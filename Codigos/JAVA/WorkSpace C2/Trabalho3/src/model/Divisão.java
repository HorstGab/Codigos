package model;

public class Divis�o extends Node {

	public Divis�o () {
		//super chama o construtor da classe pai
		super(" / ");
	}
	
	@Override
	public double processa() {
		return this.esq.processa() / this.dir.processa();
	}

}
