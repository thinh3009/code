
def kiemtrachuoi(n):
    n=input("nhap mk: ")
    dem=0
    while (len(n)<=6 or n==n.isdigit()):
        dem=dem+1
        s=input(f"ban nhap sai {dem} lan")
        if dem==5:
            print("ban da nhap sai qua 5 lan!")
            break
    else:
        print("ban nhap dung")
a=input("nhap mat khau: ")
kiemtrachuoi(a)

'''x=bool
y=bool#true/false
for i in n:
    if i.isdigit():
        x=True
        break
    else:
        x=False
for i in n:
    if i.isalpha():
        y=True
        break
    else:
        y=False
print(x,y)
#print(len(n))
while len(n)<6 or x==False:
    n=input("nhap lai mk it nhat 6 ki tu mot chu cai va mot so: ")
else:
    print("mk hop le")


#2.nhap mk
s=input("nhap mk")
dem=0
while s!=n:
    dem=dem+1
    s=input(f'nhap sai lan thu {dem}: ')
    if dem==5:
        print("nhap sai qua 5 lan")
        break
else:
    print("dang nhap thanh cong!!")'''
