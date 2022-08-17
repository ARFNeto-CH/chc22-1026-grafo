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

  def Step(self,image,action="click",\
    btn="left",    attempts=3,     confidence=.7):
    att = 1 # first time
    while (att<attempts):
        location = gui.locateCenterOnScreen(image, confidence=.7 )
        if ( location == None ):
           time.sleep(1.) # retry time
           print(image,": not found. Try #",att)
           att += 1 # count this
           continue
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
        img = self.folder + '\\' + item
        res = self.Step(img)
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


          
 


