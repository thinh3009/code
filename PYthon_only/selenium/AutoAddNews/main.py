from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import os
from PIL import Image
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from infomation import cms_url,user,password
#xu ly anh
# Đường dẫn ảnh gốc và ảnh sau khi resize

def Process_img(output_path):

    input_path = r"C:\Users\Asus\Desktop\thiscode\PYthon_only\selenium\AutoAddNews\hinh1.jpg"
    # output_path = r"C:\Users\Asus\Desktop\thiscode\PYthon_only\selenium\resized.jpg"

    # Mở ảnh
    img = Image.open(input_path)

    # Resize ảnh về đúng kích thước 390x270
    resized_img = img.resize((390, 270))

    # Lưu ảnh
    resized_img.save(output_path)



def Post_hot_tar_news():
    post_title = "Bài viết tự động"
    post_content = "Đây là nội dung bài viết được tạo tự động bằng Selenium."
    post_content2="Nghệ An: Thông xe kỹ thuật cầu vượt đường sắt"
    post_content3="""
        <p>Công ty đạt lợi nhuận ổn định năm 2024 từ mảng dầu nhờn, nhưng mảng hóa chất tiếp tục đối mặt với thách thức. Về kế hoạch năm 2025, PLC đặt muc tiêu lợi nhuận trước thuế 140 tỷ đồng (gấp đôi so với kết quả năm 2024; tương đương với kế hoạch đầu năm 2024). Trong giai đoạn 2010 – 2024, lợi nhuận trước thuế thực tế trung bình hoàn thành 101% so với kế hoạch đầu năm.Chi tiết lợi nhuận trước thuế theo mảng (trước hợp nhất): Mảng dầu nhờn đạt 110 tỷ đồng (tăng 3% so với cùng kỳ năm trước), nguồn đóng góp ổn định và vững chắc; Mảng nhựa đường đạt 43 tỷ đồng (tăng 310%), mục tiêu</p>

<img alt="hinh anh minh hoa" src="https://hoadaumiennam.com.vn/upload/elfinder/20191115-112706-1575243654-width1004height565.jpeg" style="width: 1004px; height: 565px;">

<p>tăng trưởng mạnh mẽ nhờ giải ngân đầu tư công; Mảng hóa chất đạt 2 tỷ đồng (so với lỗ ròng khoảng 46 tỷ đồng trong năm 2024), dự kiến cải thiện nhưng còn đối mặt với nhiều thách thức.Kết quả kinh doanh quý I/2025 sơ bộ cho thấy sự phục hồi mạnh với lợi nhuận trước thuế tăng 90% so với cùng kỳ 2024. Cụ thể, lợi nhuận trước thuế mảng dầu nhờn đạt 28 tỷ đồng (hoàn thiện 26% kế hoạch năm 2025), sản lượng cũng đạt 26% kế hoạch. Doanh số qua kênh Petrolimex tăng 9% so với cùng kỳ; doanh số qua kênh</p>

    """
    # Khởi tạo trình duyệt
    driver = webdriver.Edge()  # Hoặc Firefox, Edge, etc.
    driver.get(f"{cms_url}")
    time.sleep(3)
    # Đăng nhập
    driver.find_element(By.XPATH, '//*[@id="username"]').send_keys(user)
    time.sleep(5)
    driver.find_element(By.XPATH, '//*[@id="password"]').send_keys(password)
    time.sleep(6)
    driver.find_element(By.XPATH, '/html/body/div[2]/div/div/form/button').click()
    time.sleep(5)  # Đợi đăng nhập hoàn tất

    # Truy cập trang tạo bài viết
    driver.get(f"{cms_url}/index.php?com=news&act=man&type=tin-ve-nhua-duong")
    time.sleep(3)
    driver.find_element(By.XPATH,'/html/body/div/div[1]/section[2]/div[1]/a[1]').click()
    time.sleep(5)
    output_path=r"C:\Users\Asus\Desktop\thiscode\PYthon_only\selenium\AutoAddNews\resize.jpg"
    Process_img(output_path)
    image_path = os.path.abspath(output_path)  # Đảm bảo đường dẫn tuyệt đối
    upload_input = driver.find_element(By.ID, 'file-zone')  # hoặc By.NAME, By.XPATH, tùy giao diện
    upload_input.send_keys(output_path)
    driver.find_element(By.XPATH,'//*[@id="slugvi"]').send_keys(post_title)
    time.sleep(5)
    driver.find_element(By.XPATH,'//*[@id="tenvi"]').send_keys(post_content)
    time.sleep(5)
    driver.find_element(By.XPATH,'//*[@id="motavi"]').send_keys(post_content2)
    time.sleep(5)

    driver.execute_script("window.scrollTo(0, 600);")
    #find iframe
    iframe = driver.find_element(By.CLASS_NAME, "cke_wysiwyg_frame")
    driver.switch_to.frame(iframe)
    body = driver.find_element(By.TAG_NAME, "body")
    body.clear()
    body.send_keys(post_content3) 
    # driver.find_element(By.XPATH,'/html/body').send_keys(post_content3)
    time.sleep(4)
    
    # 👉 QUAN TRỌNG: Quay lại main page trước khi tiếp tục scroll và nhập
    driver.switch_to.default_content()
    #seo
    driver.execute_script("window.scrollTo(0, 700);")
    driver.find_element(By.XPATH,'//*[@id="titlevi"]').send_keys('nhựa đường')
    time.sleep(2)
    driver.find_element(By.XPATH,'//*[@id="keywordsvi"]').send_keys('nhựa đường')
    time.sleep(2)
    driver.find_element(By.XPATH,'//*[@id="descriptionvi"]').send_keys('nhựa đường')
    time.sleep(2)
    driver.find_element(By.XPATH,'/html/body/div[1]/div[1]/section[2]/form/div[1]/button[1]').click()
    time.sleep(5)

if __name__=="__main__":
    
    Post_hot_tar_news()
    time.sleep(3000)