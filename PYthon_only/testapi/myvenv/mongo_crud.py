from pymongo import MongoClient
from bson.objectid import ObjectId
from dotenv import load_dotenv
import os

load_dotenv()

class MongoDB:
    def __init__(self):
        self.client = MongoClient(os.getenv('MONGO_URI'))
        self.db = self.client['mydatabase']
        self.collection = self.db['products']
    
    # CREATE
    def insert_product(self, product_data):
        """Thêm sản phẩm mới"""
        result = self.collection.insert_one(product_data)
        return result.inserted_id
    
    # READ
    def get_all_products(self):
        """Lấy tất cả sản phẩm"""
        return list(self.collection.find({}))
    
    def get_product_by_id(self, product_id):
        """Lấy sản phẩm theo ID"""
        return self.collection.find_one({'_id': ObjectId(product_id)})
    
    # UPDATE
    def update_product(self, product_id, update_data):
        """Cập nhật sản phẩm"""
        result = self.collection.update_one(
            {'_id': ObjectId(product_id)},
            {'$set': update_data}
        )
        return result.modified_count
    
    # DELETE
    def delete_product(self, product_id):
        """Xóa sản phẩm"""
        result = self.collection.delete_one({'_id': ObjectId(product_id)})
        return result.deleted_count
    
    def close_connection(self):
        """Đóng kết nối"""
        self.client.close()

# Sử dụng
if __name__ == '__main__':
    mongo = MongoDB()
    
    # Thêm sản phẩm
    new_id = mongo.insert_product({
        "name": "Bicycle",
        "price": 12000,
        "brand": "Adidas"
    })
    print(f"Đã thêm sản phẩm với ID: {new_id}")
    
    # Lấy tất cả sản phẩm
    products = mongo.get_all_products()
    print("Tất cả sản phẩm:")
    for p in products:
        print(p)
    
    # Đóng kết nối
    mongo.close_connection()