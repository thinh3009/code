var thongBaos = document.getElementsByClassName('thongBao');
document.getElementById('btnDangKy').onclick = function () {
    check();
};
//ten
function check() {
    var hoTen = document.getElementById('name');
    if (hoTen.value == "") {
        thongBaos[0].innerText = "Không được để trống tên";
        thongBaos[0].style.color = "red";
    } else {
        thongBaos[0].innerText = "";
        thongBaos[0].style.color = "green";
    }
    //email
    var email = document.getElementById('email');
    if (email.value == "") {
        thongBaos[1].innerText = "Email không được để trống";
        thongBaos[1].style.color = "red";
    } else {
        thongBaos[1].innerText = "";
        thongBaos[1].style.color = "green";
    }
    //mssv
    var mssv = document.getElementById('id');
    if (mssv.value == "") {
        thongBaos[2].innerText = "Không được để trống mã sinh viên!!";
        thongBaos[2].style.color = "red";
    } else {
        thongBaos[2].innerText = "";
        thongBaos[2].style.color = "green";
    }
    
    
    
    //thong bao dang ky thanh cong
    if (thongBaos[0].innerText == "" && thongBaos[1].innerText == "" && thongBaos[2].innerText == "") {
        alert("Đăng kí thành công!!!")
    }
}

