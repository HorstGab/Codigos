package controller;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import view.ViewMain;

public class ControllerMain implements ActionListener {

	ViewMain window;
	
	public ControllerMain () {
		ControllerMain me = this;
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					window = new ViewMain(me);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println(e.getActionCommand());
		if (e.getActionCommand().equals("consultarCliente")) {			
			window.add( (new ControllerCliente()).getView());
		}
		if (e.getActionCommand().equals("consultarConta")) {			
			window.add( (new ControllerConta()).getView());
		}
		if (e.getActionCommand().equals("fechar")) {
			window.close();
		} 
	}

	public static void main(String[] args) {
		new ControllerMain();
	}
}
