package view;

import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.beans.PropertyVetoException;

import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;

public class ViewMain {
	private JFrame frame;
	
	public  JDesktopPane deskPanel;  
	
	private ActionListener al;

	/**
	 * Create the application.
	 */
	public ViewMain(ActionListener al) {
		this.al = al;
		initialize();
		frame.setVisible(true);
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		 
		 
		frame = new JFrame();
		frame.setBounds(100, 100, 710, 536);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		frame.setJMenuBar(menuBar);
		
		JMenu mnSistema = new JMenu("Sistema");
		menuBar.add(mnSistema);
		
		JMenuItem mntmConsultarCliente = new JMenuItem("Consultar cliente");
		mntmConsultarCliente.setActionCommand("consultarCliente");
		mntmConsultarCliente.addActionListener(al);
		mnSistema.add(mntmConsultarCliente);
		
		JMenuItem mntmConsultarConta = new JMenuItem("Consultar conta");
		mntmConsultarConta.setActionCommand("consultarConta");
		mntmConsultarConta.addActionListener(al);
		mnSistema.add(mntmConsultarConta);
		
		JSeparator separator = new JSeparator();
		mnSistema.add(separator);
		
		JMenuItem mntmFechar = new JMenuItem("Fechar");
		mntmFechar.setActionCommand("fechar");
		mntmFechar.addActionListener(al);
		mnSistema.add(mntmFechar);
		
		deskPanel = new JDesktopPane();
		frame.getContentPane().add(deskPanel);
	}
	
	public void add ( JInternalFrame internalFrame ) {
		deskPanel.add(internalFrame, BorderLayout.CENTER );
		internalFrame.setVisible(true);
		try {
			internalFrame.setMaximum(true);
		} catch (PropertyVetoException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void close () {
		this.frame.setVisible(false);
	}
}

