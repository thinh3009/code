import requests

BASE_URL = 'http://localhost:5000/products'

# Tạo sản phẩm mới
new_product = {
    'name': 'Python Book',
    'price': 29.99,
    'description': 'Learn Python programming'
}
response = requests.post(BASE_URL, json=new_product)
print('POST /products:', response.json())

product_id = response.json()['_id']

# Lấy danh sách sản phẩm
response = requests.get(BASE_URL)
print('GET /products:', response.json())

# Lấy chi tiết sản phẩm
response = requests.get(f'{BASE_URL}/{product_id}')
print(f'GET /products/{product_id}:', response.json())

# Cập nhật toàn bộ sản phẩm
updated_product = {
    'name': 'Advanced Python Book',
    'price': 39.99,
    'description': 'Advanced Python programming',
    'inStock': False
}
response = requests.put(f'{BASE_URL}/{product_id}', json=updated_product)
print(f'PUT /products/{product_id}:', response.json())

# Cập nhật một phần
partial_update = {'price': 35.99}
response = requests.patch(f'{BASE_URL}/{product_id}', json=partial_update)
print(f'PATCH /products/{product_id}:', response.json())

# Xóa sản phẩm
# response = requests.delete(f'{BASE_URL}/{product_id}')
# print(f'DELETE /products/{product_id}:', response.json())