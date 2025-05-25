from types import TracebackType
from typing import Type
import booking.constants as const
import os
from selenium import webdriver
import time
from selenium.webdriver.common.by import By  
class Booking(webdriver.Edge):
    def __init__(self,driver_path=r'C:\Windows\System32',teardown=False):
        self.driver_path=driver_path
        self.teardown=teardown
        os.environ['PATH']+=self.driver_path
        super(Booking,self).__init__()
        self.implicitly_wait(15)
        self.maximize_window()
    #phuong thuc tat brower
    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.teardown:
            self.quit()
    def land_first_page(self):
        self.get(const.BASE_URL)
    def change_currentcy(self,currency=None):
        currency_element=self.find_element(By.CSS_SELECTOR,"div[id='topActionSwitchLang']")
        time.sleep(10)
        currency_element.click()
        selected_language=self.find_element(By.CSS_SELECTOR,
                                            f'div.lzd-switch-item*=data-lang="{currency}"')
        time.sleep(5)
        selected_language.click()