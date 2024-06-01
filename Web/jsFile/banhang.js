//them sp
function them(button) {
    var row = button.parentElement.parentElement.cloneNode(true);

    var btnXoa = row.getElementsByTagName("button")[0];
    btnXoa.innerText = "Xóa";
    btnXoa.setAttribute('onclick', 'xoa(this)');
    document.getElementById("cart").appendChild(row);
    tinhTong();
    document.getElementById("cart").style.display = "";
    document.getElementsByTagName("h3").style.display = "";

    //chon so luong va tinh tien
    var pro = document.getElementById("pro");
    var qty = document.getElementById("qty");
    var price = pro.getAttribute("data-price");
    var quality =qty.value; 
    var amount = price * price;
    document.getElementById("tong").innerText=amount;


}

//xoa sp
function xoa(button) {
    var row = button.parentElement.parentElement;
    document.getElementById("cart").removeChild(row);
    tinhTong();
}
//auto tinh tong
function tinhTong() {
    var cart = document.getElementById("cart");
    var rows = cart.getElementsByTagName("tr");
    var tong = 0;
    for (var i = 0; i < rows.length; i++) {

        var price = rows[i].children[2].innerText;
        price = parseInt(price)
        tong += price;
    }
    document.getElementById("tong").innerText = tong;
}


document.getElementById("cart").style.display = "none";
document.getElementsByTagName("h3").style.display = "none";

function daott(obj) {
    var row = obj.parentElement.parentElement;
    var btn = row.getElementsByTagName("button")[0];
    btn.disabled = !btn.disabled;
}
//chon muc gia
var chonGia = document.getElementById('chonGia');
var options = chonGia.getElementsByTagName('option');
//chon va hien thi san pham
var gia1SPs = document.getElementsByClassName('gia1SP');
chonGia.onchange = function () {
    hienThiSP();
}
function hienThiSP() {
    if (chonGia.value == 'Dưới 100k') {
        for (var i = 0; i < 5; i++) {
            if (Number(gia1SPs[i].innerText) < 100) {
                var tr = gia1SPs[i].parentElement;
                tr.style.display = 'table-row';
            }
            else {
                var tr = gia1SPs[i].parentElement;
                tr.style.display = 'none';
            }
        }
    }
}
