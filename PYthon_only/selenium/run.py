from booking.booking import Booking
import time

with Booking() as bot:
    bot.land_first_page()
    time.sleep(10)
    bot.change_currentcy(currency='en')
    time.sleep(10)
    print('Exiting...')