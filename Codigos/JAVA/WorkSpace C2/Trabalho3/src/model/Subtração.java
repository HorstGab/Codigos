package model;

public class Subtração extends Node {

	public Subtração () {
		super(" - ");
	}
	
	@Override
	public double processa() {
		return this.esq.processa() - this.dir.processa();
	}

}
