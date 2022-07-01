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
        location = gui.locateCenterOnScreen(image,confidence=.7)
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
    evt.append(step("05 Reboot.jpg",action="move"))
    time.sleep(2) # so the user can see the reset countdown
    gui.hotkey("alt","F4") # end session
    return evt

def reset_VIVO(router,password):
    gui.PAUSE = 0.25
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    evt = []
    arg = prefix+router+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(8) # wait longer for browser
    #gui.hotkey("F11")
    #
    # exit if user is already logged on
    #
    location = gui.locateOnScreen("140 Logged.jpg",confidence=.7) 
    if (location != None ):
        print("User is online")
        return evt
    print("No User")
    return 0
    evt.append(step("100 Gerenc.jpg",action="move"))
    gui.hotkey("enter")
    time.sleep(1)
    gui.typewrite("admin")
    gui.hotkey("TAB")
    gui.typewrite(password)
    evt.append(step("110 Reinicia.jpg"))
    time.sleep(1)
    evt.append(step("120 Reinicia.jpg"))
    evt.append(step("130 Confirma.jpg"))
    gui.hotkey("F11")
    time.sleep(4)
    gui.hotkey("alt","F4") # end session
    return evt

#print(
#    "First router:  Attempts ",
#    reset_DLINK("192.168.15.2","2017-iso9001D")
#    )

#print(
#    "Second router: Attempts ",
#    reset_DLINK("192.168.15.3","2017-iso9001D")
#    )

res = reset_VIVO("192.168.15.1","231A-iso9001V\n")
print(res)
exit(0)
