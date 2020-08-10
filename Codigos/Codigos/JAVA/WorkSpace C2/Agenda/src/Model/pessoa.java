package Model;

public class pessoa {

	private String nome;
	private data nascimento;
	private double altura;
	
	public pessoa(String nome, data nascimento, double altura) {
		this.nome = nome;
		this.nascimento = nascimento;
		this.altura = altura;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public data getNascimento() {
		return nascimento;
	}
	
	public void setNascimento(data nascimento) {
		this.nascimento = nascimento;
	}
	
	public double getAltura() {
		return altura;
	}
	
	public void setAltura(double altura) {
		this.altura = altura;
	}
	
	public int getIdade(data hoje) {
		return this.nascimento.diferencaAno(hoje);
	}
	
	public boolean equals (String nome) {
		return this.nome.toUpperCase().equals(nome.toUpperCase());
	}
	
	public String toString() {
		return "Nome: " + this.nome + "\n" + "Data de Nascimento: " + this.nascimento + "\n" + "Altura: " + this.altura + " metros";
	}
	
}
