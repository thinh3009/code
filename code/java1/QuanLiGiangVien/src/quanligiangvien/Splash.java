
package quanligiangvien;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Splash extends JFrame implements ActionListener {
    Splash(){
        getContentPane().setBackground(Color.WHITE);
        setLayout(null);
        //Tao tieu de he thong quan li giang vien
        JLabel heading=new JLabel("HỆ THỐNG QUẢN LÍ GIẢNG VIÊN");
        heading.setBounds(80,30,1200,60);
        heading.setFont(new Font("serif", Font.PLAIN,60));
        heading.setForeground(Color.RED);
        add(heading);
        //Xay dung background
        ImageIcon i1=new ImageIcon(ClassLoader.getSystemResource("icons/front.jpg"));
        Image i2=i1.getImage().getScaledInstance(1100, 700, Image.SCALE_DEFAULT);
        ImageIcon i3=new ImageIcon(i2);
        JLabel image=new JLabel(i3);
        image.setBounds(50,100,1050,500);
        add(image);
        
        
        //nut click continue
        JButton clickhere=new JButton("NHẤN ĐỂ TIẾP TỤC");
        clickhere.setBounds(400,400,300,70);
        clickhere.setBackground(Color.BLACK);
        clickhere.setForeground(Color.WHITE);
        clickhere.addActionListener(this);
        image.add(clickhere);
        
        //Tao khung
        setSize(1170,650);
        setLocation(200,50);
        setVisible(true);
        
        while(true){
            heading.setVisible(false);
            try{
                Thread.sleep(500);
            }catch (Exception e){
                
            }
            
            heading.setVisible(true);
             try{
                Thread.sleep(500);
            }catch (Exception e){
                
            }
        }
    }
    
    public void actionPerformed(ActionEvent ae){
        setVisible(false);
        new Login();
    }
    
    public static void main(String args[]){
        new Splash();
    }
}
