import java.awt.event.*;  
import javax.swing.*;    
public class Swings{  
public static void main(String[] args) {  
    JFrame f=new JFrame("Counter");  
    final JTextField tf=new JTextField();  
    tf.setBounds(120,50, 60,20);  
	JLabel l1 = new JLabel("Counter");
	l1.setBounds(50, 50, 150, 20);
    JButton b=new JButton("Count");  
    b.setBounds(200,50,95,30);  
    b.addActionListener(new ActionListener(){ 
		int count = 0; 
		public void actionPerformed(ActionEvent e){  
			count+=6;
			String s = String.valueOf(count);
            tf.setText(s);  
        }  
    });  
    f.add(b);f.add(tf); f.add(l1);
    f.setSize(400,200);  
    f.setLayout(null);  
    f.setVisible(true);   
}  
}
