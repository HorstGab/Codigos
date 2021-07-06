package cliente;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.sql.SQLException;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import common.IServidor;


public class GUI {

	private Cliente client;
	private IServidor server;
	
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
				client.setUi(this);
				server = (IServidor)Naming.lookup("rmi://localhost/twitter");
				int status = server.login(client);
				if(status == 1) {
					JOptionPane.showMessageDialog(frame, "Login efetuado com sucesso!");
					timeline();
					u.setText(user.getText());
					login.setText("Logout");
					userB.setText(user.getText());
					user.setText(null);
					pass.setText(null);
				}else {
					if(status == -1)JOptionPane.showMessageDialog(frame, "Usuario ou senha Incorreto!");
					if(status == -2)JOptionPane.showMessageDialog(frame, "Usuario já logado!");
				}
				
			}catch(java.rmi.RemoteException e) {
				e.printStackTrace();
				JOptionPane.showMessageDialog(frame, "ERROR, não foi possivel conectar....");
			}
		}else {
			try {
				if(login.getText().equals("Logout")) {
					u.setText(null);
					tx.setText("");
					if(server.Desconnected(client.getName())) {
						JOptionPane.showMessageDialog(frame, "Usuario Deslogado!");
						login.setText("Login");
					}else {
						System.out.println("Erro para deslogar");
					}
				}
			}catch(java.rmi.RemoteException e) {
				e.printStackTrace();
				JOptionPane.showMessageDialog(frame, "ERROR, não foi possivel desconectar....");
			}
		}
		
		//JOptionPane.showMessageDialog(frame, "OK");
	}
	
	public void twittar() throws RemoteException, SQLException {
		if (login.getText().equals("Connect")){
	    	JOptionPane.showMessageDialog(frame, "É necessário conectar primeiro."); 
	    	return;	
	    }
	    String st=tf.getText();
	    String sttl="["+client.getName()+"]: "+st;
	    tf.setText("");
	    try {
	    	tx.setText(tx.getText()+"\n"+sttl);
		    server.twittar(st, client.getName());
	    }catch(java.rmi.RemoteException e) {
	    	e.printStackTrace();
	    	JOptionPane.showMessageDialog(frame, "Erro: Não foi possivel Twittar."); 
	    }
	}
	
	public void twitterUser() throws RemoteException, SQLException {
		if(userB.getText().equals("User")) {
			JOptionPane.showMessageDialog(frame, "É necessário conectar primeiro."); 
	    	return;	
		}
		
		try {
			tx.setText("");
			List<String> tt = server.User(client.getName());
			for(int i = 0; i < tt.size(); i++) {
				//System.out.println(tt.get(i));
				String sttl="["+client.getName()+"]: "+tt.get(i);
				tx.setText(tx.getText()+"\n"+sttl);
			}
		}catch(java.rmi.RemoteException e) {
	    	e.printStackTrace();
	    	JOptionPane.showMessageDialog(frame, "Erro: Não foi possivel requisitar os Twittes do usuario!"); 
	    }
	}
	
	public void timeline() throws RemoteException, SQLException {
		
		List<String> tl = server.timeLine();
		tx.setText("");
		
		for(int i = 0; i < tl.size(); i+=2) {
			//System.out.println(tl.get(i));
			//System.out.println(tl.get(i+1));
			String sttl="["+tl.get(i+1)+"]: "+tl.get(i);
			tx.setText(tx.getText()+"\n"+sttl);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new GUI();
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
		userB = new JButton("User");
		refresh = new JButton("Feed");
		u = new JLabel();
		
		tf = new JTextField();
		tx = new JTextArea();
		JButton bt = new JButton("Twittar");
		
		main.setLayout(new BorderLayout(5,5));
		
		top.setLayout(new GridLayout(1,0,5,5));
		top.add(new JLabel("Username"));top.add(user);
		top.add(new JLabel("Password")); top.add(pass);
		top.add(refresh);
		top.add(userB);
		top.add(login);
		main.add(top, BorderLayout.NORTH);
		
		cn.setLayout(new BorderLayout(5,5));
		cn.add(new JScrollPane(tx), BorderLayout.CENTER);        
	    //cn.add(lst, BorderLayout.EAST);  
	    main.add(cn, BorderLayout.CENTER);
	    
	    bottom.setLayout(new BorderLayout(5,5));
	    bottom.add(tf, BorderLayout.CENTER);    
	    bottom.add(bt, BorderLayout.EAST);
	    main.add(bottom, BorderLayout.SOUTH);
	    
	    main.setBorder(new EmptyBorder(10, 10, 10, 10) );
	    
	    
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
	    
	    bt.addActionListener(new ActionListener(){
	    	public void actionPerformed(ActionEvent e){ 
	    		try {
					twittar();
				} catch (RemoteException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}   
	    	}  
	    });
		
	    userB.addActionListener(new ActionListener(){
	    	public void actionPerformed(ActionEvent e){ 
	    		try {
					twitterUser();
				} catch (RemoteException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}   
	    	}  
	    });
		
	    refresh.addActionListener(new ActionListener(){
	    	public void actionPerformed(ActionEvent e){ 
	    		try {
					timeline();
				} catch (RemoteException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}   
	    	}  
	    });
	    
	    tf.addActionListener(new ActionListener(){
	    	public void actionPerformed(ActionEvent e){ 
	    		try {
					twittar();
				} catch (RemoteException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}  
	    	}  
	    });
		
		frame.setContentPane(main);
	    frame.setSize(700,600);
	    frame.setVisible(true);  
	}
		
	JTextArea tx;
	JTextField tf,pass, user;
	JButton login, userB, refresh;
	//JList<String> lst;
	JFrame frame;
	JLabel u;
	
}

