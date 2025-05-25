from filea import ClassA
from fileb import ClassB
if __name__=="__main__":
    # Sử dụng ClassA
    obj_a = ClassA()
    obj_a.method_a()
    print(obj_a.common_data)  # Truy cập thuộc tính chung

    # Sử dụng ClassB
    obj_b = ClassB()
    obj_b.method_b()
    obj_b.common_method()  # Gọi phương thức chung
