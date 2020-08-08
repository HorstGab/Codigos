package unioeste.gestao.estoque.produto;


import unioeste.gestao.estoque.fornecedor.Fornecedor;

import java.io.Serializable;


public class Produto implements Serializable {

	  // declarar opcionalmente. Motivo: objeto Serializable. Ver doc. java
	  public final static long serialVersionUID = 1;

      public Produto() {}
      
      private long codProduto;
      private String descricao;
      private double precoVenda;
      private Fornecedor fornecedor;
      
      public void setCodProduto(long cod) { this.codProduto = cod; }
      public long getCodProduto() { return codProduto; }
      
      public void setDescricao(String descr) { this.descricao = descr; }
      public String getDescricao() { return descricao; }
      
      public void setPrecoVenda(double preco) { this.precoVenda = preco; }
      public double getPrecoVenda() { return precoVenda; }
      
      public void setFornecedor(Fornecedor forn) { this.fornecedor = forn; }
      public Fornecedor getFornecedor() { return fornecedor; }
    
      
}
