package unioeste.gestao.estoque.manager;

import Fornecedor;
import unioeste.gestao.estoque.fornecedor.ColFornecedor;
import unioeste.gestao.estoque.infra.GlobalApp;
import unioeste.gestao.estoque.produto.ColProduto;
import unioeste.gestao.estoque.produto.Produto;
import esI.geral.infra.ConexaoBD;

public class UCManterProdutoManager {

	public UCManterProdutoManager() {}
	
	public Produto cadastrarProduto(Produto produto) throws Exception  {
	
		ColProduto colProd = new ColProduto();
		ColFornecedor colForn = new ColFornecedor();
		
		try {
		    produto = colProd.recuperaProdutoPK(produto.getCodProduto());
		} catch (Exception ee) {}
		
		if (produto != null) {
			throw new Exception("Produto já existe");
		}

		Fornecedor fornecedor = null;
		if (produto.getFornecedor() != null) {
		    fornecedor = colForn.recuperaFornecedorPK(produto.getFornecedor().getCodFornecedor());
		}
		
	    // iniciar transação
		ConexaoBD conexao = GlobalApp.getConexaoBD();

		
		produto = colProd.criarProduto(produto,fornecedor);
		
		// fechar transacao
		conexao.getConnection().commit();
		
		return produto;
	}

	public Produto obterProduto(long codProduto) throws Exception {
		ColProduto colProd = new ColProduto();
		Produto produto = null;

	    produto = colProd.recuperaProdutoPK(codProduto);
	    
	    // recupera o fornecedor do produto
	    // Nota: a instancia associada no momento para o objeto produto
	    //       contém apenas a chave primária. O algoritmo abaixo instância
	    //       (recupera do BD) o objeto completo ref. ao fornecedor.
	    ColFornecedor colForn = new ColFornecedor();
	    Fornecedor forn = colForn.recuperaFornecedorPK(produto.getFornecedor().getCodFornecedor());
	    produto.setFornecedor(forn);
	    
	    return produto;
	}
	
}
