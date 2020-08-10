package Controller;
import Model.Pessoa;
import Util.Param;
import Util.Vetor;

public class controllerMain {
	
	
	
	public static void main(String[] args) {
		
		Pessoa p = new Pessoa("1920", "Gabriel", 'M');
		
		System.out.println(p);
		
		Param p1 = new Param("A", "Gabriel");
		Param p2 = new Param("B", 1234.55);
		Param p3 = new Param("C", 12345.55);
		Param p4 = new Param("D", 123);
		
		Vetor v = new Vetor(100);
		v.add(p1);
		v.add(p2);
		v.add(p3);
		v.add(p4);
		
		for (int i = 0; i < v.getCount(); i++) {
			System.out.println(v.get(i));
		}
		 
		Calculos.Vetor v2 = new Calculos.Vetor (100);
		v2.lerVetor();
		v2.mostrarVetor();
		
		System.out.println("Soma: " + v2.soma());
		System.out.println("Média: " + v2.media());
		
		v2.ordena();
		v2.mostrarVetor();
		
		System.out.println("Soma: " + v2.soma());
		System.out.println("Média: " + v2.media());
		System.out.println("Maior: " + v2.getMaior());
		System.out.println("Menor: " + v2.getMenor());
		System.out.println("Conta 5: " + v2.getNumeroOcorrencia(5));
		
		v2.mostrarVetor();
		//imprime o vetor, mas n contem indice
//		Param vetor[] = v.getVetor();
//		for (Param param : v.getVetor()) {
//			System.out.println(param);
//		}
		
		
//		System.out.println(p1);
//		System.out.println(p2);
//		System.out.println(p3);
//		System.out.println(p4);
		
//		controllerMain ctrl = new controllerMain();
//		System.out.println(ctrl.fibonacci(10));
		
//		Calculos c = new Calculos();
//		
//		System.out.println("Fat 5:" + c.Fatorial(5));
//
//		
//		for(int i = 0; i < args.length; i++) {
//			System.out.println(args[i]);
//		}
//		
//		for(int i = 0; i < 10; i++) {
//			/*if(i%2 == 0) {
//				System.out.println(i + " = *");
//			}else {
//				System.out.println(i + " = **");
//			}
//			*/
//			
//			System.out.println( (i%2 == 0)? "*" : "**" );
//		}
//		
//		
//		for (int i = 0; i < 20; i++) {
//			System.out.println( ((i+1)%4==0)? "PI": i+1  );
//		}
//		
//		String s = "*";
//		for (int i = 0; i < 20; i++) {
//			System.out.println(s);
//			if(s.length() == 4) {
//				s = "*";
//			}else {
//				s += "*";
//			}
//		}
//		
//		long anterior = 0;
//		long atual = 1;
//		long proximo;
//		System.out.println(anterior + " ");
//		for(int i = 0; i < 50; i++) {
//			System.out.println(atual + " ");
//			proximo = anterior + atual;
//			anterior = atual;
//			atual = proximo;
//		}
//		
		
		
		// TODO Auto-generated method stub
//		//debug
//		System.out.println("Olá Mundo1!");
//		System.out.println("Olá Mundo2!");
//		//error
//		System.err.println("Erro!");
//		System.err.println("Erro1!");
		
//		Scanner scan = new Scanner(System.in);
//		
//		System.out.print("Digite um numero: ");
//		
//		int i = scan.nextInt();
//		
//		System.out.println("Numero digitacao: " + i);
//		
//		for(int j = 0; j < 10; j++) {
//			System.out.println(j);
//		}
//		
//		scan.close();

	}
}
