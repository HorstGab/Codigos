package model;

public class Quimico extends Produto {
	
	private boolean inflamavel;

	public Quimico() {
		this.inflamavel = false;
	}

	public Quimico(int codigo) {
		super(codigo);
		this.inflamavel = false;
	}

	public Quimico(int codigo, String nome, int quantidade, double preco) {
		super(codigo, nome, quantidade, preco);
		this.inflamavel = false;
	}

}
