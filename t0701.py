import time
import pyautogui as gui

gui.PAUSE = 1
gui.FAILSAFE = True
prefix = "Chrome http://" 
suffix = "  --new-window\n"

def step(image,action="click",btn="left",attempts=6):
    att = 1 # first time
    while (att<attempts):
        location = gui.locateCenterOnScreen(image,confidence=.7)
        if ( location == None ):
           time.sleep(.30) # retry time
           print(image,": not found at try #",att)
           att += 1 # count this
           continue
        print(image, "on screen!")
        if ( action == "move"):
            gui.moveTo(location)
        else:
            if ( action == "click"):
                gui.click(location.x,location.y, button=btn)
            else:
                pass # action none
        return att
    # estourou o numero de tentativas
    if ( location == None ):
        print("image \"", image, "\" was not found")
        if ( action != "none" ) : exit(-1)

    return 0

def reset_DLINK(router,password):
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(2)
    gui.typewrite(password)
    gui.typewrite("enter")
    gui.hotkey("F11)")
    evt.append(step("01 Tools.jpg"))
    evt.append(step("02 System.jpg"))
    evt.append(step("03 Reboot.jpg"))
    evt.append(step("04 Ok.jpg"))
    evt.append(step("05 Reboot.jpg"))
    time.sleep(1)
    gui.hotkey("alt","F4") # end session
    gui.PAUSE = save
    return evt

def reset_VV(router,password):
    save = gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    gui.hotkey("F11")
    time.sleep(2) # wait longer for router response

    if ( step("160 Autent.jpg",action="none") != 0 ):
        # ja esta esperando o login
        print("login na tela")
        gui.typewrite("admin")
        gui.hotkey("TAB")
        gui.typewrite(password)
    else:
        # se nao esta pedindo a senha clica em reiniciar
        print("sem login na tela")
        evt.append(step("100 Gerenc.jpg"))
        evt.append(step("110 Reinicia.jpg"))
        evt.append(step("160 Autent.jpg"))
        gui.typewrite("admin")
        gui.hotkey("TAB")
        gui.typewrite(password)

    evt.append(step("170 Entrar.jpg"))
    time.sleep(2) # wait for login
    # abre as opcoes
    evt.append(step("100 Gerenc.jpg"))
    evt.append(step("110 Reinicia.jpg"))
    evt.append(step("120 Reinicia.jpg"))
    time.sleep(2) # espera tela de confirmacao
    evt.append(step("130 Confirma.jpg",action="move"))
    # nao reinicia de verdade: so pra teste
    # move o ponteiro mas termina
    evt.append(step("170 Botao.jpg",action="move"))
    gui.hotkey("F11")
    gui.hotkey("alt","F4") # end session
    gui.PAUSE = save
    return evt

def abre_sessao(password,evt):
    gui.typewrite("admin")
    gui.hotkey("TAB")
    gui.typewrite(password)
    evt.append(step("170 Entrar.jpg",action="move"))
    gui.hotkey("ENTER")
    time.sleep(2) # pode demorar muito aqui
    
def reset_VIVO(router,password):
    print("roteador em", router, 
          "password: \"", password, "\"")
    save = gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    sessao = 0
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    gui.hotkey("F11")
    time.sleep(2) # wait longer for router response

    if ( gui.locateOnScreen("150 Sair.jpg",confidence=.8) != None ):
        print("Sessao aberta");
        evt.append(step("100 Gerenc.jpg"))
        evt.append(step("110 Reinicia.jpg"))
        evt.append(step("120 Reinicia.jpg"))
        evt.append(step("130 Confirma.jpg",action="move"))
    else:
        print("SEM Sessao aberta")
        if ( step("160 Autent.jpg",action="none") != 0 ):
            # ja esta esperando o login
            print("login na tela")
            abre_sessao(password,evt)
            evt.append(step("100 Gerenc.jpg"))
            evt.append(step("110 Reinicia.jpg"))
            evt.append(step("120 Reinicia.jpg"))
            evt.append(step("130 Confirma.jpg",action="move"))
        else:
            # se nao esta pedindo a senha abre algo
            print("sem login na tela")
            evt.append(step("100 Gerenc.jpg"))
            evt.append(step("110 Reinicia.jpg"))
            abre_sessao(password,evt)
            evt.append(step("120 Reinicia.jpg"))
            evt.append(step("130 Confirma.jpg",action="move"))

    time.sleep(5) # espera tela de confirmacao
    # nao reinicia de verdade: so pra teste
    # move o ponteiro mas termina
    evt.append(step("170 Botao.jpg",action="move"))
    gui.hotkey("F11")
    time.sleep(4) # espera tela de confirmacao
    gui.hotkey("alt","F4") # end session
    gui.PAUSE = save
    return evt

print(
    "First router:  Attempts ",
    reset_DLINK("192.168.15.2","2017-iso9001D\n")
    )

print(
    "Second router: Attempts ",
    reset_DLINK("192.168.15.3","2017-iso9001D\n")
    )

print(
    "reiniciando gateway: attempts ",
    reset_VIVO("192.168.15.1","231A-iso9001V")
    )

exit(0)
