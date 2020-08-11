package teste;

import Fornecedor;
import unioeste.gestao.estoque.manager.*;
import unioeste.gestao.estoque.produto.*;
import unioeste.gestao.estoque.fornecedor.*;

public class TesteUCManterProduto {

	
	public static void testeCadastrarProduto() {
		
		UCManterProdutoManager ucProduto = new UCManterProdutoManager();
		
		try {
		//  seta os dados nos objetos de negócio
		   Produto prod = new Produto();
		   prod.setCodProduto(1);
		   prod.setDescricao("Computador Duo Core Intel 1.8");
		   prod.setPrecoVenda(1050);
		   Fornecedor forn = new Fornecedor();
		   forn.setCodFornecedor(1);
		   prod.setFornecedor(forn);
		//   executa o servico.   
	       ucProduto.cadastrarProduto(prod);
	       System.out.println("Cadastro OK");
			
		} catch (Exception ee) {
			System.out.println("Erro: " + ee.getMessage());
			System.out.println("");
			ee.printStackTrace();
		}
		
	}

	public static void testeObterProduto() {
		
		UCManterProdutoManager ucProduto = new UCManterProdutoManager();
		
		try {
		
	       Produto produto = ucProduto.obterProduto(1);
	       System.out.println("Produto: " + produto.getDescricao());
	       System.out.println("Fornecedor do Produto: " + produto.getFornecedor().getNome());
	       
	       
		} catch (Exception ee) {
			System.out.println("Erro: " + ee.getMessage());
			ee.printStackTrace();
		}
		
	}

}
