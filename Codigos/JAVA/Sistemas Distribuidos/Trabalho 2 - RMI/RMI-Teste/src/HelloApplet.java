import java.awt.*;
import java.rmi.*;

public class HelloApplet extends java.applet.Applet{

	String mensagem="";
	
	public 	void init() {
		try {
			Hello obj = (Hello)Naming.lookup("//"+getCodeBase().getHost()+"/HelloServer");
			mensagem=obj.sayHello();
		}catch(Exception e) {
			System.out.println("Ocorreu uma exceção");
			e.printStackTrace();
		}
	}
	
	public void paint(Graphics g) {
		g.drawString(mensagem, 25, 50);
	}
}
