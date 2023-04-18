import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class OE2 extends Frame implements ActionListener, MouseListener, WindowListener{
  JTextField tf;
  JButton add1, add2, rem1, rem2, next, back;
  List l1, l2;
  int index1=-1, index2=-1;
  OE2(){
    JFrame f=new JFrame("Grid Calculator Example");
    tf=new JTextField("Add your hobby here");
    tf.setBounds(150, 20, 300, 30);
    add1=new JButton("add to list 1");
    add1.setBounds(80, 70, 150, 30);
    add2=new JButton("add to list 2");
    add2.setBounds(430, 70, 150, 30);
    l1=new List(10, true);
    l1.setBounds(30, 130, 250, 330);
    l2=new List(10, true);
    l2.setBounds(380, 130, 250, 330);
    next=new JButton(">>");
    next.setBounds(300, 180, 50, 50);
    back=new JButton("<<");
    back.setBounds(300, 250, 50, 50);
    rem1=new JButton("remove from list 1");
    rem1.setBounds(80, 500, 150, 50);
    rem2=new JButton("remove from list 2");
    rem2.setBounds(430, 500, 150, 50);
    f.setSize(680, 800);
    f.setLayout(null);
    f.setVisible(true);
    //add listeners
    f.add(tf);
    f.add(add1);
    f.add(add2);
    f.add(l1);
    f.add(l2);
    f.add(next);
    f.add(back);
    f.add(rem1);
    f.add(rem2);
    //add components
    tf.addMouseListener(this);
    //l1.addListSelectionListener();
    //l2.addListSelectionListener();
    add1.addActionListener(this);
    add2.addActionListener(this);
    rem1.addActionListener(this);
    rem2.addActionListener(this);
    next.addActionListener(this);
    back.addActionListener(this);
    f.addWindowListener(this);
  }
  public void windowDeactivated(WindowEvent e) {}
  public void windowDeiconified(WindowEvent e) {}
  public void windowIconified(WindowEvent e) {}
  public void windowOpened(WindowEvent e) {}
  public void windowActivated(WindowEvent e) {}
  public void windowClosed(WindowEvent e) {}
  public void windowClosing(WindowEvent e){
    System.exit(0);
 }
  public void mouseClicked(MouseEvent e){
    tf.setText("");
  }
  public void mouseEntered(MouseEvent e){}
  public void mouseExited(MouseEvent e){}
  public void mousePressed(MouseEvent e){}
  public void mouseReleased(MouseEvent e){}

  public void actionPerformed(ActionEvent e){
    if(e.getSource()==add1){
      l1.add(tf.getText());
      tf.setText("Add your hobby here");
      index1++;
    }
    else if(e.getSource()==add2){
      l2.add(tf.getText());
      tf.setText("Add your hobby here");
      index2++;
    }
    else if(e.getSource()==rem1){
      l1.remove(index1);
      index1--;;
    }
    else if(e.getSource()==rem2){
      l2.remove(index2);
      index2--;
    }
    else if(e.getSource()==next){
      l2.add(l1.getItem(index1));
      l1.remove(index1);
      index1--;
      index2++;
    }
    else if(e.getSource()==back){
      l1.add(l2.getItem(index2));
      l2.remove(index2);
      index2--;
      index1++;
    }
  }
  public static void main(String agrs[]){
    new OE2();
  }
}
