package Model;

public class Pessoa {
	private String cpf = " ";
	private String nome = " ";
	private char sexo = ' ';
	
	public Pessoa (String cpf, String nome, char sexo) {
		
		this.cpf = cpf;
		this.nome = nome;
		this.sexo = sexo;
	}

	public Pessoa ( String nome, char sexo) {

		this.nome = nome;
		this.sexo = sexo;
	}
	
	public String getCpf() {
		return cpf;
	}
	
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public char getSexo() {
		return sexo;
	}
	
	public void setSexo(char sexo) {
		this.sexo = sexo;
	}
	
	public String toString() {
		return this.cpf + " " + this.nome + " " + this.sexo;
	}
}
