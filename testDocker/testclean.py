import math 
def Funciton(a,b,c):
    delta=pow(b,2)-(4*a*c)
    if delta<0:
        print("phuong trinh vo nghiem")
    elif delta==0:
        print("phuong trinh co nghiem kep")
        x=-b/(2*a)
        print(x)
    else:
        print("phuong trinh co 2 nghiem phan biet")
        x1=(pow(a,2)-math.sqrt(delta))/(2*a)
        x2=(pow(a,2)+math.sqrt(delta))/(2*a)
        print(x1)
        print(x2)
        
if __name__=="__main__":
    Funciton(2,3,0)  