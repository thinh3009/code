#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

struct xe{
	char maxe[30],tenxe[30];
    int gia,soluong;
};
struct khachhang{
 char makhachhang[30],tenkhachhang[30],tinhtrangmuaxe[30];
};
struct nhanvien{
	char tennhanvien[30];
};
struct kho{
	int loaixe;
	char ngaytaophieu[30],maphieu[30];
	xe x[100];
};
struct hoadon{
	xe x[100];
	nhanvien nv;
	khachhang kh;
	char mahd[30],ngaylaphd[30];
	int loaixe;
};
void nhapxe(xe &x){
	cout<<"Nhap ma xe: ";
    cin>>x.maxe;
	cout<<"Nhap vao ten xe: ";
	cin>>x.tenxe;
	cout<<"Nhap vao gia: ";
	cin>>x.gia;
	cout<<"Nhap so luong: ";
   	cin>>x.soluong;
}
void xuatxe(xe x){
	cout<<"Ma xe: "<<x.maxe<<".Ten xe la: "<<x.tenxe<<".Gia la: "<<x.gia<<".So luong: "<<x.soluong<<endl;
}
void menu1(kho &k,int &n){
	int luachon;
	    while(true){
	    	cout<< "=================MENU================\n";
	    	cout<<"\t BAN DA CHON SO 1\n";
	    	cout<< "\t 1.1 Nhap thong tin xe trong kho\n";
	        cout<< "\t 1.2 Dieu chinh thong tin xe trong kho\n";
	        cout<< "\t 1.3 Liet ke thong tin xe trong kho\n";
	        cout<< "\t 1.4 Ket thuc chuong trinh!!!.\n";
	        cout<< "=====================================\n";
           	cout<<"Nhap vao lua chon(1->4): ";
          	cin>>luachon;
          	if(luachon==1){
          		cout<<"Nhap vao so luong loai xe co o trong kho: ";
          		cin>>k.loaixe;
          		cout<<"Nhap vao ma phieu: ";
          		cin>>k.maphieu;
          		cout<<"Nhap vao ngay tao phieu: ";
          		cin>>k.ngaytaophieu;
          		cout<<"Nhap vao cac xe trong kho va so luong\n";
          		for(int i=0;i<k.loaixe;i++){
          			cout<<"\t\tNhap xe thu "<<i+1<<endl;
          			nhapxe(k.x[i]);
				  }
	           }else if(luachon==2){
	           	char a[30];
	           	int dem=0;
	           	cout<<"Nhap ma xe can dieu chinh: ";
	           cin>>a;
	           	for(int i=0;i<k.loaixe;i++){
	           		if(strcmp(k.x[i].maxe,a)==0){
	           		    dem++;
	           		    cout<<"Nhap vao ten xe can sua: ";
                     	cin>>k.x[i].tenxe;
                    	cout<<"Nhap vao gia can sua: ";
                      	cin>>k.x[i].gia;
                       	cout<<"Nhap so luong can sua: ";
                       	cin>>k.x[i].soluong;
                       	cout<<"\tDa sua thanh cong.\n";
					   }
				   }
				if(dem==0) cout<<"Khong tim thay ma xe ma ban can dieu chinh trong danh sach xe.\n";
			   }
			   else if(luachon==3){
			  	cout<<"Ma phieu la: "<<k.maphieu<<endl<<"Ngay tao phieu la: "<<k.ngaytaophieu<<endl;
			  	cout<<"Danh sach xe co trong kho la\n";
			  	for(int i=0;i<k.loaixe;i++){
			  		cout<<"\tXe thu "<<i+1<<endl;
			  		xuatxe(k.x[i]);
				  }
			  }
		       else if(luachon==4){
			  	cout<<"Cam on ban da su dung chuong trinh!!!\n";
			  	break;
			  }	else{
	                cout<<"Ban da nhap sai.Vui long nhap lai\n";
              }
		}
}
void menu2(hoadon hd[],int &m){
	int luachon;
	    while(true){
	    	cout<< "=================MENU================\n";
	    		cout<<"\t BAN DA CHON SO 2\n";
	    	cout<< "\t 1.1 Nhap cac thong tin don dat hang\n";
	        cout<< "\t 1.2 Dieu chinh thong tin cac don dat hang\n";
	        cout<< "\t 1.3 Liet ke thong tin xe cac don dat hang\n";
	        cout<< "\t 1.4 Ket thuc chuong trinh!!!.";
	        cout<< "=====================================\n";
           	cout<<"Nhap vao lua chon(1->4): ";
          	cin>>luachon;
          	if(luachon==1){
          		cout<<"Nhap vao so luong don dat hang: ";
          		cin>>m;
          	    for(int i=0;i<m;i++){
          	    	cout<<"\tNhap vao thong tin don dat hang thu "<<i+1<<endl;
          	    	cout<<"Nhap vao ma hoa don: ";
          	        cin>>hd[i].mahd;
          	        cout<<"Nhap vao ngay lap hoa don: ";
          	       cin>>hd[i].ngaylaphd;
          	        cout<<"Nhap vao ten nhan vien: ";
          	        cin>>hd[i].nv.tennhanvien;
          	        cout<<"Nhap vao ma khach hang: ";
          	      cin>>hd[i].kh.makhachhang;
          	        cout<<"Nhap vao ten khach hang: ";
          	        cin>>hd[i].kh.tenkhachhang;
          	        cout<<"Nhap vao tinh trang mua xe(mua ngay,6 thang,1 nam,3 nam): ";
          	        cin>>hd[i].kh.tinhtrangmuaxe;
          	        cout<<"Nhap vao so luong loai xe:";
          	        cin>>hd[i].loaixe;
          	        for(int j=0;j<hd[i].loaixe;j++){
          			cout<<"\t\tXe thu "<<j+1<<endl;
          			nhapxe(hd[i].x[j]);
				  }
				  }	  	
	           }else if(luachon==2){
	           	char a[30];
	           	int dem=0;
	           	cout<<"Nhap ma hoa don can dieu chinh: ";
	           	cin>>a;
	           	for(int i=0;i<m;i++){
	           		if(strcmp(hd[i].mahd,a)==0){
	           		    dem++;
	           		    cout<<"Nhap vao ten khach hang can sua: ";
                     	cin>>hd[i].kh.tenkhachhang;
                       	cout<<"Nhap vao tinh trang mua xe(mua ngay,6 thang,1 nam,3 nam) can chinh sua: ";
          	           cin>>hd[i].kh.tinhtrangmuaxe;
                       	cout<<"\tDa sua thanh cong.\n";
					   }
				   }
				if(dem==0) cout<<"Khong tim thay ma xe ma ban can dieu chinh trong danh sach xe.\n";
			   }
			   else if(luachon==3){
			  	for(int i=0;i<m;i++){
          	    	cout<<"\tThong tin don dat hang thu "<<i+1<<endl;
          	    	cout<<"Ma hoa don: "<<hd[i].mahd<<endl;
                    cout<<"Ngay lap hd" <<hd[i].ngaylaphd<<endl;
          	        cout<<"Ten nhan vien: "<<hd[i].nv.tennhanvien<<endl;
                    cout<<"Ma khach hang: "<<hd[i].kh.makhachhang<<endl;
                    cout<<"Ten khach hang: "<<hd[i].kh.makhachhang<<endl;
          	        cout<<"Nhap vao ma khach hang: "<<hd[i].kh.tenkhachhang<<endl;
          	        cout<<"Tinh trang mua xe: "<<hd[i].kh.tinhtrangmuaxe<<endl;
          	        for(int j=0;j<hd[i].loaixe;j++){
			  		cout<<"\t\tXe thu "<<j+1<<endl;
			  		xuatxe(hd[i].x[j]);
				  }
				  }	
			  }
			   
		       else if(luachon==4){
			  	cout<<"Cam on ban da su dung chuong trinh!!!\n";
			  	break;
			  }	else{
	                cout<<"Ban da nhap sai.Vui long nhap lai\n";
              }
		}
}
void menu3(hoadon hd[],int &z){
	int luachon;
	    while(true){
	    	cout<< "=================MENU================\n";
	    		cout<<"\t BAN DA CHON SO 3\n";
	    	cout<< "\t 1.1 Nhap cac thong tin don dat hang ban ngay\n";
	        cout<< "\t 1.2 Dieu chinh thong tin cac don dat hang ban ngay\n";
	        cout<< "\t 1.3 Liet ke thong tin xe cac don dat hang ban ngay\n";
	        cout<< "\t 1.4 Ket thuc chuong trinh!!!.";
	        cout<< "=====================================\n";
           	cout<<"Nhap vao lua chon(1->4): ";
          	cin>>luachon;
          	if(luachon==1){
          		cout<<"Nhap vao so luong don dat hang ban ngay: ";
          		cin>>z;
          	    for(int i=0;i<z;i++){
          	    	cout<<"\tNhap vao thong tin don dat hang thu "<<i+1<<endl;
          	    	cout<<"Nhap vao ma hoa don khach hang mua xe tra ngay: ";
          	       cin>>hd[i].mahd;
          	        cout<<"Nhap vao ngay lap hoa don khach hang mua xe tra ngay: ";
          	        cin>>hd[i].ngaylaphd;
          	        cout<<"Nhap vao ten nhan vien khach hang mua xe tra ngay: ";
          	       cin>>hd[i].nv.tennhanvien;
          	        cout<<"Nhap vao ma khach hang khach hang mua xe tra ngay: ";
          	      cin>>hd[i].kh.makhachhang;
          	        cout<<"Nhap vao ten khach hang khach hang mua xe tra ngay: ";
          	        cin>>hd[i].kh.tenkhachhang;
          	        cout<<"Nhap vao so luong loai xe khach hang mua xe tra ngay:";
          	        cin>>hd[i].loaixe;
          	        for(int j=0;j<hd[i].loaixe;j++){
          			cout<<"\t\tXe thu "<<j+1<<endl;
          			nhapxe(hd[i].x[j]);
				  }
				  }	  	
	           }else if(luachon==2){
	           	char a[30];
	           	int dem=0;
	           	cout<<"Nhap ma hoa don ban ngay can dieu chinh: ";
	           	cin>>a;
	           	for(int i=0;i<z;i++){
	           		if(strcmp(hd[i].mahd,a)==0){
	           		    dem++;
	           		    cout<<"Nhap vao ten khach hang can sua: ";
                     	cin>>hd[i].kh.tenkhachhang;
                        cout<<"Nhap vao ngay lap hoa don mua xe tra ngay can chinh sua: ";
          	            cin>>hd[i].ngaylaphd;
                       	cout<<"\tDa sua thanh cong.\n";
					   }
				   }
				if(dem==0) cout<<"Khong tim thay ma xe ma ban can dieu chinh trong danh sach xe.\n";
			   }
			   else if(luachon==3){
			  	for(int i=0;i<z;i++){
          	    	cout<<"\tThong tin don dat hang ban xe tra ngay thu "<<i+1<<endl;
          	    	cout<<"Ma hoa don: "<<hd[i].mahd<<endl;
                    cout<<"Ngay lap hd" <<hd[i].ngaylaphd<<endl;
          	        cout<<"Ten nhan vien: "<<hd[i].nv.tennhanvien<<endl;
                    cout<<"Ma khach hang: "<<hd[i].kh.makhachhang<<endl;
                    cout<<"Ten khach hang: "<<hd[i].kh.makhachhang<<endl;
          	        cout<<"Nhap vao ma khach hang: "<<hd[i].kh.tenkhachhang<<endl;
          	        for(int j=0;j<hd[i].loaixe;j++){
			  		cout<<"\t\tXe thu "<<j+1<<endl;
			  		xuatxe(hd[i].x[j]);
				  }
				  }	
			  }
			   
		       else if(luachon==4){
			  	cout<<"Cam on ban da su dung chuong trinh!!!\n";
			  	break;
			  }	else{
	                cout<<"Ban da nhap sai.Vui long nhap lai\n";
              }
		}
}
void theoDoiQuaTrinhTraGop(){
	cout<<"\t\t\tChao ban den voi chuc nang qua trinh tinh tien ve mua xe tra gop.\n";
	long giaxe,tratruoc,duno,tienlai;
	float laixuat;
	int kyhan;
	cout<<"Nhap vao gia xe: ";
	cin>>giaxe;
	cout<<"Nhap vao so tien khach hang da tra truoc: ";
	cin>>tratruoc;
	cout<<"Chon ky han bang cach nhap 1 hoac 2 hoac 3\n1.6 thang\n2.1 nam\n3.3 nam\n";
	while(true){
		cin>>kyhan;
		if(kyhan>3||kyhan<1) cout<<"Ban da nhap sai!! Vui long nhap ky han trong khoang 1->3\n";
		else{
			if(kyhan==1) kyhan=6;
			else if(kyhan==2) kyhan=12;
			else if(kyhan==3) kyhan=36;
			break;
		};
	}
	cout<<"Nhap vao lai xuat: ";
	cin>>laixuat;
	duno=giaxe-tratruoc;
	tienlai=duno*laixuat;
	long tiengoclai=duno/kyhan;
	cout<<"\tTien goc khach phai tra hang thang la: "<<tiengoclai<<endl;
	cout<<"Ky\t\t\t"<<"Du no\t\t\t"<<"Tien lai\t\t\t"<<"Goc + lai\n";
	for(int i=1;i<=kyhan;i++){
	cout<<i<<"\t\t\t"<<duno<<"\t\t"<<tienlai<<"\t\t\t"<<tiengoclai+tienlai<<endl;
	duno=duno-tiengoclai;
	tienlai=duno*((float)laixuat/100)	;
	}
}
void menu4(khachhang kh[],int c){
	int luachon,loaixe=0;
	    while(true){
	    	cout<< "=================MENU================\n";
	    		cout<<"\t BAN DA CHON SO 4\n";
	    	cout<< "\t 1.1 Nhap thong tin khach hang mua xe tra gop\n";
	        cout<< "\t 1.2 Dieu chinh thong tin khach hang mua xe tra gop\n";
	        cout<< "\t 1.3 Liet ke thong tin khach hang mua xe tra gop\n";
	        cout<< "\t 1.4 Ket thuc chuong trinh!!!.";
	        cout<< "=====================================\n";
           	cout<<"Nhap vao lua chon(1->4): ";
          	cin>>luachon;
          	if(luachon==1){
          		cout<<"Nhap vao so luong khach hang mua xe tra gop: ";
          		cin>>c;
          		for(int i=0;i<c;i++){
          		cout<<"\tKhach hang thu "<<i+1<<endl;
          		cout<<"Nhap vao ma khach hang: ";
          	   cin>>kh[i].makhachhang;
          	    cout<<"Nhap vao ten khach hang: ";
          	   cin>>kh[i].tenkhachhang;
          	    cout<<"Nhap vao tinh trang tra gop luc mua xe(6 thang,1 nam,3 nam): ";
          	    cin>>kh[i].tinhtrangmuaxe;
				}
	           }else if(luachon==2){
	           	char a[30];
	           	int dem=0;
	           	cout<<"Nhap ma khach hang can dieu chinh: ";
	           	cin>>a;
	           	for(int i=0;i<c;i++){
	           		if(strcmp(kh[i].makhachhang,a)==0){
	           		    dem++;
	           		    cout<<"Nhap vao ten khach hang can sua: ";
                     cin>>kh[i].tenkhachhang;
                    	cout<<"Nhap vao tinh trang mua xe tra gop can sua: ";
                      	cin>>kh[i].tinhtrangmuaxe;
                       	cout<<"\tDa sua thanh cong.\n";
					   }
				   }
				if(dem==0) cout<<"Khong tim thay ma xe ma ban can dieu chinh trong danh sach xe.\n";
			   }
			   else if(luachon==3){
			  	for(int i=0;i<c;i++){
			  	cout<<"\tKhach hang thu "<<i+1<<endl;
			  	cout<<"Ma khach hang la: "<<kh[i].makhachhang<<endl;
          	    cout<<"Ten khach hang la: "<<kh[i].tenkhachhang<<endl;
                cout<<"Tinh tran mua xe tra gop(6 thang,1 nam,3 nam): "<<kh[i].tinhtrangmuaxe<<endl;
				}
			  }
		       else if(luachon==4){
			  	cout<<"Cam on ban da su dung chuong trinh!!!\n";
			  	break;
			  }	else{
	                cout<<"Ban da nhap sai.Vui long nhap lai\n";
              }
		}
}
void menu(kho &k,int &n,hoadon hd[],int &m,int &z,khachhang kh[],int c){
	int luachon;
	    while(true){
	    	cout<< "=================MENU================\n";
	    	cout<< "\t 1. Nhap,dieu chinh va liet ke thong tin xe trong kho\n";
	        cout<< "\t 2. Nhap,dieu chinh va liet ke thong tin cac don dat hang\n";
	        cout<< "\t 3. Nhap,dieu chinh va liet ke thong tin cac dot dat hang ban xe tra ngay\n";
	        cout<< "\t 4. Nhap,dieu chinh va liet ke thong tin cac khach hang mua xe tra gop\n";
	        cout<< "\t 5. Theo doi qua trinh mua xe tra gop\n";
	        cout<< "\t 6. Lap bao cao\n";
	        cout<< "\t 7. Ket thuc chuong trinh!!!.\n";
	        cout<< "=====================================\n";
           	cout<<"Nhap vao lua chon(1->7): ";
          	cin>>luachon;
          	if(luachon==1){
          		menu1(k,n);
	           }else if(luachon==2){
			   menu2(hd,m);
			   }else if(luachon==3){
			   	menu3(hd,z);

			   }else if(luachon==4){
			   	menu4(kh,c);
			   }
			   else if(luachon==5){
			   	theoDoiQuaTrinhTraGop();
			   }
		       else if(luachon==7){
			  	cout<<"Cam on ban da su dung chuong trinh!!!\n";
			  	break;
			  }	else{
	                cout<<"Ban da nhap sai.Vui long nhap lai\n";
              }
		}	
}
void BaoCao(char *TenF, xe x[], int n){
    xe l[100];
    ofstream f(TenF, ios::binary | ios::out);
    f<<" Danh sach nhap xe theo tung hop dong:"<<endl;
    for (int i=0; i<n; i++)
    cout<<"|"<<l[i].maxe<<"       "<<l[i].tenxe<<"      "<<l[i].gia<<"        "<<l[i].soluong<<endl;
    fstream tenF;
    tenF.open("input.txt", ios::in);
	f.close();
}
int main() {
	kho k;
	int n,m,z,c;
	hoadon hd[200];
	khachhang kh[200];
	menu(k,n,hd,m,z,kh,c);
    fstream(file )
	return 0;
}