package unioeste.geral.pessoa;

import java.io.Serializable;

import unioeste.geral.endereco.Endereco;

public class Pessoa implements Serializable  {

	  // declarar opcionalmente. Motivo: objeto Serializable. Ver doc. java
	  public final static long serialVersionUID = 1;

	  public Pessoa() {}
	  
	  protected String nome;
	  protected String telefone;
	  protected String email;
	  protected Endereco enderecoPrincipal;
	  
	  public void setNome (String nome) { this.nome = nome; }
	  public String getNome() { return nome; }
	  
	  public void setTelefone (String fone) { this.telefone = fone; }
	  public String getTelefone() { return telefone; }
	  
	  public void setEmail(String email) { this.email = email; }
	  public String getEmail() { return email; }
	  
	  public void setEnderecoPrincipal (Endereco end) { this.enderecoPrincipal = end; }
	  public Endereco getEnderecoPrincipal() { return this.enderecoPrincipal; }
	  
}
