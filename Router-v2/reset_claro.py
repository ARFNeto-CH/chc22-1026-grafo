from automate_v2 import Roteador, AX10, CLARO
import pyautogui as gui
import netifaces as net
gui.FAILSAFE = True

teste = CLARO("claro-parm.txt", "CLARO",
    [ 
        '000-login.jpg',
        '000-entrar.jpg',
        '000-REDES.jpg',
        '100-LAN-DHCP.jpg',
        '300-start-dhcp.jpg',
        '500-aplicar ajustes.jpg',
        '600-sair.jpg'
    ]);

if (teste.Automate(simulado=True) ):
    print("Reset OK!...")
else:
    print("Erro! Verifique...")




