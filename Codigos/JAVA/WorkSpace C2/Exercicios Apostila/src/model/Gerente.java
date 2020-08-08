package model;

public class Gerente extends Funcionario {

	private String senha;
	private String usuario; 
	
	public String getSenha () {
		return this.senha;
	}
	
	public String getUsuario () {
		return this.usuario;
	}
	
	public void setSenha (String senha) {
		this.senha = senha;
	}
	
	public void setUsuario (String usuario) {
		this.usuario = usuario;
	}
	
	
}
