from tkinter import *
from tkinter import font
import deff_demo
from tkinter import ttk
import random
import tkinter.messagebox
import datetime
import time
import tempfile, os
from tkinter import messagebox

__metaclass__ = type
class Student:
    def __init__(self,root):
        self.root = root
        blank_space = " "
        self.root.title(200 * blank_space + "GROUP 8")
        self.root.geometry("650x700+0+0")

        A = StringVar()
        B = StringVar()
        C = StringVar()
    #==============================Funtion===========================
        def iReset():
            self.txtA.delete(0,END)
            self.txtB.delete(0,END)
            self.txtC.delete(0,END)
        def addData():
            try:
                if A.get() == "" or B.get() =="" or C.get() =="":
                    tkinter.messagebox.askyesno("Enter correct data")
                else: 
                    deff_demo.addStdRec(A.get(),B.get(),C.get())
                    DisplayData()
                    messagebox.showinfo('Add',"Thêm thành công")
            except:
                messagebox.showerror('Error',"Vi pham A->B")
        def DisplayData():
            result = deff_demo.viewData()
            if len(result) != 0:
                self.studentlist.delete(*self.studentlist.get_children())
                for row in result:
                    self.studentlist.insert('',END,values=row)
        def StudentRec():
                global sd
                iReset()
                viewInfo = self.studentlist.focus()
                learnerData = self.studentlist.item(viewInfo)
                sd = learnerData['values']

                self.txtA.insert(END, sd[1])
                self.txtB.insert(END, sd[2])
                self.txtC.insert(END, sd[3])
            
                
    #==============================Frames===========================
        MainFrame = Frame(self.root, bd=10, width=1350,height=700,relief=RIDGE,bg="yellow")
        MainFrame.grid()

        TopFrame1 = Frame(MainFrame, bd=7, width=1340,height=100,relief=RIDGE)
        TopFrame1.grid(row=2,column=0,pady=8)
        TitleFrame = Frame(MainFrame, bd=7, width=1340,height=100,relief=RIDGE)
        TitleFrame.grid(row=0,column=0,)
        TopFrame3= Frame(MainFrame, bd=7, width=1340,height=100,relief=RIDGE)
        TopFrame3.grid(row=1,column=0,)

        RightFrame1 = Frame (TopFrame3,bd=5, width=320,height=400,padx=2,bg= "cadet blue",relief=RIDGE)
        RightFrame1.pack(side=RIGHT)
        RightFrame1a = Frame (RightFrame1,bd=5, width=600,height=180,padx=2,pady=4,relief=RIDGE)
        RightFrame1a.pack(side = TOP)

    #==============================Title===========================
        self.lblTitle = Label(TitleFrame, font= ('arial',30,'bold'),text="GROUP 3",bd=7)
        self.lblTitle.grid(row = 0,column=0,padx=132)
        self.lblTitle = Label(TitleFrame, font= ('arial',30,'bold'),text="R(A,B,C)     A->B",bd=7)
        self.lblTitle.grid(row = 1,column=0,padx=50)

    #==============================WIDGET===========================
        self.lblA = Label(TopFrame1, font= ('arial',10,'bold'),text="A",bd=7,anchor= 'w',justify= LEFT)
        self.lblA.grid(row = 0,column=0,sticky=W,padx=5)
        self.txtA = Entry(TopFrame1, font= ('arial',10,'bold'),bd=5,width=40,justify= 'left',textvariable=A)
        self.txtA.grid(row = 0,column=1)

        self.lblB = Label(TopFrame1, font= ('arial',10,'bold'),text="B",bd=7,anchor= 'w',justify= LEFT)
        self.lblB.grid(row = 1,column=0,sticky=W,padx=5)
        self.txtB = Entry(TopFrame1, font= ('arial',10,'bold'),bd=5,width=40,justify= 'left',textvariable=B)
        self.txtB.grid(row = 1,column=1)

        self.lblC = Label(TopFrame1, font= ('arial',10,'bold'),text="C",bd=7,anchor= 'w',justify= LEFT)
        self.lblC.grid(row = 2,column=0,sticky=W,padx=5)
        self.txtC = Entry(TopFrame1, font= ('arial',10,'bold'),bd=5,width=40,justify= 'left',textvariable=C)
        self.txtC.grid(row = 2,column=1)

    #==============================TreeView===========================
        scroll_x = Scrollbar (RightFrame1a,orient= HORIZONTAL)
        scroll_y = Scrollbar (RightFrame1a,orient= VERTICAL)

        self.studentlist = ttk.Treeview(RightFrame1a,height=12,columns=("A","B","C"),xscrollcommand=scroll_x.set,yscrollcommand=scroll_y.set)
        scroll_x.pack(side=BOTTOM,fill=X)
        scroll_y.pack(side=BOTTOM,fill=Y)

        self.studentlist.heading("A",text="A")
        self.studentlist.heading("B",text="B")
        self.studentlist.heading("C",text="C")

        self.studentlist['show']='headings'

        self.studentlist.column("A",width=100)
        self.studentlist.column("B",width=100)
        self.studentlist.column("C",width=100)

        self.studentlist.pack(fill=BOTH,expand=1)
        self.studentlist.bind("<ButtonRelease-1>",StudentRec)
        DisplayData()

    #==============================Button===========================
        self.btnAddNew = Button(TopFrame1,pady=1,bd=4,font=('arial',10,'bold'),text="Add new",padx=24,
                                width=12,height=2,command=addData).grid(row=3,column=0,padx=1)
        self.btnDisplay = Button(TopFrame1,pady=1,bd=4,font=('arial',10,'bold'),text="Display",padx=24,
                                width=12,height=2,command=DisplayData).grid(row=3,column=1,padx=1)
        self.btnUpdate = Button(TopFrame1,pady=1,bd=4,font=('arial',10,'bold'),text="Update",padx=24,
                                width=12,height=2).grid(row=3,column=2,padx=1)



if __name__== '__main__':
    root = Tk()
    application = Student(root)
    root.mainloop()