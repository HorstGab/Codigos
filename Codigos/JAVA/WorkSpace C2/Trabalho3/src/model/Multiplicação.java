package model;

public class Multiplica��o extends Node {

	public Multiplica��o () {
		super(" * ");
	}
	@Override
	public double processa() {
		return this.esq.processa() * this.dir.processa();
	}

}
