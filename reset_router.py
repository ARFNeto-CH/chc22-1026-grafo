import time
import pyautogui as gui

gui.PAUSE = 0.1
gui.FAILSAFE = True
prefix = "Chrome http://" 
suffix = "  --new-window\n"

router = "192.168.15.3"
password="2017-iso9001D"

def step(image,action="click",btn="left",attempts=5):
    att = 1 # first time
    while (att<attempts):
        location = gui.locateCenterOnScreen(image,confidence=.6)
        if ( location == None ):
           time.sleep(.25) # retry time
           att += 1 # count this
           continue
        if ( action == "move"):
            gui.moveTo(location)
        else:
            gui.click(location.x,location.y, button=btn)
        return att
    if ( location == None ):
        print("image \"", image, "\" was not found")
        exit(-1)
    return 0

evt = []
arg = prefix+router+suffix
gui.hotkey("win","r")
gui.typewrite(arg)
time.sleep(2)
gui.hotkey("F11")
evt.append(step("00password.jpg"))
gui.typewrite(password)
gui.hotkey("enter")
evt.append(step("01tools.jpg"))
evt.append(step("02system.jpg"))
evt.append(step("03reboot.jpg"))
evt.append(step("04ok.jpg"))
evt.append(step("05reboot.jpg",action="move"))
time.sleep(2) # so the user can see the reset countdown
gui.hotkey("alt","F4") # end session
print(evt)
exit(0)
