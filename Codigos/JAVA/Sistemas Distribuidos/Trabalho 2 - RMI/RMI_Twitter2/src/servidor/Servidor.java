	package servidor;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import common.ICliente;
import common.IServidor;

public class Servidor extends UnicastRemoteObject implements IServidor{

	//private String[] postsGlobal;
	private Vector<String> v = new Vector<String>();
	
	private static final long serialVersionUID = 1L;

	public Servidor() throws RemoteException{
		java.rmi.registry.LocateRegistry.createRegistry(1099);
	}
	
	
	public int login(ICliente c) throws RemoteException, SQLException{
		
		if(setConnected(c.getName())) {
			Connection con = Query.getConnection();
			
			String sql = "SELECT exists (SELECT * FROM public.\"user\" "
					+ "WHERE (\"user\" = ? and \"pass\" = ?))";
			
			PreparedStatement stt = con.prepareStatement(sql);
			stt.setString(1, c.getName());
			stt.setString(2, c.getPass());
			ResultSet res = stt.executeQuery();
			
			if (res.next()) {
				if(res.getString(1).equals("t")) {
					return 1;
				}
			}
			return -1;
		}
		
		return -2;
	}
	
	public List<String> timeLine() throws RemoteException, SQLException{
		
		Connection con = Query.getConnection();
		List<String> tl = new ArrayList<>();
		
		String sql = "SELECT \"timeLine\", \"user\"\r\n"
				+ "	FROM public.\"timeLine\", public.\"user\"\r\n"
				+ "	where \"timeLine\".\"iduser\" = \"user\".\"idUser\";";
		
		PreparedStatement stt = con.prepareStatement(sql);
		ResultSet res = stt.executeQuery();
		
		while(res.next()) {
			String tt = res.getString("timeLine");
			String user = res.getString("user");
			tl.add(tt);
			tl.add(user);
		}
		return tl;
	}
	
	public List<String> User(String user)throws RemoteException, SQLException{
		
		Connection con = Query.getConnection();
		int iduser = buscaID(user, con);
		List<String> tw = new ArrayList<>();
		
		String sql = "SELECT \"timeLine\"\r\n"
				+ "	FROM public.\"timeLine\"\r\n"
				+ "	where idUser = ?;";
		
		PreparedStatement stt = con.prepareStatement(sql);
		stt.setInt(1, iduser);
		ResultSet res = stt.executeQuery();
		
		while(res.next()) {
			String tt = res.getString("timeLine");
			tw.add(tt);
		}
		return tw;	
	}
	public boolean twittar(String t, String user)throws RemoteException, SQLException{
		
		Connection con = Query.getConnection();
		int iduser = buscaID(user, con);
		
		String sql = "INSERT INTO public.\"timeLine\" (\"timeLine\", iduser)" +
                " VALUES (?, ?) ";
		
		PreparedStatement create = con.prepareStatement(sql);
        create.setString(1,t);
        create.setInt(2, iduser);
        create.execute();
        ResultSet generatedKeys;
        try {
            generatedKeys = create.getGeneratedKeys();
            generatedKeys.next();
            return true;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return false;
        }
	}
	
	public int buscaID(String user, Connection con) throws SQLException {
		
		String sql = "SELECT \"idUser\" "
				+ "	FROM public.\"user\""
				+ "	where \"user\" = ?;";
		
		PreparedStatement stt = con.prepareStatement(sql);
		stt.setString(1, user);
		ResultSet res = stt.executeQuery();
		if (!res.next()) return -1;
		
		return res.getInt("idUser");   
		
	}
	
	public Vector<String> getConnected() throws RemoteException{
		return v;
	}
	
	public boolean setConnected(String name) throws RemoteException{
		if(v.contains(name)) return false;
		v.add(name);
		System.out.println(v);
		return true;
	}
	
	public boolean Desconnected(String name) throws RemoteException{
		System.out.println(name);
		return v.remove(name);
	}
}
