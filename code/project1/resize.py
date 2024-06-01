from tkinter import *
from PIL import Image, ImageTk

ws = Tk()
ws.title('PythonGuides')
ws.geometry('500x400')
ws.config(bg='#4a7a8c')


def resize_func():
    image = Image.open("C:/Users/ASUS TUF/Desktop/project1/sreach.png")
    w = int(width.get())
    h = int(height.get())
    resize_img = image.resize((w, h))
    img = ImageTk.PhotoImage(resize_img)
    disp_img.config(image=img)
    disp_img.image = img


frame = Frame(ws)
frame.pack()

Label(
    frame,
    text='Width'
    ).pack(side=LEFT)
width = Entry(frame, width=10)
width.insert(END, 300)
width.pack(side=LEFT)

Label(
    frame,
    text='Height'
    ).pack(side=LEFT)

height = Entry(frame, width=10)
height.insert(END, 350)
height.pack(side=LEFT)

resize_btn = Button(
    frame,
    text='Resize',
    command=resize_func
)
resize_btn.pack(side=LEFT)

disp_img = Label()
disp_img.pack(pady=20)


ws.mainloop()