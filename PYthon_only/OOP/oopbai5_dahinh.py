class Sinhvien_nuocngoai():
    def __init__(self,hoten,msv,que):
        self.hoten=hoten
        self.msv=msv
        self.que=que

    def chao(self):
        print('hello')

class Sinhvien_vn():
    def __init__(self,hoten,msv,que):
        self.hoten=hoten
        self.msv=msv
        self.que=que

    def chao(self):
        print('xin chao')

def Hi(Sinhvien_vn):
    Sinhvien_vn.chao()
sv1=Sinhvien_nuocngoai('alex',123,'usa')
sv2=Sinhvien_vn('thinh',123123,"hanoi")
Hi(sv1)
sv2.chao()
sv1.chao()