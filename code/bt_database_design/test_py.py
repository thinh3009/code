import sqlite3
from tkinter import *
from tkinter import messagebox
#connect database
conn=sqlite3.connect('FD.db')

#create a cursor(con tro)
c = conn.cursor()
#create table
c.execute("""CREATE TRIGGER T1 BEFORE INSERT ON R
             BEGIN
                SELECT
                CASE
                WHEN EXISTS (SELECT *
                             FROM R
                             WHERE R.A = NEW.A AND R.B <> NEW.B) THEN
                    RAISE(ABORT, 'VP A-> B')
                END;
            END;
        """)
root = Tk()
root.title('Python Guides')
root.geometry('300x200')
root.config(bg='#5FB691')


#=========================
root.mainloop()