package cliente;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import servidor.Servidor;


public class GUI {

	private Cliente client;
	private Servidor server;
	
	public void doConnect() throws SQLException, MalformedURLException, NotBoundException {
		if(login.getText().equals("Login")) {
			if(user.getText().length()==0) {
				JOptionPane.showMessageDialog(frame, "Informe o username para Login!");
				return;
			}
			if(pass.getText().length()==0) {
				JOptionPane.showMessageDialog(frame, "Informe a senha para Login!");
				return;
			}
			try {
				client = new Cliente(user.getText(), pass.getText());
				client.setGUI(this);
				server = (Servidor)Naming.lookup("rmi://localhost/twitter");
				server.login(client);
			}catch(java.rmi.RemoteException e) {
				e.printStackTrace();
				JOptionPane.showMessageDialog(frame, "ERROR, não foi possivel conectar....");
			}
		}
		
		JOptionPane.showMessageDialog(frame, "OK");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GUI c=new GUI();
	}
	public GUI() {
		frame = new JFrame("Twitter");
		
		JPanel main =new JPanel();
		JPanel top = new JPanel();
		JPanel cn =new JPanel();
	    JPanel bottom =new JPanel();
		
		user = new JTextField();
		pass = new JPasswordField();
		login = new JButton("Login");
		
		tf = new JTextField();
		tx = new JTextArea();
		JButton bt = new JButton("Twittar");
		lst = new JList();
		
		main.setLayout(new BorderLayout(5,5));
		
		top.setLayout(new GridLayout(1,0,5,5));
		top.add(new JLabel("Username"));top.add(user);
		top.add(new JLabel("Password")); top.add(pass);
		top.add(login);
		main.add(top, BorderLayout.NORTH);
		
		cn.setLayout(new BorderLayout(5,5));
		cn.add(new JScrollPane(tx), BorderLayout.CENTER);        
	    cn.add(lst, BorderLayout.EAST);  
	    main.add(cn, BorderLayout.CENTER);
	    
	    bottom.setLayout(new BorderLayout(5,5));
	    bottom.add(tf, BorderLayout.CENTER);    
	    bottom.add(bt, BorderLayout.EAST);
	    main.add(bottom, BorderLayout.SOUTH);
	    
	    main.setBorder(new EmptyBorder(10, 10, 10, 10) );
	    
	    //eventos
	    
	    login.addActionListener(new ActionListener() {
	    	public void actionPerformed(ActionEvent e) {
	    		try {
					doConnect();
				} catch (MalformedURLException | SQLException | NotBoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
	    	}
	    });
		
		frame.setContentPane(main);
	    frame.setSize(600,600);
	    frame.setVisible(true);  
	}
		
	JTextArea tx;
	JTextField tf,pass, user;
	JButton login;
	JList lst;
	JFrame frame;
	
}

