// Lọc sản phẩm theo mức giá
function locSanPhamTheoGia() {
    var selectBox = document.getElementById('chonGia');
    var selectedValue = selectBox.value;

    var productList = document.querySelectorAll('tbody tr'); // Lấy tất cả các hàng sản phẩm

    // Lặp qua từng sản phẩm và ẩn/hiển thị tùy theo mức giá được chọn
    productList.forEach(function (product) {
        var gia = parseFloat(product.querySelector('#ct').textContent);

        if (selectedValue === 'Chọn mức giá'){
            product.style.display = 'table-row';// Hiển thị sản phẩm
        } else if (selectedValue === 'Dưới 100k' && gia < 100000) {
            product.style.display = 'table-row'; // Hiển thị sản phẩm
        } else if (selectedValue === '100k-500k' && gia >= 100000 && gia <= 500000) {
            product.style.display = 'table-row'; // Hiển thị sản phẩm
        } else if (selectedValue === 'Trên 600k' && gia >= 600000) {
            product.style.display = 'table-row'; // Hiển thị sản phẩm
        } else {
            product.style.display = 'none'; // Ẩn sản phẩm
        }
    });
}

// Gắn sự kiện thay đổi mức giá khi trang tải xong
document.addEventListener('DOMContentLoaded', function() {
    var selectBox = document.getElementById('chonGia');
    selectBox.addEventListener('change', locSanPhamTheoGia);
});

// Khi thay đổi số lượng hoặc tích vào checkbox
function capNhatGioHang(input) {
    var gioHangTable = document.getElementById('cart');
    var tongTienSpan = document.getElementById('tong');
    var tongTien = 0;

    gioHangTable.innerHTML = ''; // Xóa nội dung giỏ hàng cũ

    var productList = document.querySelectorAll('tbody tr'); // Lấy tất cả các hàng sản phẩm

    // Lặp qua từng sản phẩm để kiểm tra số lượng và checkbox
    productList.forEach(function (product) {
        var checkbox = product.querySelector('input[type="checkbox"]');
        var soLuongInput = product.querySelector('#qty');
        var gia = parseFloat(product.querySelector('#ct').textContent);
        var soLuong = parseInt(soLuongInput.value);

        // Kiểm tra nếu checkbox được tích chọn và số lượng hợp lệ
        if (checkbox.checked && !isNaN(soLuong) && soLuong > 0) {
            // Thêm thông tin sản phẩm vào giỏ hàng
            gioHangTable.innerHTML += `<tr><td>${product.querySelector('#pro').textContent}</td><td>${gia}</td><td>${soLuong}</td></tr>`;
            tongTien += gia * soLuong;
        }
    });

    // Cập nhật tổng số tiền
    tongTienSpan.textContent = tongTien.toFixed(2); // Hiển thị đến 2 chữ số thập phân
}

// Thêm chức năng khi người dùng chọn sản phẩm để mua
function them(button) {
    var row = button.closest('tr');
    var checkbox = row.querySelector('input[type="checkbox"]');
    checkbox.checked = true; // Đánh dấu checkbox là đã chọn
    capNhatGioHang(); // Cập nhật giỏ hàng
}

// Gắn sự kiện cho checkbox chọn hết
function chonHet(checkbox) {
    var checkboxes = document.querySelectorAll('input[type="checkbox"][name="chon"]');
    
    checkboxes.forEach(function(checkbox) {
        checkbox.checked = checkbox === this;
    }, checkbox);

    capNhatGioHang();
}

// Gắn sự kiện thay đổi số lượng và checkbox khi trang tải xong
document.addEventListener('DOMContentLoaded', function() {
    var qtyInputs = document.querySelectorAll('#qty');
    var checkboxes = document.querySelectorAll('input[type="checkbox"]');
    
    qtyInputs.forEach(function(input) {
        input.addEventListener('change', capNhatGioHang);
    });
    
    checkboxes.forEach(function(checkbox) {
        checkbox.addEventListener('change', capNhatGioHang);
    });
});


