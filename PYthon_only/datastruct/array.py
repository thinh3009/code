#lst=[0,1,2,3,4,5,'ditmemar',6,567,7,6,5,3]
'''lst2=["pttron","efsdf"]
lst3=[lst,lst2]
print(lst[3])
for i in range(len(lst)-1,-1,-1):
    k=lst[i]
    print(k,end=" ")'''
#del lst[1]
# remove
#lst.remove(567)
#print(len(lst))
#print(lst.index(4))
import random
from math import sqrt
def taonptu(n):
    mang=[]
    for i in range(n):
        mang.append(random.randint(1,100))
    return mang
def taophantu2(n):
    mang=[]
    for i in range (n):
        mang.append(random.randint(1,100))
    mang2=[]
    for j in range (len(mang)):
        mang2.append(mang[j]**2)
    return mang,mang2
def traketqua(kqua):
    for i in kqua:
        #print(i.strip("="))#xoa dau bang
        ans=eval(i.strip("="))#dap an dung ham eval
        traloi=float(input(i))
        if traloi==ans:
            print("dung")
        else:
            print("sai,ket qua la: ",ans)
    return kqua 

if __name__=="__main__":
    #n=int(input("nhap so luong phan tu"))
    #mang, mang2 = taophantu2(n)  # split the two arrays here
    #print("mang:", mang)
    #print("mang2:", mang2)
    kqua=["2 + 5 + 3=","5 * 20 =", "sqrt(4) =", "12 % 2 =", "5 // 2 ="]
    traketqua(kqua)
