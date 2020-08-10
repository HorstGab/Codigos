package Controller;

import Model.agenda;
import Model.data;
import Model.pessoa;

public class controllerMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		agenda ag = new agenda();
		
		ag.armazenaPessoa(new pessoa("Gabriel Horst Montoanelli", new data(30, 9 ,1998), 1.8));

		ag.armazenaPessoa(new pessoa("Iraci Horst", new data(30, 10 ,1958), 1.7));
		
		ag.armazenaPessoa(new pessoa("José Aloizio Montoanelli", new data(5, 5 ,1964), 1.75));
		
		ag.imprimeAgenda();
		
		System.out.println();
		
		ag.removePessoa("José Aloizio Montoanelli");

		ag.imprimeAgenda();
		
//		Calendar c = Calendar.getInstance(); //singleton

//		data hoje = new data (c.get(Calendar.DAY_OF_MONTH), c.get(Calendar.MONTH)+1, c.get(Calendar.YEAR));

//		System.out.println(p);
//		System.out.println("Idade: " + p.getIdade(hoje) + " anos");
//		
//		data data = new data(24,04,2002);
//		data d1 = new data (31,12, 2000);
//		data d2 = new data(01, 01, 2001);
//		
//		System.out.println(d1.diferencaAno(d2));
		
//		System.out.println(data);
//		System.out.println(hoje);
//		System.out.println(data.diferencaAno(hoje));
//		

//		Date dt = c.getTime();
//		data hoje = new data(dt.getDate(), dt.getMonth(), dt.getYear()); //ainda disponivel mas é absoleta 

	}

}
