import requests

# Thông số API
API_URL = "https://api.openai.com/v1/chat/completions"  # Thay bằng URL thật của DeepSeek API
API_KEY = "Bearer sk-bcec1212531f4b8bb6cae32767lebf7f"    # Thay bằng API key thật của bạn

# Headers
headers = {
    "Content-Type": "application/json",
    "Authorization": API_KEY
}

# Body (JSON data)
payload = {
    "model": "deepseek-chat",  # Thay bằng model thật (nếu cần)
    "messages": [
        {"role": "user", "content": "Xin chào! Bạn có hoạt động không?"}
    ],
    "temperature": 0.7
}

try:
    # Gửi POST request
    response = requests.post(API_URL, headers=headers, json=payload)
    
    # Kiểm tra kết quả
    if response.status_code == 200:
        print("✅ API hoạt động tốt!")
        print("Phản hồi từ API:", response.json())
    else:
        print(f"❌ Lỗi {response.status_code}: {response.text}")

except requests.exceptions.RequestException as e:
    print(f"❌ Lỗi kết nối: {e}")