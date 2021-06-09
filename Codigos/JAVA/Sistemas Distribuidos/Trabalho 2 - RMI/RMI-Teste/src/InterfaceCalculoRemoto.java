import java.rmi.Remote;
import java.rmi.RemoteException;
 
public interface InterfaceCalculoRemoto extends Remote
{
        public double metodo_calcular(int val1, int val2, int operacao) throws RemoteException;
        public void mensagemServidor(String mensagem) throws RemoteException;
}