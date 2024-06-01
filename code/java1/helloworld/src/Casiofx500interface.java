import javax.swing.text.html.HTMLDocument.RunElement;

//implements: hien thuc hoa
public class Casiofx500interface implements MayTinhbotuiinterface {

    @Override
    public double cong(double a, double b) {
        // TODO Auto-generated method stub
        return a+b;
    }

    @Override
    public double tru(double a, double b) {
        // TODO Auto-generated method stub
        return a-b;
    }

    @Override
    public double nhan(double a, double b) {
        // TODO Auto-generated method stub
        return a*b;
    }

    @Override
    public double chia(double a, double b) {
        //TODO Auto-generated method stub
        try {
            if(b==0){
                System.out.println("a khong chia dc cho 0!");
            }
            else{
                return a/b;
            }
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("a khong chia duoc cho 0");
        }
        System.out.println("nhap sai vui long nhap lai!!"); 
        return a/b;
    }

    
}
