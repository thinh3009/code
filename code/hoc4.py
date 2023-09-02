from hoc3 import *
dssp=docFile()
#print(dssp)-->doc file tu database
def xuatSP(dssp):
    for row in dssp:
        for element in row:
            print(element,end='\t')
        print()
    print()
xuatSP(dssp)
def sapxep(dssp):
    for i in range (len(dssp)):
        for j in range(len(dssp)):
            a=dssp[i]
            b=dssp[j]
            if a[2]>b[2]:
                dssp[i]=b
                dssp[j]=a
sapxep(dssp)
print("san pham sau khi sap xep: ")
xuatSP(dssp)
