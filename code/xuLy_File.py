def luuFile(data):
    file=open('dulieuso.txt','a',encoding='utf-8')
    file.writelines(data)
    file.writelines('\n')
    file.close()
def docFile():
    arrSo=[]
    file=open('dulieuso.txt','r',encoding="utf-8")
    for line in file:
        data=line.strip()
        arr=data.split(',')
        arrSo.append(arr)
    file.close()
    return arrSo
    