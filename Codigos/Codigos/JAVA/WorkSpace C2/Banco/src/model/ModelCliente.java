package model;

public class ModelCliente extends Model {

	protected int    idcliente=-1;
	protected String cpf;
	protected String nome;
	protected String sobrenome;

	@Override
	public int getId() {
		return idcliente;
	}
	
	public int getIdcliente() {
		return idcliente;
	}
	
	public void setIdcliente(int idcliente) {
		this.idcliente = idcliente;
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
	
	public String getSobrenome() {
		return sobrenome;
	}
	
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	
	public String toString() {
		return this.nome + " " + this.sobrenome;
	}
	
}
