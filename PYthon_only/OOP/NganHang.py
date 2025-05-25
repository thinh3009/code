class NganHang():
    def __init__(self):
        self.stk=0
        self.tennganhang=''
    def nhapnganhang(self):
        self.tennganhang = input(f"nhap ten ngan hang ({self.tennganhang}): ")
        self.stk = input(f"nhap stk: ({self.stk}): ")
        
    def doitennganhang(self):
        if self.tennganhang == self.tennganhang and self.stk == self.stk:
            print(f'Da co thong tin ngan hang ban co muon doi hay khong: 1:co/2:khong')
            x = int(input())
            if x == 1:
                self.tennganhang = input(f"nhap ten ngan hang moi ({self.tennganhang}): ")
                self.stk = input(f"nhap stk moi: ({self.stk}): ")
                print(f'ten ngan hang moi: {self.tennganhang}')
                print(f'Stk moi: {self.stk}')
            else:
                print(f'ten ngan hang: {self.tennganhang}')
                print(f'Stk: {self.stk}')
    def xuatNganHang(self):
        print('ten ngan hang: ',self.tennganhang)
        print("so tai khoan: ",self.stk)

class CongTy(NganHang):

    def __init__(self):
        super().__init__()
        self.tencty = ''
        self.diachi = ''
        self.masothue = 0
        self.hinhthucthanhtoan = ''
        self.website = ''
        self.tennganhang= ''
        self.stk=''
    def nhapthongtin(self):
        self.tencty = input(f"nhap ten cong ty ({self.tencty}): ")
        self.diachi = input(f"nhap dia chi: ({self.diachi}): ")
        self.masothue = int(input(f'nhap ma so thue: ({self.masothue}): '))
        self.hinhthucthanhtoan = input(f'hinh thuc thanh toan: ({self.hinhthucthanhtoan}): ')
        self.website = input(f'nhap web site: ({self.website}): ')
        self.tennganhang=input(f'nhap ten ngan hang: ({self.tennganhang})')
        self.stk=input(f'nhap stk: {self.stk}')
    def xuatthongtin(self):
        print(f'Ten cong ty: {self.tencty}')
        print(f'Dia chi: {self.diachi}')
        print(f'Ma so thue: {self.masothue}')
        print(f'Hinh thuc thanh toan: {self.hinhthucthanhtoan}')
        print(f'Website: {self.website}')
        self.xuatNganHang()


        
class TenHang():
    
    def __init__(self):
        self.tensp=""
        self.masp=""
        self.donvi=""
        self.soluong=0
        self.dongia=0
        self.thanhtien=0
    def nhapSanPham(self):
        self.tensp=input(f'nhap ten san pham: {self.tensp}')
        self.masp=input(f'nhap ma san pham: {self.masp}')
        self.donvi=input(f'nhap don vi: {self.donvi}')
        self.soluong=int(input(f'nhap so luong: {self.soluong}'))
        self.dongia=int(input(f'nhap don gia: {self.dongia}'))
    def tinhtien(self):
        self.thanhtien=self.soluong*self.dongia
        return self.thanhtien
    def xuathoadon(self):
        print(f'Ten san pham: {self.tensp}')
        print(f'Ma san pham: {self.masp}')
        print(f'Don vi: {self.donvi}')
        print(f'So luong: {self.soluong}')
        print(f'Don gia: {self.dongia}')
        print(f'Thanh tien: {self.tinhtien()}')
        


class KhachHang(TenHang,NganHang):
    def __init__(self):
        super().__init__()
        self.tenkhachhang = ""
        self.madonhang = ""
        self.sodienthoai = ""
        self.diachi = ""
        self.hinhthucthanhtoan = ""

    def nhapthongtin(self):
        self.tenkhachhang = input("Nhập tên khách hàng: ")
        self.madonhang = input("Nhập mã đơn hàng: ")
        self.sodienthoai = int(input("Nhập số điện thoại: "))
        self.diachi = input("Nhập địa chỉ: ")
        self.hinhthucthanhtoan = input("Nhập hình thức thanh toán: ")
    def xuatthongKH(self):
        print('ten khach hang: ',self.tenkhachhang)
        print('ma don hang: ',self.madonhang)
        print('so dien thoai: ',self.sodienthoai)
        print('dia chi: ',self.diachi)
        print('hinh thuc thanh toan: ',self.hinhthucthanhtoan)
    def doithongtinkhach(self):
        mess={
            '1': 'doi ten khach hang',
            '2': 'doi ma don hang',
            '3': 'doi so dien thoai',
            '4': 'doi dia chi',
            '5': 'doi so tai khoan',
        }
        print('Ban muon doi thong tin nao?',mess)
        nhap = int(input('nhap lua chon: '))
        if nhap==1:
            self.tenkhachhang=input('nhap ten khach hang moi: ')
        elif nhap==2:
            self.madonhang=input('nhap ma don hang moi: ')
        elif nhap==3:
            self.sodienthoai=input('nhap so dien thoai moi: ')
        elif nhap==4:
            self.diachi=input('nhap dia chi moi: ')
        else:
            self.sotk=input('nhap so tai khoan moi: ')
        self.xuatthongKH()
        

 




khach=KhachHang()
hang = TenHang()
cty=CongTy()
bank=NganHang()
cty.nhapthongtin()
cty.xuatthongtin()
cty.doitennganhang()


        