
package quanligiangvien;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.sql.*;
public class UpdateGV extends JFrame implements ActionListener{
    
     JTextField cbeducation,namegv, subject, tfphone, tfemail, addr;
      //JDateChooser dcdob;
   // JComboBox cbeducation;
    JLabel lblempId;
    JButton add, back;
    String id;
    UpdateGV(String id){
        this.id=id;
        getContentPane().setBackground(Color.WHITE);
        setLayout(null);
        
        JLabel heading=new JLabel("Cập Nhật Giảng Viên");
        heading.setBounds(320,30,500,50);
       heading.setFont(new Font("SAN_SERIF", Font.BOLD, 25));
        add(heading);
        
         JLabel labelempId = new JLabel("Mã Giảng Viên");
        labelempId.setBounds(50, 150, 150, 30);
        labelempId.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelempId);
        
        lblempId = new JLabel();
        lblempId.setBounds(200, 150, 150, 30);
        lblempId.setFont(new Font("serif", Font.PLAIN, 20));
        add(lblempId);
        
        JLabel labelname = new JLabel("Tên Giảng Viên");
        labelname.setBounds(400, 150, 150, 30);
        labelname.setFont(new Font("serif", Font.PLAIN, 20));
        add(labelname);
        
        JLabel lblname = new JLabel();
        lblname.setBounds(600, 150, 150, 30);
        add(lblname);
        
        JLabel labeldob = new JLabel("Ngày sinh");
        labeldob.setBounds(50, 200, 150, 30);
        labeldob.setFont(new Font("serif", Font.PLAIN, 20));
        add(labeldob);
        
        JLabel lbldob = new JLabel();
        lbldob.setBounds(200, 200, 150, 30);
        add(lbldob);
        
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
        
        JLabel lblnum = new JLabel();
        lblnum.setBounds(600, 250, 150, 30);
        add(lblnum);
        
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
        
       // String courses[] = {"CNTT", "Kinh Tế Vận tải", "Điện-DTVT", "Cơ Khí", "Viện Hàng Hải", "Viện Đào Tạo CLC", "KTXD", "Khai khác vận tải", "Kỹ thuật điều khiển-TDH", "Công Trình Giao Thông"};
        cbeducation = new JTextField();
       // cbeducation.setBackground(Color.WHITE);
        cbeducation.setBounds(600, 300, 150, 30);
        add(cbeducation);
        
      try{
          Conn c=new Conn();
          String query ="select * from GiangVien where id='"+id+"'";
        ResultSet rs=  c.s.executeQuery(query);
        while(rs.next()){
            lblname.setText(rs.getString("name"));
            lbldob.setText(rs.getString("dob"));
            addr.setText(rs.getString("addrr"));
            subject.setText(rs.getString("sub"));
            lblnum.setText(rs.getString("phone"));
            tfemail.setText(rs.getString("email"));
            cbeducation.setText(rs.getString("dep"));
            
            
        }
      }catch(Exception e){
          e.printStackTrace();
      }
        
       
        
        add = new JButton("Cập Nhật Giảng Viên");
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
          //  String id = lblempId.getText();
            String name=namegv.getText();
            //String dob = ((JTextField) dcdob.getDateEditor().getUiComponent()).getText();
            String addrr = addr.getText();
            String sub = subject.getText();
            String phone = tfphone.getText();
            String email = tfemail.getText();
            String dep = cbeducation.getText();
           
            
            try{
                Conn conn=new Conn();
                String query = "update GiangVien set name = '"+name+"', addrr = '"+addrr+"', sub = '"+sub+"', phone = '"+phone+"', email =  '"+email+"', dep = '"+dep+"' where empId = '"+id+"'";
                conn.s.executeUpdate(query);
                JOptionPane.showMessageDialog(null,"Cập nhật thành công");
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
        new UpdateGV("");
    }
}
