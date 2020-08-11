package model;

public class Produto {

	private int codigo;
	private String nome;
	private int quantidade;
	private double preco;
	
	public Produto ( ) {
		this.codigo = 0;
		this.nome   = "";
		this.quantidade = 0;
		this.preco = 0;
	}
	
	public Produto ( int codigo ) {
		this.codigo = codigo;
		this.nome   = "";
		this.quantidade = 0;
		this.preco = 0;
	}
	
	public Produto ( int codigo, String nome, int quantidade, 
			double preco ) {
		this.codigo = codigo;
		this.nome   = nome;
		this.quantidade = quantidade;
		this.preco = preco;
	}
	
	public int getCodigo() {
		return codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}
	
	public void atualizaPreco ( double percentual ) {
		this.preco += this.preco*percentual/100;
	}

	public double totaliza ( ) {
		return this.quantidade * this.preco;
	}
		
	public String toString () {
		return "Código : "+ this.codigo +
			   "\nNome : " + this.nome +
			   "\nQtd  : " + this.quantidade+
			   "\nPreço unitário  : R$ " + this.preco +
			   "\nValor total : R$ " + this.totaliza();		   
	}
	
}
