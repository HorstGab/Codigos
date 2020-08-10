package Util;

public class Vetor {

	private int max = 100;
	private Param v[]; // = new Param[100]
	private int cont; // =0
	
	public Vetor(int max) {
		this.max = max;
		this.v = new Param[max];
		this.cont = 0;
	}
	
	public Vetor() {
		this.v = new Param[max];
		this.cont = 0;
	}
	
	public void add (Param p) {
		this.v[this.cont++] = p;
	}
	
	public int getCount () {
		return this.cont;
	}
	
	public Param get(int index) {
		return this.v[index];
	}
	
	public Param[] getVetor() {
		return this.v;
	}
	
	public String toString() {
		return "Vetor com " + this.cont + " Parâmetros";
	}
}
