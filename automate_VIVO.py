#
# RESET VIVO
# 
from pickle import TRUE
import time
import pyautogui as gui

class VIVO:

  def __init__( self, endereco, senha, pasta, roteiro ):
    self.address = endereco
    self.password = senha 
    self.folder = pasta
    self.roteiro = roteiro

  def Step(self,image,action="click",\
    btn="left",    attempts=3,     confidence=.7):
    print("VIVO: image is", image)
    att = 1 # first time
    while (att<attempts):
        location = gui.locateCenterOnScreen(image, confidence=.8 )
        if ( location == None ):
           print(image,": not found. Try #",att)
           time.sleep(1.) # retry time
           att += 1 # count this
           continue
        print(image,": found")
        if ( action == "move"):
            gui.moveTo(location)
        else:
            if ( action == "click"):
                gui.click(location.x,location.y, button=btn)
            else:
                pass # action none
        break
    # estourou o numero de tentativas
    if ( location == None ):
        return 0
    return att


  def abre_sessao(self):
    print("Reiniciando equipamento em",self.address)
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(4.0)
    gui.hotkey("F11")
    print("Browser ok")
    # esta online?
    image = self.roteiro[0]
    res = self.Step(image,action="none")
    # retorna 1 se ja esta online
    if ( res == 1):
        return True
    # esta na tela em que pede a senha?
    image = self.roteiro[1]
    res = self.Step(image)
    # esta na tela de login
    if ( res == 1):
        gui.hotkey("TAB")
        gui.typewrite("admin")
        gui.hotkey("TAB")
        gui.typewrite(self.password)
        image = self.roteiro[2]
        res = self.Step(image)
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
