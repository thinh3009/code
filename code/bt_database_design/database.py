from tkinter import *
import time
import random
import datetime
from tkinter import ttk
import sqlite3
from tkinter import messagebox
from typing import Match
#label: hien text hoac hinh anh ko dc chinh sua
#entry: cho phep nhap lieu thong tin
conn = sqlite3.connect("QLSV.db")
c = conn.cursor()
options = [' ']
sql="SELECT * FROM Class"
c.execute(sql)
ids=c.fetchall()
for i in ids:
    options.append(str(i[0])+" - "+i[1]+" - "+i[2])
 
 
def update(rows):
    for i in rows:
        tableView.insert('','end',values=i)   


def selected():
    tableView.delete(*tableView.get_children())
    option= ClassOption.get()
    cid = option.split(" - ")[0]
    query ="SELECT * FROM Student WHERE ClassID = '" + str(cid) + "'"
    c.execute(query)
    rows = c.fetchall()
    update(rows)
    
def submit():
    #box message ask
    iExit = messagebox.askquestion("Ask question","Bạn có muốn thêm sinh viên này vào không?")
    if iExit == 'yes':
        if studentid_insert.get() == '' or studentname_insert.get() == '' or classid_insert.get() == '':
            messagebox.showerror('Error',"Bạn chưa nhập thông tin sinh viên!!")
        else:
            try:
                conn = sqlite3.connect('QLSV.db')
                #create cursor
                c= conn.cursor()

                # insert into Table
                c.execute("""INSERT INTO Student 
                            VALUES
                                (:StudentID, :StudentName, :ClassID)
                        """,
                            {
                                'StudentID':studentid_insert.get(),
                                'StudentName':studentname_insert.get(),
                                'ClassID':classid_insert.get()
                            }
                        )
        
                #commit changes
                conn.commit()
                #close connection
                conn.close()

                response=messagebox.showinfo("INSERT","Thêm thành công")
                Label(root,text=response).pack()
            except:
                response=messagebox.showerror("INSERT","Thêm không thành công")

    studentid_insert.delete(0,END)
    studentname_insert.delete(0,END)
    classid_insert.delete(0,END)

    insert.destroy()

#bang insert
def insert():
    global insert
    insert = Tk()
    insert.title("Insert Student!")
    insert.geometry("400x150")
    insert.config(bg='#99FF99')
    #goi lai ham trong bang insert
    global studentid_insert
    global studentname_insert
    global classid_insert
    global math 

    math = "insert"

    studentid_insert = Entry(insert,width=30)
    studentid_insert.grid(row= 0, column=1,padx=20,pady=(10,0))
    studentname_insert = Entry(insert,width=30)
    studentname_insert.grid(row= 1, column=1)
    classid_insert = Entry(insert,width=30)
    classid_insert.grid(row= 2, column=1)

    studentid_insert_label = Label(insert,text="StudentID",fg="#000022")
    studentid_insert_label.grid(row=0, column=0,pady=(10,0))
    studentname_insert_label = Label(insert,text="StudentName")
    studentname_insert_label.grid(row=1, column=0)   
    classid_insert_label = Label(insert,text="ClassID")
    classid_insert_label.grid(row=2, column=0)

    insert_btn = Button(insert, text="Add to student",fg="#363636",bg="#FFFF66",command=submit) 
    insert_btn.grid(row = 6,column=0,columnspan=2,padx=50,pady=30,ipadx=100)
#nut xoa
def delete():
    conn = sqlite3.connect('QLSV.db')
    c= conn.cursor()

    c.execute("DELETE from Student WHERE StudentID = "+"'"+ studentid_delete.get()+"'") 
    studentid_delete.delete(0,END)

    conn.commit()
    conn.close()
    popup()
    deletee.destroy()
#bang xoa
def delete_wrapper():
    global deletee 

    deletee = Tk()
    deletee.title("Delete Student !!")
    deletee.geometry("300x100")
    deletee.config(bg="#99FF99")

    global studentid_delete
    global math 

    math = "delete"

    studentid_delete = Entry(deletee,width=30)
    studentid_delete.grid(row= 0, column=1,padx=20,pady=(10,0))

    studentid_delete_label = Label(deletee,text="StudentID")
    studentid_delete_label.grid(row=0, column=0,pady=(10,0))

    insert_btn = Button(deletee, text="Delete to student",fg="#363636",bg="#FFD700",command=delete) 
    insert_btn.grid(row = 6,column=0,columnspan=2,padx=10,pady=10,ipadx=100)

def edit3():
    conn = sqlite3.connect('QLSV.db')
    c= conn.cursor()

    record_id = studentid_input.get()

    c.execute("""UPDATE Student SET
                StudentID = :studentid,
                StudentName = :studentname,
                ClassID = :classid

                WHERE StudentID = """+"'"+ record_id +"'",
                {
                    'studentid': studentid_edit.get(),
                    'studentname': studentname_edit.get(),
                    'classid': classid_edit.get(),

                }
                )


    conn.commit()
    conn.close()
    popup()
    editor.destroy()

def edit2():
    conn = sqlite3.connect('QLSV.db')
    c= conn.cursor()

    record_id = studentid_input.get()

    c.execute("SELECT *  FROM Student WHERE StudentID = "+"'"+ record_id +"'") 
    records=c.fetchall()

    global studentid_edit
    global studentname_edit
    global classid_edit

    studentid_edit = Entry(editor,width=30)
    studentid_edit.grid(row= 4, column=1,padx=20,pady=(10,0))
    studentname_edit = Entry(editor,width=30)
    studentname_edit.grid(row= 5, column=1)
    classid_edit = Entry(editor,width=30)
    classid_edit.grid(row= 6, column=1)

    studentid_edit_label = Label(editor,text="StudentID")
    studentid_edit_label.grid(row=4, column=0,pady=(10,0))
    studentname_edit_label = Label(editor,text="StudentName")
    studentname_edit_label.grid(row=5, column=0)   
    classid_edit_label = Label(editor,text="ClassID")
    classid_edit_label.grid(row=6, column=0)

    for record in records:
        studentid_edit.insert(0,record[0])
        studentname_edit.insert(0,record[1])
        classid_edit.insert(0,record[2])

    edit_btn = Button(editor,text="Save",fg="#363636",bg="#FFD700",command=edit3 )
    edit_btn.grid(row=7,column=0,columnspan=2,pady=10,padx=10,ipadx=143)


def edit1():    
    global editor 
    editor = Tk()
    editor.title("Update!")
    editor.geometry("400x200")
    editor.config(bg="#99FF99")

    global studentid_input
    global math 

    math = "edit"
    
    studentid_input = Entry(editor,width=30)
    studentid_input.grid(row= 0, column=1,padx=20,pady=(10,0))
    studentid_input_label = Label(editor,text="studentid to edit:")
    studentid_input_label.grid(row=0, column=0,pady=(10,0))
    edit_input_btn = Button(editor,text="Update to student ",fg="#363636",bg="#FFD700",command = edit2)
    edit_input_btn.grid(row=3,column=0,columnspan=2,pady=10,padx=10,ipadx=143)

def quit():
    root.destroy()

def popup():
    if math == "insert":
        response=messagebox.showinfo("INSERT","Thêm thành công")
        Label(root,text=response).pack()
    if math == "delete":
        response=messagebox.showinfo("DELETE","Xóa thành công")
        Label(root,text=response).pack()
    if math == "edit":
        response=messagebox.showinfo("UPDATE","Sửa thành công")
        Label(root,text=response).pack()

#=====================
root = Tk()
root.title('student management')
root.config(bg='#FFFFCC')
root.geometry('1174x850')
root.iconbitmap('team_group_people_management_business_work_employees_icon_153126.ico')
root.resizable(False,False)
#=======================Tao ngay gio
def tick():
    time_string = time.strftime("%H:%M:%S")
    date_string = time.strftime("%d/%m/%Y")
    clock.config(text=' '+date_string+'\ngroup database 8\n '+time_string)
    clock.after(200,tick)
#Tao intro
colors=['red','green','blue','yellow','pink','red2','gold2','gray','brown']
def introcolor():
    fg= random.choice(colors)
    sliderLaber.config(fg=fg)
    sliderLaber.after(20,introcolor)

def IntroLabelTick():
    global count,text
    if(count>=len(aa)):
        count =-1
        text=''
        sliderLaber.config(text=text)
    else:
        text = text + aa[count]
        sliderLaber.config(text=text)
        count +=1
    sliderLaber.after(100,IntroLabelTick)

 
#Tao Khung nhap su lieu
DataEntryFrame = Frame(root,bg='yellow',relief=GROOVE,borderwidth=5)
DataEntryFrame.place(x=10,y=80,width=400,height=800)
#======================Frame intro
#99FFFF: ma mau sac
#padx: kich thuoc nut ngang
#pady: kich thuoc nut doc
#bg:mau nen
#fg: mau vien
#command: goi ham
ttitle=Label(DataEntryFrame,text='STUDENT',font=('Times New Roman', 50 , 'italic bold'),bg='#99FFFF',relief=RAISED,fg='#CC9900')
ttitle.grid(row=0,columnspan=1,padx=30,pady=20)

insert_btn = Button(DataEntryFrame,text="Insert",fg="red",bg="#99FFFF",width=10,relief=RAISED,font=('Times New Roman',20),command =insert) 
insert_btn.grid(row=1,columnspan=2,padx=120,pady=40)

delete_btn = Button(DataEntryFrame,text="Delete",fg="red",bg="#99FFFF",width=10,font=('Times New Roman',20),command = delete_wrapper) 
delete_btn.grid(row=2,columnspan=2,padx=120,pady=40)

edit_btn = Button(DataEntryFrame,text="Update",fg="red",bg="#99FFFF",width=10,font=('Times New Roman',20),command = edit1) 
edit_btn.grid(row=3,columnspan=2,padx=120,pady=40)

quit_btn = Button(DataEntryFrame,text="Quit  ",fg="red",bg="#99FFFF",width=10,font=('Times New Roman',20),command=quit) 
quit_btn.grid(row=4,columnspan=2,padx=120,pady=40)


ShowDataFrame = Frame(root,bg='#999966',relief=GROOVE,borderwidth=5)
ShowDataFrame.place(x=480,y=80,width=700,height=150)

ShowDataFrame1 = Frame(root,bg='#CC99CC',relief=GROOVE,borderwidth=5)
ShowDataFrame1.place(x=480,y=230,width=700,height=800)

tableView= ttk.Treeview(ShowDataFrame1, columns=(1,2,3), show="headings", height="20")
tableView.pack(padx=10,pady=20)
tableView.heading(1, text="StudentID")
tableView.heading(2, text="StudentName")
tableView.heading(3, text="ClassID")

#====================================
selectButton = Button(ShowDataFrame,font=('arial', 15, 'bold'),text="Select Class",bg='#99FF66',fg='#000000', command=selected)
selectButton.grid(row=0,column=1,padx=0,pady=0)
ClassOption = ttk.Combobox(ShowDataFrame,font=('Times New Roman', 7, 'bold'), textvariable='opts', width=80)
ClassOption['values'] = options
ClassOption.grid(row=0,column=0,padx=10,pady=10)
ClassOption.current(0)
#===========================

# Tao Thanh tieu de
aa=' WELCOME TO STUDENT MANAGEMENT SYSTEM '
count =0
text =''
#====================================
sliderLaber = Label(root,text=aa,font=('Times New Roman',25,'italic bold'))
sliderLaber.place(x=210,y=0)
IntroLabelTick()
introcolor()

# Clock
clock= Label(root,font=('times',14,' bold'),relief=RIDGE,borderwidth=4,bg='#FF9999')
clock.place(x=1000,y=0)
tick()
#===============================

root.mainloop()