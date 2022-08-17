from automate_VIVO import VIVO
from pickle import TRUE
import time
import pyautogui as gui
from automate import Roteador

gui.PAUSE = 1
gui.FAILSAFE = True
prefix = "Chrome http://" 
suffix = "  --new-window\n"

#
# Varanda
#

teste = Roteador("192.168.15.2", "2017-iso9001D", "DIR-655", [
    "01-Tools.jpg",
    "02-System.jpg",
    "03-Reboot.jpg",
    "04-Ok.jpg",
    "05-Rebooting.jpg" ] );
if (teste.Check()):
    print("Dados OK! Prosseguindo...")
    teste.Automate();
else:
    print("Faltam arquivos! Verifique...")

#
# Quarto
#

teste = Roteador("192.168.15.3", "2017-iso9001D", "DIR-635", [
    "dir-635-1-Tools.jpg",
    "dir-635-2-System.jpg",
    "dir-635-3-Reboot.jpg",
    "dir-635-4-Ok.jpg",
    "dir-635-5-Rebooting.jpg" ] );
if (teste.Check()):
    print("Dados OK! Prosseguindo...")
    teste.Automate();
else:
    print("Faltam arquivos! Verifique...")

#
# VIVO
#

def reset_VIVO():  
  vivo = VIVO("192.168.15.1", "231A-iso9001V", "VIVO", [
    "150 Sair.jpg",
    "160 Autent.jpg",
    "170 Entrar.jpg",
    "100 Gerenc.jpg",
    "110 Reinicia.jpg",
    "120 Reiniciar.jpg",
    "170 Botao.jpg"
    ])
  res = vivo.abre_sessao()
  if ( not res ):
    print("Erro ao tentar abrir sessao")
    return False
  print("Sessao aberta no roteador. Prosseguindo...")
  time.sleep(3.0)
  for i in range (3,5):
    res = vivo.Step(vivo.roteiro[i]);
    if ( res == 0):
        break
  time.sleep(0.5)
  gui.hotkey("F11")
  time.sleep(3)
  gui.hotkey("alt","F4") # end session
  return True

 
reset_VIVO() 
