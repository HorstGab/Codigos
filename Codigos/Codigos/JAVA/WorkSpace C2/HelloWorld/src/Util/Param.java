package Util;

public class Param {

	public enum Tipo {STRING, DOUBLE, FLOAT, INT};
	private String nome;
	private Object valor;
	private Tipo tipo;
	
	public Param (String nome, String valor) {
		this.nome = nome;
		this.valor = valor;
		this.tipo = Tipo.STRING;
	}
	
	public Param (String nome, double valor) {
		this.nome = nome;
		this.valor = valor;
		this.tipo = Tipo.DOUBLE;
	}
	
	public Param (String nome, float valor) {
		this.nome = nome;
		this.valor = valor;
		this.tipo = Tipo.FLOAT;
	}
	
	public Param (String nome, int valor) {
		this.nome = nome;
		this.valor = valor;
		this.tipo = Tipo.INT;
	}

	public String getNome() {
		return nome;
	}

	public Object getValor() {
		return valor;
	}

	public Tipo getTipo() {
		return tipo;
	}
	
	public String toString() {
		return this.nome + "= " + this.valor + " " + this.tipo;
	}
	
}
