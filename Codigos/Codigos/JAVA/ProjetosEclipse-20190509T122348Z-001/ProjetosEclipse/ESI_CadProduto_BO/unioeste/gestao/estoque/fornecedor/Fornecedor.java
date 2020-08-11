package unioeste.gestao.estoque.fornecedor;



import java.io.Serializable;

import unioeste.geral.pessoa.PessoaJuridica;

public class Fornecedor extends PessoaJuridica implements Serializable  {

	  // declarar opcionalmente. Motivo: objeto Serializable. Ver doc. java
	  public final static long serialVersionUID = 1;

	  public Fornecedor() {}
	  
	  private int codFornecedor;
	  
	  public void setCodFornecedor(int cd) { this.codFornecedor = cd; }
	  public int getCodFornecedor() { return codFornecedor; }
	  
}
