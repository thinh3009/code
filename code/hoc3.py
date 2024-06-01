def luuFile(data):
    file=open('database.txt','a',encoding='utf-8')
    file.writelines(data)
    file.writelines('\n')
    file.close()
def docFile():
    arrProduct=[]
    file=open("database.txt",'r',encoding='utf-8')
    for line in file:
        data=line.strip()
        arr=data.split(';')
        arrProduct.append(arr)
    file.close()
    return arrProduct