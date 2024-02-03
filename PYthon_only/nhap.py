from tkinter import  *
#.grid : thiet ke theo dang luoi
#.pack: lam trong 1 o
def tiepA():
    stringhsA.set("")
    stringhsB.set("")
    stringKQ.set("")
def giaiA():
    a=float(stringhsA.get())
    b=float(stringhsB.get())
    if a==0 and b==0:
        stringKQ.set("vo so nghiem")
    elif a==0 and b!=0:
        stringKQ.set("vo nghiem")
    else:
        stringKQ.set("x="+str((-b/a)))
root=Tk()
stringhsA=StringVar()
stringhsB=StringVar()
stringKQ=StringVar()
root.title("giai Ptrinh bac 1")
root.resizable(height=True,width=True)
root.minsize(height=200,width=400)
Label(root,text="ptrinh bac 1",fg="red",font=("tahoma",16),justify=CENTER).grid(row=0,columnspan=2)#giao dien chu
Label(root,text="he so a: ").grid(row=1,column=0)
Entry(root,width=30,textvariable=stringhsA).grid(row=1,column=1)

Label(root,text="he so b: ").grid(row=2,column=0)
Entry(root,width=30,textvariable=stringhsB).grid(row=2,column=1)

frambutton=Frame()
Button(frambutton,text="giai",command=giaiA).pack(side=LEFT)
Button(frambutton,text="tiep",command=tiepA).pack(side=LEFT)
Button(frambutton,text="thoat",command=root.quit).pack(side=LEFT)
frambutton.grid(row=3,columnspan=2)
Label(root,text="ket qua: ").grid(row=4,column=0)
Entry(root,width=30,textvariable=stringKQ).grid(row=4,column=1)
root.mainloop()