from selenium import webdriver
import time

driver = webdriver.Chrome()
driver.get("https://www.google.co.in")
time.sleep(1)
driver.refresh()
time.sleep(1)
driver.save_screenshot("google.png")
driver.quit()
