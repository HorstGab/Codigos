package cliente;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

import common.ICliente;

public class Cliente extends UnicastRemoteObject implements ICliente{
	
	private String name;
	private String pass;
	private String[] posts;
	private GUI ui;
	
	public Cliente (String user, String pass)throws RemoteException{
		this.name = user;
		this.pass = pass;
	}
	

	public void tell (String name) throws RemoteException{}

	public void setGUI(GUI t) {
		ui =t;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getPass() {
		return this.pass;
	}
}
