import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class gridCalc extends Frame implements WindowListener, ActionListener{
  JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, add, sub, mul, div, clear, equal;
  JTextField tf, tf1;
  JPanel p1, p2;
  int flag=0, fn=0;
  String temp="", temp1="", num1="", num2="", func="";
  gridCalc(){
    //declaring containers and their size
    JFrame f=new JFrame("Grid Calculator Example");
    p1=new JPanel();
    p1.setBounds(10, 10, 740, 200);
    p2=new JPanel();
    p2.setBounds(10, 210, 510, 400);
    tf=new JTextField("0");
    tf.setBounds(300, 60, 210, 100);
    tf.setEditable(false);
    tf1=new JTextField("0");
    tf1.setBounds(400, 15, 110, 40);
    tf1.setEditable(false);
    b1=new JButton("1");
    b2=new JButton("2");
    b3=new JButton("3");
    b4=new JButton("4");
    b5=new JButton("5");
    b6=new JButton("6");
    b7=new JButton("7");
    b8=new JButton("8");
    b9=new JButton("9");
    b0=new JButton("0");
    add=new JButton("+");
    sub=new JButton("-");
    mul=new JButton("*");
    div=new JButton("/");
    clear=new JButton("CE");
    equal=new JButton("=");
    tf.setFont(new Font("Verdana", Font.PLAIN, 25));
    b0.setFont(new Font("Verdana", Font.PLAIN, 20));
    b1.setFont(new Font("Verdana", Font.PLAIN, 20));
    b2.setFont(new Font("Verdana", Font.PLAIN, 20));
    b3.setFont(new Font("Verdana", Font.PLAIN, 20));
    b4.setFont(new Font("Verdana", Font.PLAIN, 20));
    b5.setFont(new Font("Verdana", Font.PLAIN, 20));
    b6.setFont(new Font("Verdana", Font.PLAIN, 20));
    b7.setFont(new Font("Verdana", Font.PLAIN, 20));
    b8.setFont(new Font("Verdana", Font.PLAIN, 20));
    b9.setFont(new Font("Verdana", Font.PLAIN, 20));
    add.setFont(new Font("Verdana", Font.PLAIN, 20));
    sub.setFont(new Font("Verdana", Font.PLAIN, 20));
    mul.setFont(new Font("Verdana", Font.PLAIN, 20));
    div.setFont(new Font("Verdana", Font.PLAIN, 20));
    clear.setFont(new Font("Verdana", Font.PLAIN, 20));
    equal.setFont(new Font("Verdana", Font.PLAIN, 20));
    p1.setBackground(Color.getHSBColor(170,157,190));
    equal.setBackground(Color.getHSBColor(170,187,180));
    p1.setLayout(null);
    p2.setLayout(new GridLayout(4,4,10,10));
    f.setSize(545,655);
    f.setLayout(null);
    f.setVisible(true);
    //add listeners
    tf.addActionListener(this);
    tf1.addActionListener(this);
    b0.addActionListener(this);
    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
    b4.addActionListener(this);
    b5.addActionListener(this);
    b6.addActionListener(this);
    b7.addActionListener(this);
    b8.addActionListener(this);
    b9.addActionListener(this);
    add.addActionListener(this);
    sub.addActionListener(this);
    mul.addActionListener(this);
    div.addActionListener(this);
    clear.addActionListener(this);
    equal.addActionListener(this);
    f.addWindowListener(this);
    //add conmponents in containers
    p1.add(tf);
    p1.add(tf1);
    p2.add(b1);
    p2.add(b2);
    p2.add(b3);
    p2.add(add);
    p2.add(b4);
    p2.add(b5);
    p2.add(b6);
    p2.add(sub);
    p2.add(b7);
    p2.add(b8);
    p2.add(b9);
    p2.add(mul);
    p2.add(clear);
    p2.add(b0);
    p2.add(equal);
    p2.add(div);
    f.add(p1);
    f.add(p2);
  }
  //events
  public void windowDeactivated(WindowEvent e) {}
  public void windowDeiconified(WindowEvent e) {}
  public void windowIconified(WindowEvent e) {}
  public void windowOpened(WindowEvent e) {}
  public void windowActivated(WindowEvent e) {}
  public void windowClosed(WindowEvent e) {}
  public void windowClosing(WindowEvent e){
    System.exit(0);
 }
 public void actionPerformed(ActionEvent e){
   if(flag==0){
     if(e.getSource()==b0)
       temp="0";
     else if(e.getSource()==b1)
       temp="1";
     else if(e.getSource()==b2)
       temp="2";
     else if(e.getSource()==b3)
       temp="3";
     else if(e.getSource()==b4)
       temp="4";
     else if(e.getSource()==b5)
       temp="5";
     else if(e.getSource()==b6)
       temp="6";
     else if(e.getSource()==b7)
       temp="7";
     else if(e.getSource()==b8)
       temp="8";
     else if(e.getSource()==b9)
       temp="9";
     else if(e.getSource()==add){
       func="+";
       fn=1;
       flag=1;
       tf1.setText(num1+func);
     }
     else if(e.getSource()==sub){
       func="-";
       fn=2;
       flag=1;
       tf1.setText(num1+func);
     }
     else if(e.getSource()==mul){
       func="*";
       fn=3;
       flag=1;
       tf1.setText(num1+func);
     }
     else if(e.getSource()==div){
       func="/";
       fn=4;
       flag=1;
       tf1.setText(num1+func);
     }

     if(fn==0){
       num1=num1+temp;
       tf.setText(num1);
       tf1.setText(num1);
     }
   }
   else if(flag==1){
     if(e.getSource()==b0)
       temp1="0";
     else if(e.getSource()==b1)
       temp1="1";
     else if(e.getSource()==b2)
       temp1="2";
     else if(e.getSource()==b3)
       temp1="3";
     else if(e.getSource()==b4)
       temp1="4";
     else if(e.getSource()==b5)
       temp1="5";
     else if(e.getSource()==b6)
       temp1="6";
     else if(e.getSource()==b7)
       temp1="7";
     else if(e.getSource()==b8)
       temp1="8";
     else if(e.getSource()==b9)
       temp1="9";
     else if(e.getSource()==equal){
       float a=Float.parseFloat(num1);
       float b=Float.parseFloat(num2);
       float c=0;
       if(fn==1){
         c=a+b;
       }
       else if(fn==2){
         c=a-b;
       }
       else if(fn==3){
         c=a*b;
       }
       else if(fn==4){
         try{
           c=a/b;
         }catch(ArithmeticException ae){}
       }
       tf.setText(String.valueOf(c));
       fn=0;
       flag=2;
     }
     if(fn!=0){
      num2=num2+temp1;
     }
    tf1.setText(num1+func+num2);
   }
   else if(flag==2 && e.getSource()==clear){
       num1="";
       num2="";
       tf.setText("0");
       tf1.setText("0");
       flag=0;
     }
   }
    //main function
     public static void main(String args[]){
       new gridCalc();
     }
}
