
package quanligiangvien;
import java.awt.*;
import javax.swing.*;
import com.toedter.calendar.JDateChooser;
import java.util.*;
import java.awt.event.*;
public class AddGV extends JFrame implements ActionListener{
    Random ran = new Random();
    int number = ran.nextInt(9999);
    
     JTextField namegv, subject, tfphone, tfemail, addr;
      JDateChooser dcdob;
    JComboBox cbeducation;
    JLabel lblempId;
    JButton add, back;
    
    AddGV(){
        getContentPane().setBackground(Color.WHITE);
        setLayout(null);
        
        JLabel heading=new JLabel("Thêm Giảng Viên");
        heading.setBounds(320,30,500,50);
       heading.setFont(new Font("SAN_SERIF", Font.BOLD, 25));
        add(heading);
        
         JLabel labelempId = new JLabel("Mã Giảng Viên");
        labelempId.setBounds(50, 150, 150, 30);
        labelempId.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelempId);
        
        lblempId = new JLabel("" + number);
        lblempId.setBounds(200, 150, 150, 30);
        lblempId.setFont(new Font("serif", Font.PLAIN, 20));
        add(lblempId);
        
        JLabel labelname = new JLabel("Tên Giảng Viên");
        labelname.setBounds(400, 150, 150, 30);
        labelname.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelname);
        
        namegv = new JTextField();
        namegv.setBounds(600, 150, 150, 30);
        add(namegv);
        
        JLabel labeldob = new JLabel("Ngày sinh");
        labeldob.setBounds(50, 200, 150, 30);
        labeldob.setFont(new Font("serif", Font.PLAIN, 20));
        add(labeldob);
        
        dcdob = new JDateChooser();
        dcdob.setBounds(200, 200, 150, 30);
        add(dcdob);
        
        JLabel labelAdd = new JLabel("Địa chỉ");
        labelAdd.setBounds(400, 200, 150, 30);
        labelAdd.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelAdd);
        
        addr = new JTextField();
        addr.setBounds(600, 200, 150, 30);
        add(addr);
        
        JLabel labelsub = new JLabel("Môn Dạy");
        labelsub.setBounds(50, 250, 150, 30);
        labelsub.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelsub);
        
        subject = new JTextField();
        subject.setBounds(200, 250, 150, 30);
        add(subject);
        
        JLabel labelphone = new JLabel("Số điện thoại");
        labelphone.setBounds(400, 250, 150, 30);
        labelphone.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelphone);
        
        tfphone = new JTextField();
        tfphone.setBounds(600, 250, 150, 30);
        add(tfphone);
        
        JLabel labelemail = new JLabel("Email");
        labelemail.setBounds(50, 300, 150, 30);
        labelemail.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelemail);
        
        tfemail = new JTextField();
        tfemail.setBounds(200, 300, 150, 30);
        add(tfemail);
        
         JLabel labeleducation = new JLabel("Khoa");
        labeleducation.setBounds(400, 300, 150, 30);
        labeleducation.setFont(new Font("serif", Font.PLAIN, 20));
        add(labeleducation);
        
        String courses[] = {"CNTT", "Kinh Tế Vận tải", "Điện-DTVT", "Cơ Khí", "Viện Hàng Hải", "Viện Đào Tạo CLC", "KTXD", "Khai khác vận tải", "Kỹ thuật điều khiển-TDH", "Công Trình Giao Thông"};
        cbeducation = new JComboBox(courses);
        cbeducation.setBackground(Color.WHITE);
        cbeducation.setBounds(600, 300, 150, 30);
        add(cbeducation);
        
      
        
       
        
        add = new JButton("Thêm Giảng Viên");
        add.setBounds(250, 550, 150, 40);
        add.addActionListener(this);
        add.setBackground(Color.BLACK);
        add.setForeground(Color.WHITE);
        add(add);
        
        back = new JButton("Back");
        back.setBounds(450, 550, 150, 40);
        back.addActionListener(this);
        back.setBackground(Color.BLACK);
        back.setForeground(Color.WHITE);
        add(back);
        
        setSize(900,700);
        setLocation(300,50);
        setVisible(true);
    }
    
    public void actionPerformed(ActionEvent ae){
        if(ae.getSource()==add){
            String id = lblempId.getText();
            String name=namegv.getText();
            String dob = ((JTextField) dcdob.getDateEditor().getUiComponent()).getText();
            String addrr = addr.getText();
            String sub = subject.getText();
            String phone = tfphone.getText();
            String email = tfemail.getText();
            String dep = (String) cbeducation.getSelectedItem();
           
            
            try{
                Conn conn=new Conn();
                String query="insert into GiangVien values('"+id+"','"+name+"','"+dob+"','"+addrr+"','"+sub+"','"+phone+"','"+email+"','"+dep+"')";
                conn.s.executeUpdate(query);
                JOptionPane.showMessageDialog(null,"Thêm giảng viên thành công");
                setVisible(false);
                new Home();
            }catch (Exception e){
                e.printStackTrace();
            }
        }else{
            setVisible(false);
            new Home();
        }
    }
    
    
    public static void main(String [] args){
        new AddGV();
    }
}
