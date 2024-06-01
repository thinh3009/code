// import javax.swing.*;
// import java.awt .event. *;
// import java.awt.*; 

// public class App extends JFrame implements ActionListener { 
	
// 	/*Dùng để biểu diễn 4 nút của 4 phép toán +, -, *, / */
// 	private JButton bt1, bt2, bt3, bt4;
// 	/*Dùng để chứa 2 số và 1 kết quả*/
// 	private JTextField tf1, tf2, tf3;
// 	/*Dùng để lưu trữ kết quả tính toán*/
// 	private double result;
// 	/*Dùng để nhận tầng ContentPane của JFrame*/
// 	private Container cont;
// 	/*Dùng để nhóm các thành phần trên giao diện*/
// 	private JPanel panel1, panel2;

// 	/*Hàm khởi tạo*/
// 	public App(String s)
// 	{ 
// 		super(s);
// 		/*Lấy lớp ContentPane để đặt các đối tượng hiển thị*/
// 		cont = this.getContentPane(); 
		
// 		/*Tạo các thành phần trên giao diện*/
// 		JLabel num1lb = new JLabel("Num1: ");
// 		tf1 = new JTextField();
// 		JLabel num2lb = new JLabel("Num2: ");
// 		tf2 = new JTextField();
// 		JLabel resultlb = new JLabel("Result: ");
// 		tf3 = new JTextField();
// 		/*Textfield chứa kết quả không được phép sử dụng dữ liệu*/
// 		tf3.setEditable(false);
		
// 		/*Panel1 chứa 3 Textfield*/
// 		panel1 = new JPanel(); 
// 		/*thiết lập Layout gồm 3 hàng 2 cột*/
// 		panel1.setLayout(new GridLayout(3,2));
// 		/*Đặt các thành phần vào panel 1*/
// 		panel1.add(num1lb); 
// 		panel1.add(tf1); 
// 		panel1.add(num2lb); 
// 		panel1.add(tf2);
// 		panel1.add(resultlb);
// 		panel1.add(tf3);
// 		/*Tạo 4 nút biểu diễn 4 phép toán*/
// 		bt1 = new JButton("+");
// 		bt2= new JButton("-");
// 		bt3 = new JButton("*");
// 		bt4 = new JButton("/");
// 		/*Panel2 chứa 4 nút*/
// 		panel2 = new JPanel();
// 		panel2.add(bt1);
// 		panel2.add(bt2);
// 		panel2.add(bt3);
// 		panel2.add(bt4);
		
// 		/*Đặt 2 panel vào ContentPane*/
// 		cont.add(panel1); 
// 		cont.add(panel2,"South"); 
		
// 		bt1.addActionListener(this);
// 		bt2.addActionListener(this); 
// 		bt3.addActionListener(this); 
// 		bt4.addActionListener(this);
// 		/*Thiết lập kích thước hiển thị*/
// 		this.pack();
// 		this.setVisible(true);
// 	}

// 	/*Định nghĩa hàm cộng*/
// 	public void doPlus() 
// 	{ 
// 	   result = Double.parseDouble(tf1.getText()) + Double.parseDouble(tf2.getText()); 
// 	   tf3.setText(String.valueOf(result)); 
// 	}
// 	/*Định nghĩa hàm trừ*/
// 	public void doMinus() 
// 	{ 
// 		result = Double.parseDouble(tf1.getText()) - Double.parseDouble(tf2.getText());
// 		tf3.setText(String.valueOf(result));
// 	}
// 	/*Định nghĩa hàm nhân*/
// 	public void doMult() 
// 	{
// 		result = Double.parseDouble(tf1.getText()) * Double.parseDouble(tf2.getText());
// 		tf3.setText(String.valueOf(result)); 
// 	}
// 	/*Định nghĩa hàm chia*/
// 	public void doDiv()
// 	{
// 	    result = Double.parseDouble(tf1.getText()) / Double.parseDouble(tf2.getText());
// 	    tf3.setText(String.valueOf(result));
// 	} 
	
// 	/*Định nghĩ lại hàm xử lý khi người dùng ấn các nút phép toán*/
// 	public void actionPerformed(ActionEvent e) 
// 	{ 
// 		if (e.getActionCommand()=="+")
// 		doPlus();
// 		if (e.getActionCommand()=="-")
// 		doMinus();
// 		if (e.getActionCommand()=="*")
// 		doMult();
// 		if (e.getActionCommand()=="/")
// 		doDiv();
	
// 	}
	
// 	public static void main(String args[])
// 	{
// 		/*Tạo giao diện chương trình*/
// 		App simpleCalculator = new App("SimpleCalculator");
// 		simpleCalculator.setLocationRelativeTo(null);
// 	}
// }
import javax.swing.*;
public class App{
	public static void main(String args[]) {
		JFrame f = new JFrame("hi java");
		JButton b =new JButton("button1");
		JButton b2 = new JButton("button2");
		JButton b3 = new JButton("button3");
		JLabel l = new JLabel("Label1");
		JTextField t = new JTextField("text 1");
		//button1
		b.setBounds(10,200,100,40);//x,y,rong,cao
		f.add(b);//add button in Jframe
		f.setSize(400,500);
		f.setLayout(null);
		f.setVisible(true);//making the frame visible
		//button2
		b2.setBounds(130,200,100,40);//x,y,rong,cao
		f.add(b2);//add button in Jframe
		f.setSize(400,500);
		f.setLayout(null);
		f.setVisible(true);//making the frame visible
		//button3
		b3.setBounds(250,200,100,40);//x,y,rong,cao
		f.add(b3);//add button in Jframe
		f.setSize(400,500);
		f.setLayout(null);
		f.setVisible(true);//making the frame visible
		//label
		l.setBounds(10,100,100,40);
		f.add(l);
		f.setSize(400,500);
		f.setLayout(null);
		f.setVisible(true);
		//text 
		t.setBounds(90,100,100,40);
		f.add(t);
		f.setSize(400,500);
		f.setLayout(null);
		f.setVisible(true);

	}
}