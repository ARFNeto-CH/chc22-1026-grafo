from automate_v2 import Roteador, VIVO
import time
import pyautogui as gui

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
vivo = VIVO("192.168.15.1", "231A-iso9001V", "VIVO", [
    "150 Sair.jpg",
    "160 Autent.jpg",
    "170 Entrar.jpg",
    "100 Gerenc.jpg",
    "110 Reinicia.jpg",
    "120 Reiniciar.jpg",
    "170 Botao.jpg"
    ])
if (vivo.Check()):
    print("VIVO: Dados OK! Prosseguindo...")
    vivo.reset_VIVO()
else:
    print("Faltam arquivos! Verifique...")

