class Bank():
    def __init__(self,hoten,cmt):
        self.hoten=hoten
        self.cmt=cmt

class NhanVien(Bank):
    def __init__(self, hoten, cmt):
        super().__init__(hoten, cmt)
        self.__luong=5000#dung 2 gach duoi de tao private

        #code de truy cap vao luong
    def get(self):
        return self.__luong
    def set(self,luong_moi):
        self.__luong=luong_moi#set luong moi


nv1=NhanVien('mai',23123123)
print(nv1.cmt,'\t')
nv1.set(90000)
print(nv1.get())