package unioeste.geral.pessoa;


import java.io.Serializable;


public class PessoaJuridica extends Pessoa implements Serializable {

	  // declarar opcionalmente. Motivo: objeto Serializable. Ver doc. java
	  public final static long serialVersionUID = 1;

	  public PessoaJuridica() {}
	  
	  protected long cnpj;
	  
	  public void setCnpj(long cnpj) { this.cnpj = cnpj; }
	  public long getCnpj() { return cnpj; }
	  
}
