package common;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.sql.SQLException;
import java.util.Vector;

public interface IServidor extends Remote{
	
	public int login(ICliente c) throws RemoteException, SQLException;
	public boolean twittar(String t, String user) throws RemoteException, SQLException;
	public Vector<String> getConnected() throws RemoteException;
	public boolean setConnected(String name)throws RemoteException;
	public boolean Desconnected(String name) throws RemoteException;
}
