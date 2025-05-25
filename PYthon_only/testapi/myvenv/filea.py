from file_common import CommonFeatures

class ClassA(CommonFeatures):
    def __init__(self):
        super().__init__()  # Gọi constructor của class cha
        self.specific_a = "Dữ liệu riêng A"
    
    def method_a(self):
        print("Phương thức riêng của A")
        # Gọi phương thức chung
        self.common_method()


