import time
import pickle
import os
import random

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from webdriver_manager.microsoft import EdgeChromiumDriverManager
from selenium.webdriver.edge.service import Service
from selenium.webdriver.edge.options import Options

COOKIE_FILE = "fb_cookies.pkl"

# danh sách người nhận
receivers = [
    "https://www.facebook.com/messages/t/USERNAME1",
    "https://www.facebook.com/messages/t/USERNAME2"
]

message = "Chào bạn! Đây là tin nhắn tự động từ Python."

image_path = r"C:\image\test.jpg"


def start_driver():

    edge_options = Options()
    edge_options.add_argument("--start-maximized")

    driver = webdriver.Edge(
        service=Service(EdgeChromiumDriverManager().install()),
        options=edge_options
    )

    return driver


def save_cookies(driver):
    pickle.dump(driver.get_cookies(), open(COOKIE_FILE, "wb"))


def load_cookies(driver):
    cookies = pickle.load(open(COOKIE_FILE, "rb"))
    for cookie in cookies:
        driver.add_cookie(cookie)


def login_if_needed(driver):

    driver.get("https://www.facebook.com/")

    if os.path.exists(COOKIE_FILE):

        load_cookies(driver)
        driver.refresh()
        time.sleep(5)

    else:
        print("Hãy đăng nhập Facebook trong 60 giây...")
        time.sleep(60)
        save_cookies(driver)


def send_message(driver, url):

    driver.get(url)

    time.sleep(8)

    message_box = driver.find_element(By.XPATH, "//div[@aria-label='Message']")

    message_box.click()
    message_box.send_keys(message)
    message_box.send_keys(Keys.ENTER)

    time.sleep(random.randint(3,6))

    upload = driver.find_element(By.XPATH, "//input[@type='file']")
    upload.send_keys(image_path)

    time.sleep(5)

    message_box.send_keys(Keys.ENTER)

    print("Đã gửi tới:", url)

    time.sleep(random.randint(5,10))


def main():

    driver = start_driver()

    login_if_needed(driver)

    for r in receivers:
        send_message(driver, r)

    time.sleep(10)
    driver.quit()


if __name__ == "__main__":
    main()