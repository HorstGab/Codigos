import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
 
public class ImplementacaoCalculoRemoto extends UnicastRemoteObject implements InterfaceCalculoRemoto
{
    public ImplementacaoCalculoRemoto() throws RemoteException
    { }
 
public void mensagemServidor(String mensagem) throws RemoteException
{
      System.out.println("Cliente fala: " + mensagem);
}
 
public double metodo_calcular(int val1, int val2, int op) throws RemoteException
{
   double v1 = Double.valueOf(String.valueOf(val1));
   double v2 = Double.valueOf(String.valueOf(val2));
 
      if (op == 0)
      {
          return (v1 + v2);
      }
      else
          if (op == 1)
          {
              return (v1 - v2);
          }
          else
              if (op == 2)
              {
                  return (v1 * v2);
              }
              else
                   if (op == 3)
                   {
                       return (v1 / v2);
                    }
     return 0;
  }
}