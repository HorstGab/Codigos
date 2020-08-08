package model;

public class Multiplicação extends Node {

	public Multiplicação () {
		super(" * ");
	}
	@Override
	public double processa() {
		return this.esq.processa() * this.dir.processa();
	}

}
