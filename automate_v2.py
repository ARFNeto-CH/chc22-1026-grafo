import time
import pyautogui as gui
from os import path

class Roteador:

  def __init__( self, endereco, senha, pasta, roteiro ):
    self.address = endereco
    self.password = senha 
    self.folder = pasta
    self.roteiro = roteiro

  def Show(self):
    print("Roteador:", self.address )
    print("   senha: ", self.password )
    print("   pasta: ", self.folder )
    print("Roteiro tem ", len(self.roteiro), "passos:")
    for item in self.roteiro:
        print("    ", item)

  def Check(self):
    ok = 0
    for item in self.roteiro:
        if ( path.exists(self.folder + '/' + item)):
            ok += 1
    return ok == len(self.roteiro)

  def Step(self,img,action="click",\
    btn="left",    attempts=3,     confidence=.8):
    att = 1 # first time
    image = self.folder + '\\' + img
    while (att<attempts):
        location = gui.locateCenterOnScreen(image, confidence=.8 )
        if ( location == None ):
           time.sleep(1.2) # retry time
           att += 1 # count this
           continue
        print(image," found!")
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
        return 0
    return att
  
  def Automate(self):
    print("Reiniciando equipamento em",self.address)
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(1.)
    gui.hotkey("F11")
    gui.typewrite(self.password)
    gui.hotkey("ENTER")
    time.sleep(1.)
    # session is open
    steps = len(self.roteiro)
    done = 0
    for item in self.roteiro:
        res = self.Step(item)
        time.sleep(1.3)
        if ( res != 1 ):
            break
        done +=1
    if ( done == steps ):
        print("RESET OK!")
    else:
        print("Erro no RESET!")
    time.sleep(0.5)
    gui.hotkey("alt","F4") # end session


#
# RESET VIVO
# 
class VIVO(Roteador):

#   def __init__( self, endereco, senha, pasta, roteiro ):
#     Roteador.address = endereco
#     Roteador.password = senha 
#     self.folder = pasta
#     self.roteiro = roteiro
  def abre_sessao(self):
    print("Reiniciando equipamento em",self.address)
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(5.0)
    gui.hotkey("F11")
    print("Browser ok")
    # esta online?
    res = self.Step(self.roteiro[0],action="none")
    # retorna 1 se ja esta online
    if ( res == 1):
        return True
    # esta na tela em que pede a senha?
    res = self.Step(self.roteiro[1])
    # esta na tela de login
    if ( res == 1):
        gui.hotkey("TAB")
        gui.typewrite("admin")
        gui.hotkey("TAB")
        gui.typewrite(self.password)
        res = self.Step(self.roteiro[2])
        gui.PAUSE = save
        if ( res == 0):
            return False
        return True
    # nao esta na tela de login entao 
    # precisa abrir o prompt de login
    res = self.Step(self.roteiro[3])
    if ( res == 0 ):
        return False # deu pau
    res = self.Step(self.roteiro[4])
    if ( res == 0 ):
        return False # deu pau
    # ok deve estar de volta na tela de login    
    res = self.Step(self.roteiro[1])
    # esta na tela de login
    # ok agora deve ter a tela
    gui.hotkey("TAB")
    gui.typewrite("admin")
    gui.hotkey("TAB")
    gui.typewrite(self.password)
    res = self.Step(self.roteiro[2])
    if ( res == 0 ):
        return False 
    gui.PAUSE = save
    return True
     
  def reset_VIVO(self):  
    res = self.abre_sessao()
    print("Sessao aberta: ", res)
    if ( not res ):
        print("Erro ao tentar abrir sessao")
        return False

    print("Sessao aberta no roteador. Prosseguindo em 6s...")
    time.sleep(6.0)

    for i in range (3,5):
        res = self.Step(self.roteiro[i]);
        if ( res == 0):
            break
    time.sleep(0.5)
    res = self.Step(self.roteiro[5],action="none");
    if ( res == 1):
        print("Posicionado no RESET")
    else:
        print("Nao encontrou botao RESET")
    gui.hotkey("F11")
    time.sleep(3)
    gui.hotkey("alt","F4") # end session
    return True



