# import webdriver 
from selenium import webdriver 

# create webdriver object 
driver = webdriver.Chrome() 

# get website
driver.get("https://www.google.com/") 

# get element 
driver.find_element_by_link_text("Images").click()

driver.find_element_by_name("q").send_keys('apple macbook')

driver.find_element_by_class_name("Tg7LZd").click()



