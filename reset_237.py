from automate_v2 import Roteador, AX10
import pyautogui as gui
gui.FAILSAFE = True
#
# Varanda
#
teste = Roteador("192.168.15.2", "R_DIR-655", "DIR-655", [
    "01-Tools.jpg",
    "02-System.jpg",
    "03-Reboot.jpg",
    "04-Ok.jpg",
    "05-Rebooting.jpg" ] );
if (teste.Automate()):
    print("Reiniciado...")
else:
    print("Faltam arquivos! Verifique...")

#
# Quarto
#
teste = Roteador("192.168.15.3", "R_DIR-635", "DIR-635", [
    "dir-635-1-Tools.jpg",
    "dir-635-2-System.jpg",
    "dir-635-3-Reboot.jpg",
    "dir-635-4-Ok.jpg",
    "dir-635-5-Rebooting.jpg" ] );
if (teste.Automate()):
    print("Reiniciado...")
else:
    print("Faltam arquivos! Verifique...")

#
# AX10
#
teste = AX10("192.168.15.7", "R_AX10", "AX10", [
    "100 - login local.jpg",
    "110 - login box.jpg",
    "120 - System.jpg",
    "130 - Reboot.jpg",
    "140 - Reboot Button.jpg",
    "150 - Rebooting.jpg" ] );
if (teste.Automate()):
    print("Reiniciado...")
else:
    print("Faltam arquivos! Verifique...")

