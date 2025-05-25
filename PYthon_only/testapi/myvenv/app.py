from flask import Flask, request, jsonify
from pymongo import MongoClient
from bson.objectid import ObjectId
from dotenv import load_dotenv
import os

load_dotenv()

app = Flask(__name__)

# Kết nối MongoDB
client = MongoClient(os.getenv('MONGO_URI'))
db = client['productDB']
products_collection = db['products']

# Helper function để chuyển ObjectId thành string
def product_serializer(product):
    if product:
        product['_id'] = str(product['_id'])
        return product
    return None

@app.route('/')
def home():
    return "Product API"
@app.route('/products', methods=['GET'])
def get_products():
    try:
        # Pagination
        page = int(request.args.get('page', 1))
        limit = int(request.args.get('limit', 10))
        skip = (page - 1) * limit

        products = list(products_collection.find().skip(skip).limit(limit))
        total = products_collection.count_documents({})

        return jsonify({
            'data': [product_serializer(p) for p in products],
            'meta': {
                'page': page,
                'limit': limit,
                'total': total,
                'pages': (total + limit - 1) // limit
            }
        }), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/products/<product_id>', methods=['GET'])
def get_product(product_id):
    try:
        product = products_collection.find_one({'_id': ObjectId(product_id)})
        if product:
            return jsonify(product_serializer(product)), 200
        return jsonify({'message': 'Product not found'}), 404
    except Exception as e:
        return jsonify({'error': str(e)}), 400
    
@app.route('/products', methods=['POST'])
def create_product():
    try:
        data = request.get_json()
        
        # Validation
        if not data.get('name'):
            return jsonify({'error': 'Name is required'}), 400
        if not isinstance(data.get('price'), (int, float)):
            return jsonify({'error': 'Valid price is required'}), 400

        product = {
            'name': data['name'],
            'price': float(data['price']),
            'description': data.get('description', ''),
            'inStock': data.get('inStock', True)
        }

        result = products_collection.insert_one(product)
        product['_id'] = str(result.inserted_id)
        
        return jsonify(product), 201
    except Exception as e:
        return jsonify({'error': str(e)}), 500


@app.route('/products/<product_id>', methods=['PUT'])
def update_product(product_id):
    try:
        data = request.get_json()
        
        # Validation
        if not data.get('name'):
            return jsonify({'error': 'Name is required'}), 400
        if not isinstance(data.get('price'), (int, float)):
            return jsonify({'error': 'Valid price is required'}), 400

        updated_product = {
            'name': data['name'],
            'price': float(data['price']),
            'description': data.get('description', ''),
            'inStock': data.get('inStock', True)
        }

        result = products_collection.update_one(
            {'_id': ObjectId(product_id)},
            {'$set': updated_product}
        )
        
        if result.matched_count == 0:
            return jsonify({'message': 'Product not found'}), 404
            
        updated_product['_id'] = product_id
        return jsonify(updated_product), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 400
@app.route('/products/<product_id>', methods=['PATCH'])
def partial_update_product(product_id):
    try:
        data = request.get_json()
        update_data = {}
        
        if 'name' in data:
            if not data['name']:
                return jsonify({'error': 'Name cannot be empty'}), 400
            update_data['name'] = data['name']
            
        if 'price' in data:
            if not isinstance(data['price'], (int, float)):
                return jsonify({'error': 'Valid price is required'}), 400
            update_data['price'] = float(data['price'])
            
        if 'description' in data:
            update_data['description'] = data['description']
            
        if 'inStock' in data:
            update_data['inStock'] = bool(data['inStock'])

        result = products_collection.update_one(
            {'_id': ObjectId(product_id)},
            {'$set': update_data}
        )
        
        if result.matched_count == 0:
            return jsonify({'message': 'Product not found'}), 404
            
        updated_product = products_collection.find_one({'_id': ObjectId(product_id)})
        return jsonify(product_serializer(updated_product)), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 400


@app.route('/products/<product_id>', methods=['DELETE'])
def delete_product(product_id):
    try:
        # Soft delete
        result = products_collection.update_one(
            {'_id': ObjectId(product_id)},
            {'$set': {'deleted': True}}
        )
        
        # Hoặc xóa hoàn toàn:
        # result = products_collection.delete_one({'_id': ObjectId(product_id)})
        
        if result.matched_count == 0:
            return jsonify({'message': 'Product not found'}), 404
            
        return jsonify({'message': 'Product deleted successfully'}), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 400
if __name__ == '__main__':
    app.run(debug=True)