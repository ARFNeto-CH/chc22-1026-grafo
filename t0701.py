import time
import pyautogui as gui

gui.PAUSE = 0.50
gui.FAILSAFE = True
prefix = "Chrome http://" 
suffix = "  --new-window\n"

def step(image,action="click",btn="left",attempts=5):
    att = 1 # first time
    while (att<attempts):
        location = gui.locateCenterOnScreen(image,confidence=.7)
        if ( location == None ):
           time.sleep(.30) # retry time
           att += 1 # count this
           continue
        print(image, "on screen!")
        if ( action == "move"):
            gui.moveTo(location)
        else:
            gui.click(location.x,location.y, button=btn)
        return att
    if ( location == None ):
        print("image \"", image, "\" was not found")
        exit(-1)
    return 0

def reset_DLINK(router,password):
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(2)
    gui.hotkey("F11")
    evt.append(step("00 Password.jpg"))
    gui.typewrite(password)
    gui.hotkey("enter")
    evt.append(step("01 Tools.jpg"))
    evt.append(step("02 System.jpg"))
    evt.append(step("03 Reboot.jpg"))
    evt.append(step("04 Ok.jpg"))
    time.sleep(2) # add wait for reboot msg
    evt.append(step("05 Reboot.jpg",action="move"))
    time.sleep(2) # so the user can see the reset countdown
    gui.hotkey("alt","F4") # end session
    return evt

def reset_VIVO(router,password):
    save = gui.PAUSE
    gui.PAUSE = 1.5
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(2) # wait longer for router response
    gui.hotkey("F11")
    evt.append(step("100 Gerenc.jpg"))
    evt.append(step("160 Autent.jpg"))
    gui.hotkey("TAB")
    gui.typewrite("admin")
    gui.hotkey("TAB")
    gui.typewrite(password)
    time.sleep(3) # wait for login
    # abre as opcoes
    evt.append(step("100 Gerenc.jpg"))
    evt.append(step("110 Reinicia.jpg"))
    evt.append(step("120 Reinicia.jpg"))
    time.sleep(2) # espera tela de confirmacao
    evt.append(step("130 Confirma.jpg",action="move"))
    evt.append(step("170 Botao.jpg"))
    gui.hotkey("F11")
    gui.hotkey("alt","F4") # end session
    gui.PAUSE = save
    return evt

print(
    "First router:  Attempts ",
    reset_DLINK("192.168.15.2","2017-iso9001D")
    )

print(
    "Second router: Attempts ",
    reset_DLINK("192.168.15.3","2017-iso9001D")
    )

print(
    "Reiniciando GateWay: Attempts ",
    reset_VIVO("192.168.15.1","231A-iso9001V\n")
    )

exit(0)
