'''class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def move(self):
        print("move")
    def draw(self):
        print("draw")



point = Point(10,20)
point.x=11
print(point.x)'''

class Person:
    def __init__(self,name):
        self.name=name
    def talk(self):
        print(f"hi, I am {self.name}")
    
john=Person("john ne")

john.talk()

bob=Person("bob ne")
bob.talk()
#inheritance
class Mammal:
    def walk(self):
        print("walk")

class Dog(Mammal):
    pass
class Cat(Mammal):
    def be_anoying(self):
        print("dcm")
dog1=Dog()
dog1.walk()

cat1=Cat()
cat1.walk()
cat1.be_anoying()