package servidor;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import cliente.Cliente;
import common.IServidor;

public class Servidor extends UnicastRemoteObject implements IServidor{

	
	private String[] postsGlobal;
	
	public Servidor() throws RemoteException{}
	
	public boolean login(Cliente c) throws RemoteException, SQLException{
		
		Connection con = Query.getConnection();
		
		String sql = "SELECT * FROM public.\"user\" "
				+ "WHERE (\"name\" = ? and \"password\" = ?);";
		
		PreparedStatement stt = con.prepareStatement(sql);
		stt.setString(1, c.getName());
		stt.setString(2, c.getPass());
		ResultSet res = stt.executeQuery();
		if (res != null) return false;
		return true;
	}
	
	public void timeLine() throws RemoteException{
		
	}
	
	
}
