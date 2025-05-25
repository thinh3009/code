from tkinter import *
from tkinter import messagebox
def msgbox1():
    messagebox.showinfo("<3","anh cum yeu em nham nham!!")
def msgbox2():
    messagebox.showwarning("dm","chia tay di!!")
def msgbox3():
    messagebox.showwarning("dm","ditmemay!!")

root=Tk()
root.title("ung dung tinh iu!!!")
root.resizable(height=True,width=True)
root.minsize(height=200,width=300)
# ima=PhotoImage(file='PYthon_only/tim.png')
# Label(root,image=ima).pack()
Label(root,text="EM CO YEU ANH KHONG!!",fg="hotpink").pack()

Button(root,text="CO YEU VAI LON!!",fg='hotpink',command=msgbox1).pack(side=LEFT)
Button(root,text="DEO CUT!!",fg='darkred',command=msgbox2).pack(side=RIGHT)
Button(root,text="thoat nha",fg='tomato',command=root.quit).pack(side=BOTTOM)
Button(root,text="KHUM BIT",fg='tomato',command=msgbox3).pack(side=BOTTOM)


root.mainloop()
'''-------------------------------------------------------------------------------------'''

'''--------------------------------------------------------------------------------------'''
# from tkinter import *
# import random
# root = Tk()
# def Click():
#     a = random.randint(30,230)
#     b = random.randint(120,210)
#     btn.place(x=a,y=b)
#     root.geometry('300x250')
# t = Label(root, text="Close The Window !!!",font=("Arial",15))
# t.place(x=70,y=90)
# btn = Button(root, text = 'YES',command = Click)
# btn.place(x=120,y=170)
# def disable_event():
#     pass
# root.protocol("WM_DELETE_WINDOW", disable_event)
# root.mainloop()