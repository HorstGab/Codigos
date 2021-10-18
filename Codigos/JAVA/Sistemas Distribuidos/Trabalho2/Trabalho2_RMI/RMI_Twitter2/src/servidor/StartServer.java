package servidor;

import java.rmi.Naming;

import common.IServidor;


public class StartServer {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			IServidor b = new Servidor();
			Naming.rebind("rmi://localhost/twitter", b);
			System.out.println("[system] Twitter server is ready.");
		}catch(Exception e) {
			System.out.println("Twitter server failed "+e);
		}
	}

}
