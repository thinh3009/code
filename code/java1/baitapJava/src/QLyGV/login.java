package QLyGV;

import java.awt.*;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class login extends JFrame {
	login(){
		//giao dien use va password
		getContentPane().setBackground(Color.white);
		setLayout(null);
		
		JLabel LbUserName= new JLabel("Use name");
		LbUserName.setBounds(40, 20, 100, 30);
		add(LbUserName);
		
		JTextField txtUser= new JTextField();
		txtUser.setBounds(150,20,150,30);
		add(txtUser);
		
		JTextField txtPass= new JTextField();
		txtPass.setBounds(150,70,150,30);
		add(txtPass);
		
		JButton login = new JButton("LOGIN");
		login.setBounds(150, 140, 150, 30);
		add(login); 
		
		JLabel LbPassword= new JLabel("Password");
		LbPassword.setBounds(40, 70, 100, 30);
		add(LbPassword);
		
		setSize(600,300);
		setLocation(450,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new login();
	}
}
