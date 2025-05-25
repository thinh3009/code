import random
def sinhngaunhien(n):
    mang=[]
    for i in range(n):
        songaunhien=random.randint(0,100)
        mang.append(songaunhien)
    return mang
def sapxepnoibot(mang):
    for i in range (len(mang)):#i=[0,n-1]
        tiep_tuc=False

        for j in range(len(mang)-2,i-1,-1):#j=[n-2,i],
            if mang[j]>mang[j+1]:
                mang[j],mang[j+1]=mang[j+1],mang[j]
                tiep_tuc=True
        print(i+1,'-',mang)

        if tiep_tuc==False:
            break
def main():
    mang=sinhngaunhien(10)
    print("mang ban dau la: ",mang)
    sapxepnoibot(mang)
    print("mang sau khi sap xep: ",mang)

if __name__=="__main__":
    main()


