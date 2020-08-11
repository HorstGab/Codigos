package unioeste.geral.endereco;

import java.io.Serializable;

public class Endereco implements Serializable {

	  // declarar opcionalmente. Motivo: objeto Serializable. Ver doc. java
	  public final static long serialVersionUID = 1;

	  public Endereco() {}
	  
	  private long cep;
	  private String logradouro;
	  private String complemento;
	  private String bairro;
	  private String cidade;
	  private String uf;
	  
	  public void setCep(long cep) { this.cep = cep; }
      public long getCep() { return cep; }
	  
	  public void setLogradouro(String log) { this.logradouro = log; }
      public String getLogradouro() { return this.logradouro; }
      
	  public void setComplemento(String compl) { this.complemento = compl; }
      public String getComplemento() { return this.complemento; }
    	  
      public void setBairro(String bairro) {this.bairro = bairro; }
      public String getBairro() { return this.bairro; }
    	  
	  public void setCidade(String cidade) { this.cidade = cidade; }
      public String getCidade() { return this.cidade; }
  	  
	  public void setUf(String uf) { this.uf = uf; }
      public String getUf() { return uf; }
}
