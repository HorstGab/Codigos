package common;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.sql.SQLException;

import cliente.Cliente;

public interface IServidor extends Remote{
	
	public boolean login(Cliente c) throws RemoteException, SQLException;
	public void timeLine() throws RemoteException;
}
