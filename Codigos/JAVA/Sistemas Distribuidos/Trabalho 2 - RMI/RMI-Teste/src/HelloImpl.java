import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class HelloImpl extends UnicastRemoteObject implements Hello{

	private String nome;
	
	public HelloImpl(String s) throws java.rmi.RemoteException{
		super();
		nome = s;
	}
	
	public String sayHello() throws RemoteException{
		return "Hello World!";
	}
	
	@SuppressWarnings("deprecation")
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.setSecurityManager(new RMISecurityManager());
		
		try {
			HelloImpl obj = new HelloImpl("HelloServer");
			Naming.rebind("HelloServer", obj);
			System.out.println("HelloImpl foi criado e registrado");
		}catch(Exception e) {
			System.out.println("Ocorreu uma exceção no servidor");
			e.printStackTrace();
		}
	}

}
