package Calculos;
import java.util.Scanner;

public class Vetor {
	private int v[];
	private int n;
	
	public Vetor (int max) {
		this.v = new int [max];
		this.n = 0;
	}
	
	public void lerVetor() {
		Scanner sc = new Scanner (System.in);
		System.out.println("Digite os números do vetor e zero para finalizar");
		int numero;
		do { // repetir 1 ou mais vezes
			numero = sc.nextInt();
			if(numero != 0) {
				this.v[this.n++] = numero;
			}
		}while(numero != 0);
		sc.close();
	}
	
	public void mostrarVetor() {
		System.out.println(" ----------- Elementos do vetor ------------");
		for (int i = 0; i < n ; i++) {
			System.out.print(v[i] + " ");
		}
		System.out.println();
	}
	
	public int soma() {
		int s = 0;
		
		for (int i = 0; i < n; i++) {
			s += v[i];
		}
		return s;
	}
	
	public double media() {
		if(n > 0) {
			return (double)soma()/n;
		}
		//trocar por uma exception
		return 0;
	}
	
	public int getMaior() {
		if(this.n > 0) {
			int maior = this.v[0];

			for(int i = 1; i < this.n; i++) {
				if(maior < this.v[i]) {
					maior = this.v[i];
				}
			}
			return maior;
		}
		//trocar por uma exception
		return 0;
	}
	 
	public int getMenor() {
		if(this.n > 0) {
			int menor = this.v[0];

			for(int i = 1; i < this.n; i++) {
				if(menor > this.v[i]) {
					menor = this.v[i];
				}
			}
			return menor;
		}
		//trocar por uma exception
		return 0;
	}
	
	public int getNumeroOcorrencia( int e ) {
		int contador = 0;
		
		for(int i = 0; i < this.n; i++) {
			if(this.v[i] == e) {
				contador ++;
			}
		}
		return contador;
	}
	
	public void ordena() {
		for(int i = 0; i < this.n; i++) {
			for(int j = i+1; j < this.n; j++) {
				if(this.v[i] > this.v[j]) {
					int aux = this.v[i];
					this.v[i] = this.v[j];
					this.v[j] = aux;
				}
			}
		}
	}
}
