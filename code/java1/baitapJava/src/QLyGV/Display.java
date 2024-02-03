package QLyGV;
import QLyGV.login;
import java.awt.Color;
import java.awt.Font;
//import java.awt.Image;
import java.awt.event.*;
import javax.swing.*;

//hien thi giao dien
public class Display extends JFrame implements ActionListener {
	//chinh kich thuoc
	Display(){
		
		getContentPane().setBackground(Color.WHITE);
		setLayout(null);
		//font chu
		JLabel heading = new JLabel("WELCOME TO LECTURERS MANAGERMENT SYSTEM") ;
		heading.setBounds(80,30,1200,60);
		heading.setFont(new Font("serif: ",Font.PLAIN,40));
		heading.setForeground(Color.RED);
		add(heading);
		
		//them anh vao 
//		ImageIcon i1= new ImageIcon(ClassLoader.getSystemResource("icons/background.ico"));
//		Image i2 = i1.getImage().getScaledInstance(1100, 700, Image.SCALE_DEFAULT);
//		ImageIcon i3= new ImageIcon(i2);
//		
//		JLabel image =new JLabel(i3);
//		image.setBounds(50, 100, 1050, 500);
//		add(image);
		
		//BUTTON CLICK
		JButton click = new JButton("CLICK HERE TO COUNTINUTE");
		click.setBounds(400, 400, 300, 70);
		//ket noi login
		click.addActionListener(this);
		add(click); 
		
		setSize(1170, 650);
		setLocation(200, 50);
		setVisible(true);

	}
	

	public void actionPerfomed(ActionEvent ae) {
		setVisible(false);
		new login();
		
	}
	public static void main(String[] args) {
		new Display();
		
	}

	

	
}