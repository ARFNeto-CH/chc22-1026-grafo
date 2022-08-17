from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome() # driver no diretorio corrente
title=driver.title
driver.get("http://192.168.15.2")
# passwd
passwd_box = driver.find_element(by=By.NAME,value="old_password")\
    .send_keys("2017-iso9001D")
# login
driver.find_element(by=By.NAME,value="Login").click()
driver.implicitly_wait(0.5)
# TOOLS
driver.find_element(by=By.ID,value="Tools_topnav")\
    .click()
# SYSTEM
driver.find_element(By.XPATH,value='//*[@id="Tools_subnav"]/li[5]/div/a')\
    .click()
# Reboot
#driver.find_element(by=By.ID,value="reboot")\
#    .click()

lista = driver.find_elements(By.TAG_NAME,value='a')
print('lista',lista)

for l in lista:
    print( l.get_attribute("href"),"=",l.text )

time.sleep(3)
driver.refresh()
time.sleep(3)
driver.save_screenshot("roteador1.png")
driver.quit()

#//*[@id="Tools_subnav"]/li[5]/div/a