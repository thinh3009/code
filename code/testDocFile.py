from xuLy_File import *
arrSo= docFile()
print(arrSo)
def xuat_so_am(arrSo):
    for row in arrSo:
        for element in row:
            number=int(element)
            if number<0:
                print(number,end='\t')
        print()
print("cac so am tren moi dong: \n")
xuat_so_am(arrSo)