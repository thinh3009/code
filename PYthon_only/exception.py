try:
    age=int(input('age: '))
   
    print(age)
except ZeroDivisionError:
    print("age cannot be 0")
except ValueError:
    print('Invalid values')
