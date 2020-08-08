package Model;

public class agenda {

	private pessoa p[];
	private int n;
	
	public agenda() {
		this.p = new pessoa[10];
		this.n = 0;
	}
	
	public void armazenaPessoa( pessoa p) {
		this.p[n++] = p;
	}
	
	public void imprimePessoa(int index) {
		System.out.println(p[index]);
	}
	
	public void imprimeAgenda() {
		System.out.println("Relação de pessoas da agenda ....");
		for(int i = 0; i < n; i++) {
			imprimePessoa(i);
		}
	}
	
	public int buscaPessoa(String nome) {
		for(int i = 0; i < n; i++) {
			if(p[i].equals(nome)) {
				return i;
			}
		}
		return -1;
	}
	
	public void removePessoa(String nome) {
		int index = buscaPessoa(nome);
		if(index >= 0) {
			for(int i = index +1; i < n; i++) {
				p[i-1] = p[i];
			}
			n--;
			p[n] = null;
		}
	}
	
	public String toString() {
		return "Agenda contendo " + this.n + " pessoas";
	}
}
