#proof of work: bang chung cong viec 
''' bang cach tron them 1 so ngau nhien'''
import hashlib
class Block:
    def __init__(self,data):
        self.data=data
        self.prev_hash=""
        #proof of work: tao mot con so ngau nhien
        self.nonce=0
        self.hash=""

def hash(block):
    #khi bam ta bam them so nonce
    data=block.data+block.prev_hash+ str(block.nonce)
    data=data.encode("utf-8")
    #goi bang bam sha256
    #hexdigest:chuoi the hien 32 ki tu
    return hashlib.sha256(data).hexdigest()
   


class Blockchain:
    def __init__(self):
        #tao list chua chain
        self.chain=[]
        #tao blcok dau tien (luon co dau tien)
        block=Block("Geneis Block")
        #cap ma bam
        #neu co so nonce thi yeu cau ma khi bam phai co con so 
        block.hash=hash(block)
        #day vao list
        self.chain.append(block)
    #ham add block vao chain 
    def ad_block(self,data):
        block=Block(data)
        block.prev_hash=self.chain[-1].hash
        block.hash=hash(block)
        #de tim ra con so do ta phai lap cho den khi tim ra duoc con so do
        #neu khong dung con so trong startwith ta se tang so nonce len 1 
        #tiep tuc lap cho den khi tim dung so
        while hash(block).startswith("000")==False:
            block.nonce=block.nonce+1
            block.hash=hash(block)
        
        self.chain.append(block)
    def print(self):
        #in cac block ra
        for block in self.chain:
            print("data:",block.data)
            print("hash:", block.hash)
            print("prev_hash",block.prev_hash)
            print("Nonce: ",block.nonce)
            print("")
    #kiem tra block co bi thay doi du lieu khong
    def check_isvalidData(self):
        #duyet lai toan bo block va bam lai neu du lieu thay doi thi ma hash cung thay doi theo
        #lap tu block dau tien bo genesis block
        for i in range(1,len(self.chain)):
            #lay thong tin cua block dau tien
            current_block=self.chain[i]
            #thong tin block truoc no
            prev_block = self.chain[i-1]
            #neu bam block thu i van tra ra hash cu thi dung
            if hash(current_block)!= current_block.hash:
                return False
            #neu ma hash trc do bang prephash hien tai thi dung
            if prev_block.hash != current_block.prev_hash:
                return False
            
        return True
blockchain=Blockchain()
blockchain.ad_block("chao cac ban")
blockchain.ad_block("12334")
blockchain.ad_block("hoc sinh gioi")
#gia su thay doi du lieu sau do bam du lieu bi thay doi 
# blockchain.chain[1].data="bui duc ha"
# blockchain.chain[1].hash=hash(blockchain.chain[1])
#kiem tra 
print("is valid: ",blockchain.check_isvalidData())
blockchain.print()
#ktra ma hash
'''block=Block("bui duc thinh")
print(hash(block))'''
'''
tom lai tang so 0 len se ton 
'''