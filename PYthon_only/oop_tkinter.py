from tkinter import *

class App(Tk):
    def __init__(self):
        super().__init__()
        #title,icon,size
        self.title("App dịch tiếng trung quốc")
        self.iconbitmap(r'C:\Users\Asus\Desktop\thiscode\PYthon_only\project2\icon_img\icon31.ico')
        self.geometry("700x450")

        #create status variable
        self.status=True
        #create widget
        self.my_label=Label(self,text="hello world!",font=("Times",42))
        self.my_label.pack(pady=20)

        self.my_button=Button(self,text="change text",command=self.change)
        self.my_button.pack(pady=20)
        #create a frame outside this function
        My_frame(self)
    def change(self):
        if self.status==True:
            self.my_label.config(text="goodbye world!!!")
            self.status=False
        else:
            self.my_label.config(text="hello world")
            self.status=True
        
class My_frame(Frame):
    def __init__(self,parent):
        super().__init__(parent)

        #put this scker on the screen
        self.pack(pady=20)
        #create button
        self.my_button1=Button(self,text="change",command=parent.change)#ke thua tu lop cha qua lop con
        self.my_button2=Button(self,text="change",command=parent.change)
        self.my_button3=Button(self,text="change",command=parent.change) 

        self.my_button1.grid(row=0,column=1,padx=10)
        self.my_button2.grid(row=1,column=1,padx=10)
        self.my_button3.grid(row=2,column=1,padx=10)



if __name__=="__main__":
    app=App()
    app.mainloop()
