#ke thua
class item():
    def __init__(self,name:str,price:float,quantity:int):
        self.name=name
        self.price=price
        self.quantity=quantity
    #goi phuong thuc
    def TongGia(self):
        return self.price*self.quantity
    
    #phuong thuc tinh
    @staticmethod
    def CheckGia(gia):
        if gia==500:
            return 'retien'
        else:
            return 'dat tien'
#tao class con
class Phone(item):
    def __init__(self, name: str, price: float, quantity: int,loai:str):
        super().__init__(name, price, quantity)#ke thua cac thuoc tinh ma lop cha co
        self.loai=loai #khai bao thuoc tinh nhu binh thuong


phone1=Phone('ipad',2000,1,'m10')
print(phone1.name)
print(phone1.loai)

