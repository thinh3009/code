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
    
item1=item('phone',20000,1)
item2=item('laptop',40000,2)
item3=item('baocaosu')
print('mat hang co ten la: ',item1.name)
print('mat hang co gia la: ',item1.price)
print('mat hang co so luong: ',item1.quantity)

print(item1.TongGia())
