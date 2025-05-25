from pymongo import MongoClient
from dotenv import load_dotenv
import os

# Load biến môi trường
load_dotenv()

# Lấy connection string từ .env
mongo_uri = os.getenv('MONGO_URI')

try:
    # Kết nối tới MongoDB
    client = MongoClient(mongo_uri)
    
    # Kiểm tra kết nối
    client.admin.command('ping')
    print("Kết nối MongoDB thành công!")
    
    # Tạo/truy cập database
    db = client['mydatabase']
    
    # Tạo/truy cập collection
    collection = db['mycollection']
    
    # Thử insert một document
    test_doc = {"name": "Test", "message": "Hello MongoDB!"}
    insert_result = collection.insert_one(test_doc)
    print(f"Đã insert document với id: {insert_result.inserted_id}")
    
    # Đếm số document
    count = collection.count_documents({})
    print(f"Số document trong collection: {count}")
    
except Exception as e:
    print(f"Lỗi kết nối MongoDB: {e}")
finally:
    # Đóng kết nối khi không dùng nữa
    if 'client' in locals():
        client.close()