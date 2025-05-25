from xulyFile import *
# def thongtin():
    
#     print("\nnhap danh sach: ")
#     for i in range (n):
#         maLop=input("nhap ma lop: ")
#         tenLop=input("nhap ten lop: ")
#         si_so=input("si so lop: ")
#         maSV=input("nhap ma SV: ")
#         tenSV=input("nhap ten SV: ")
#         namsinh=int(input("nam sinh: "))
#         lop=input("lop: ")
#     thongtin="ma lop: "+maLop+'\n'+"ten lop: "+tenLop+'\n'+"si so: "+si_so+'\n'+"mssv: "+maSV+'\n'+"ten: "+tenSV+"\n"+"ngay sinh: "+str(namsinh)+'\n'+"lop: "+lop+'\n'
# while(True):
#     noidung=[]
#     n=input("nhap sinh vien thu: ")
#     for i in (str(n)):
#         print('thong tin sau khi nhap: \n',thongtin())
#     hoi=input("ban co muon nhap tiep khong? (c/k)")
#     if hoi=="k":
#         break
# print('bye')
# luuFile(thongtin())

while(True):
    n=input("nhap sinh vien thu: ")

    maLop=input("nhap ma lop: ")
    tenLop=input("nhap ten lop: ")
    si_so=input("si so lop: ")
    maSV=input("nhap ma SV: ")
    tenSV=input("nhap ten SV: ")
    namsinh=int(input("nam sinh: "))
    lop=input("lop: ")
    thongtin="ma lop: "+maLop+'\n'+"ten lop: "+tenLop+'\n'+"si so: "+si_so+'\n'+"mssv: "+maSV+'\n'+"ten: "+tenSV+"\n"+"ngay sinh: "+str(namsinh)+'\n'+"lop: "+lop+'\n'
    hoi=input("ban muon nhap tiep khong? (c/k)")
    if hoi=="k":
        break
print("Bye!!")
luuFile(thongtin)