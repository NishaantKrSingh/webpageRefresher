from selenium import webdriver
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.firefox.options import Options
from webdriver_manager.firefox import GeckoDriverManager
import time

def main():
    # url = input("Enter the URL: ")
    url = "localhost:3000"
    # refresh_rate = int(input("Enter the number of seconds: "))
    refresh_rate = 5

    # Setup Firefox options and initialize the driver
    options = Options()
    # Uncomment the next line if you prefer the browser to run in headless mode
    # options.add_argument("--headless")
    
    driver = webdriver.Firefox(service=Service(GeckoDriverManager().install()), options=options)
    driver.get("http://" + url)

    try:
        while True:
            time.sleep(refresh_rate)
            driver.refresh()
    except KeyboardInterrupt:
        driver.quit()
        print("Stopped refreshing and closing the browser.")

if __name__ == "__main__":
    main()
