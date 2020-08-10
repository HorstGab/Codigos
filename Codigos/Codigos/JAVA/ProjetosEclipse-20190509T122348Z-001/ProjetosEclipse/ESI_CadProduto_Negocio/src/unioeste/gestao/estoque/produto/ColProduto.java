package unioeste.gestao.estoque.produto;

import Fornecedor;

import java.sql.ResultSet;

import unioeste.gestao.estoque.infra.GlobalApp;
import esI.geral.infra.ConexaoBD;

public class ColProduto {

 	
	public ColProduto() {
	}
	

	public Produto criarProduto(Produto produto, Fornecedor fornecedor) throws Exception  {

		produto.setFornecedor(fornecedor);
		this.validarProduto(produto);
		
		ConexaoBD conexaoBD = GlobalApp.getConexaoBD();
		// INSERT produto
		StringBuffer sql = new StringBuffer("INSERT INTO TAB_PRODUTO ");
		sql.append(" (codproduto, descricao, precoVenda, codfornecedor) VALUES (");
		sql.append("" + produto.getCodProduto() + ", ");
		sql.append(" '" + produto.getDescricao().trim() + "' , ");
		sql.append("" + produto.getPrecoVenda() + " , ");
		sql.append("" + produto.getFornecedor().getCodFornecedor() + ")");
		//
		conexaoBD.execSQL(sql.toString());
		
		return produto;
		
	}
	
	
	// padr�o de projeto: m�todo recuperaObjetoPK retorna
	// objeto solicitado, no caso aqui, Produto, mas sem
	// os objetos de relacionamento (exemplo Fornecedor)
	// Somente s�o criadas "inst�ncias destes relacionamentos" para
	// n�o perder a chave estrangeira da persist�ncia.
	// O objeto com seus relacionamentos totalmente completos
	// s�o gerados conforme o servi�o e cen�rio de uso.
	
	public Produto recuperaProdutoPK(long cod) throws Exception  {
		
		Produto produto = null;
		
		ConexaoBD conexaoBD = GlobalApp.getConexaoBD();
   		
		ResultSet result = conexaoBD.execSelect("SELECT * FROM TAB_PRODUTO WHERE CODPRODUTO = " + cod); 
		
		if (result.next()) {
		  produto = new Produto();
		  produto.setCodProduto(cod);
		  produto.setDescricao(result.getString("DESCRICAO"));
		  produto.setPrecoVenda(result.getDouble("PRECOVENDA"));
		  // cria inst�ncia de fornecedor para produto parcialmente
		  // a inst�ncia do objeto fornecedor ser� sob demanda, dependendo
		  // do servi�o. 
		  Fornecedor fornecedor = new Fornecedor();
		  fornecedor.setCodFornecedor(result.getInt("CODFORNECEDOR"));
		  produto.setFornecedor(fornecedor);
		}

		result.close();
		
		if (produto == null) {
			throw new Exception ("Produto n�o existe");
		}
		
		return produto;
		
	}

    public void validarProduto(Produto produto) throws Exception {
    	 
  	  if (produto.getCodProduto() <= 0 || produto.getCodProduto() > 9999999) {
  		 throw new Exception("Codigo do produto invalido");  
  	  }
  	  if (produto.getDescricao() == null) {
   		  throw new Exception("Descricao do Produto deve existir");
  	  }
  	  if (produto.getDescricao().equals("")) {
    		  throw new Exception("Descricao do Produto deve existir");
  	  }
  	  if (produto.getPrecoVenda() < 0) {
  		  throw new Exception("Preco de venda menor que zero");
  	  }
  	  if (produto.getFornecedor() == null) {
  		  throw new Exception("Fornecedor n�o informado");
  	  }

    }
    
	
	
}
