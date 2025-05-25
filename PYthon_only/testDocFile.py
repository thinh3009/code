from xulyFile import *
dssv=docFile()
def xuatSV(dssv):
    for row in dssv:
        for element in row:
            print(element,end='\t')
        print()
    print()
xuatSV(dssv)
def sapxepSV(dssv):
    for i in range (len(dssv)):
        for j in range(len(dssv)):
            a=dssv[i] 
            b=dssv[j]
            if a[2]>b[2]:
                dssv[i]=b
                dssv[j]=a
sapxepSV(dssv)
print("ds sinh vien sau khi xep: ")
xuatSV(dssv)