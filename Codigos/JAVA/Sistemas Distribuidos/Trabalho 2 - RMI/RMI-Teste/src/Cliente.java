
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import javax.swing.JOptionPane;
 
public class Cliente {
 
    public static void main(String[] args)
    {
        try {
               int val1 = Integer.parseInt(JOptionPane.showInputDialog("Entre com o primeiro valor"));
               String opcao[] = {"+", "-", "*", "/"};
 
               int operacao = JOptionPane.showOptionDialog(null, "Escolha uma das operacoes", "Tipo de operacao",
               0, JOptionPane.INFORMATION_MESSAGE, null, opcao, opcao[0]);
 
               int val2 = Integer.parseInt(JOptionPane.showInputDialog("Entre com o segundo valor"));
 
               InterfaceCalculoRemoto objCalculoRemoto = (InterfaceCalculoRemoto)
               Naming.lookup("rmi://localhost:1099/InterfaceCalculoRemoto");
 
               System.out.println("Servidor fala: O resultado é = " + objCalculoRemoto.metodo_calcular(val1, val2, operacao));
               objCalculoRemoto.mensagemServidor("Recebi a Resposta");
             }
 
            catch (MalformedURLException e)
            {
                    System.out.println("Erro:" + e.toString());
                    e.printStackTrace();
            }
            catch (RemoteException e)
            {
                    System.out.println("Erro:" + e.toString());
                    e.printStackTrace();
                }
            catch (NotBoundException e)
            {
                    System.out.println("Erro:" + e.toString());
                    e.printStackTrace();
                }
            catch (Exception e)
            {
                    JOptionPane.showMessageDialog(null, "Entrada inválida", e.getMessage(), JOptionPane.ERROR_MESSAGE);
                    System.exit(-1);
            }
    }
}