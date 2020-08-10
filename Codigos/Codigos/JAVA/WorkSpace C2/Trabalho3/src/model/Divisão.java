package model;

public class Divisão extends Node {

	public Divisão () {
		//super chama o construtor da classe pai
		super(" / ");
	}
	
	@Override
	public double processa() {
		return this.esq.processa() / this.dir.processa();
	}

}
