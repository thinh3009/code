import random
import re
import sys

#
# Complete the 'simpleArraySum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY ar as parameter.
#

def simpleArraySum(ar):
    # Write your code here
    arra=[]
    for i in range (0,ar):
        n=int(input(f'nhap phan tu thu {i+1}: '))
        arra.append(n)
    tongArr=sum(arra)
    return tongArr
        

if __name__ == '__main__':
    n=int(input('nhap so phan tu: '))
    print(simpleArraySum(n))