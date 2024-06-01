import java.io.File;
import java.util.Scanner;

public class MainarrayList {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        //tao constructor rong de nhap du lieu
        arrayListdsSV dssv= new arrayListdsSV();
        int luaChon=0;
        do {
			System.out.println("MENU ---------- ");
			System.out.println("Vui lòng chọn chức năng: ");
			System.out.println(
			  "1.	Thêm sinh viên vào danh sách.\n"
			+ "2.	In danh sách sinh viên ra màn hình.\n"
			+ "3.	Kiểm tra danh sách có rỗng hay không.\n"
			+ "4.	Lấy ra số lượng sinh viên trong danh sách.\n"
			+ "5.	Làm rỗng danh sách sinh viên.\n"
			+ "6.	Kiểm tra sinh viên có tồn tại trong danh sách hay không, dựa trên mã sinh viên.\n"
			+ "7.	Xóa một sinh viên ra khỏi danh sách dựa trên mã sinh viên.\n"
			+ "8.	Tìm kiếm tất cả sinh viên dựa trên Tên được nhập từ bàn phím.\n"
			+ "9.	Xuất ra danh sách sinh viên có điểm từ cao đến thấp.\n"
            + "10.	ghi du lieu vao file dat.\n"
            + "11.	doc danh sach sinh vien tu file dat.\n"
			+ "0.   Thoát khỏi chương trình");
			luaChon = sc.nextInt();
            sc.nextLine();
            if(luaChon==1){
                System.out.println("nhap ma sv: "); String masv=sc.nextLine();
                System.out.println("nhap ho ten: "); String hoten=sc.nextLine();
                System.out.println("nhap nam sinh: "); int namsinh=sc.nextInt();
                System.out.println("nhap diem tb: "); float diemtb=sc.nextFloat();
                arrayListSV sv = new arrayListSV(masv, hoten, namsinh, diemtb);
                dssv.themSV(sv);
            }
            else if(luaChon==2){
                dssv.inDS();
            }
            else if(luaChon==3){

            }
            else if(luaChon==4){

            }
            else if(luaChon==5){

            }
            else if(luaChon==6){

            }
            else if(luaChon==7){

            }
            else if(luaChon==8){

            }
            else if(luaChon==9){

            }
            else if(luaChon==10){
                System.out.println("nhap ten file: ");
                String tenFile=sc.nextLine();
                File f=new File(tenFile);
                dssv.ghiFile(f);
            }
            else if(luaChon==11){
                System.out.println("nhap ten file: ");
                String tenFile=sc.nextLine();
                File f=new File(tenFile);
                dssv.docFile(f);
            }
        }
        while(luaChon!=0);

        
    }
}
