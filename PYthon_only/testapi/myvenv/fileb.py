from file_common import CommonFeatures

class ClassB(CommonFeatures):
    def __init__(self):
        super().__init__()  # Gọi constructor của class cha
        self.specific_b = "Dữ liệu riêng B"
    
    def method_b(self):
        print("Phương thức riêng của B")
        # Sử dụng phương thức tiện ích chung
        result = self.utility_method(5, 3)
        print(f"Kết quả tính toán: {result}")