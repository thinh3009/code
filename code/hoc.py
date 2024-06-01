#list
#tao list rong
emtyList = []
#tao doituong list
emtyList2= list()
print(emtyList)
print(emtyList2)
#tao list co du lieu
color=["red", 'green',"orange"]
print(color)
#tao dsach lop
studenList=["ngan", "vy", "nam"]
#list co thu tu vi tri cac phan tu duoc danh giau tu trai sang phai
print(studenList[2])
print(studenList[1:3])
#them phan tu vaof list
studenList.append("thinh")
print(studenList)
#chen ptu
studenList.insert(2,"hung")
print(studenList)
#so luong phan tu co trong list
print(len(studenList))
#dem so luong phan tu co trong list
print("dem so hoc sinh: ",studenList.count("thinh"))
#xoa hoc sinh ra khoi list
studenList.remove("nam")
print(studenList)
#dao nguoc list
studenList.reverse()
print(studenList)
#sap xep lai list
studenList.sort()
print(studenList)
#sap xep nguoc
studenList.sort(reverse=True)
print(studenList)

#vong lap
n=10
for i in range(n):
    print(i)
#tinh tong tu 0->n
'''n=int(input("nhap n: "))
tong=0
for i in range(n+1):
    tong+=i
print("tong = ",tong)'''
#vong lap for co buoc tang
for i in range(0, 10, 2):#tang theo don vi theo vd la tang 2 don vi
    print(i)
colors=["red", "green","blue"]
for color in colors:
    print(color) 
#duyet phan tu theo vi tri
for i in range(len(colors)):
    print(colors[i])
#vong lap long nhau
for i in range(1,11):
    print("2*{0}= {1}".format(i,2*i))
print("*"*100)
for j in range(2, 10):
    print("bang cua chuong: ",j)
    for i in range(1,11):
        print("{0}*{1}= {2}".format(j,i,j*i))
#in hinh chu nhat 
n=9
for i in range (1,n):
    print("+",end=' ')
    for j in range (1,n):
        if j%2==i%2:
            print(' ',end='')
        else:
            print("*",end='')
    print('+')
         