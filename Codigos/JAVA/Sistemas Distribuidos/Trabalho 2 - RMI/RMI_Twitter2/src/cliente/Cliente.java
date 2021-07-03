package cliente;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

import common.ICliente;

public class Cliente extends UnicastRemoteObject implements ICliente{
	
	private static final long serialVersionUID = 1L;
	private String name;
	private String pass;
	//private String[] posts;
	private GUI ui;

	
	public Cliente (String user, String pass)throws RemoteException{
		this.name = user;
		this.pass = pass;
	}
	

	public void tell (String name) throws RemoteException{}

	public void setUi(GUI ui) {
		this.ui =ui;
	}
	
	public GUI getUi() {
		return this.ui;
	}
	
	public String getName() throws RemoteException{
		return this.name;
	}
	
	public String getPass() throws RemoteException{
		return this.pass;
	}
}
