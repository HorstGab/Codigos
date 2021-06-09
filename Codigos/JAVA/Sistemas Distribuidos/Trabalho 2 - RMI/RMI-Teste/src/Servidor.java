import java.rmi.Naming;
import java.rmi.RemoteException;
 
public class Servidor
{
    public Servidor() throws RemoteException
    {
        String localServico = "rmi://localhost:1099/InterfaceCalculoRemoto";
        InterfaceCalculoRemoto objServidorRemoto = new ImplementacaoCalculoRemoto();
 
        try
        {
             Naming.rebind(localServico, objServidorRemoto);
        }
        catch (Exception e)
        {
             e.printStackTrace();
        }
     }
 
        public static void main(String[] args) throws RemoteException
        {
              Servidor objServidor = new Servidor();
        }
}