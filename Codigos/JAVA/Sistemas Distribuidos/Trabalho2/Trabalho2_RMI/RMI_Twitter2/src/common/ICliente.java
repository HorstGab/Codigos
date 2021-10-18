package common;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ICliente extends Remote{
	
	public void tell (String name) throws RemoteException;
	public String getName() throws RemoteException;
	public String getPass() throws RemoteException;
}
