class item():
    def __init__(self,name,price,quantity):
        self.name=name
        self.price=price
        self.quantity=quantity

item1=item('phone',20000,1)
item2=item('laptop',40000,2)
print('mat hang co ten la: ',item1.name)
print('mat hang co gia la: ',item1.price)
print('mat hang co so luong: ',item1.quantity)
