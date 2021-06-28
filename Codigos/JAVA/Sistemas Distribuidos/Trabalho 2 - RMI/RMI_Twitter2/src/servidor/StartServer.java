package servidor;

import java.rmi.Naming;

import common.IServidor;
import servidor.Servidor;


public class StartServer {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			java.rmi.registry.LocateRegistry.createRegistry(3031);
			IServidor b = new Servidor();
			Naming.rebind("rmi://localhost:3031/twitter", b);
			System.out.println("[system] Twitter server is ready.");
		}catch(Exception e) {
			System.out.println("Twitter server failed "+e);
		}
	}

}
