package model;

public class Conta {

	public static int instance;
	public int valor;
	
	 public Conta () {
		Conta.instance++;
		this.valor = Conta.instance;
	}
	
	public static void  zerar () {
		System.out.println("Instancias: " + Conta.instance);
		System.out.println("Zerando...");
		Conta.instance = 0;
	}
	
	public String toString () {
		return "Numero de Instancias: "+ instance; 
	}
}
