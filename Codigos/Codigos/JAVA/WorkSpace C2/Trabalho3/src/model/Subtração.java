package model;

public class Subtra��o extends Node {

	public Subtra��o () {
		super(" - ");
	}
	
	@Override
	public double processa() {
		return this.esq.processa() - this.dir.processa();
	}

}
