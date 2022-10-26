from automate_v2 import VIVO
import pyautogui as gui
gui.FAILSAFE = True
#
# VIVO
#
vivo = VIVO("192.168.15.1", "R_VIVO", "VIVO", [
    "150 Sair.jpg",
    "160 Autent.jpg",
    "170 Entrar.jpg",
    "100 Gerenc.jpg",
    "110 Reinicia.jpg",
    "120 Reiniciar.jpg",
    "170 Botao.jpg"
    ])
if (vivo.Automate(simulado=True)):
    print("Reset OK!...")
else:
    print("Erro! Verifique...")

