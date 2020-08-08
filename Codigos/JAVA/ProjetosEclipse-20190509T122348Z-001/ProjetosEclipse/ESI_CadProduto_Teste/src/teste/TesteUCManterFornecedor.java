package teste;

import Fornecedor;
import unioeste.gestao.estoque.manager.*;
import unioeste.gestao.estoque.fornecedor.*;

public class TesteUCManterFornecedor {

	
	public static void obterFornecedor() {
		
		UCManterFornecedorManager ucForn = new UCManterFornecedorManager();
		
		try {
			Fornecedor forn = ucForn.obtemFornecedor(1);
			System.out.println("Codigo: " + forn.getCodFornecedor());
			System.out.println("Nome: " + forn.getNome());
			System.out.println("email: " + forn.getEmail());
			System.out.println("Cidade: " + forn.getEnderecoPrincipal().getCidade());
			
		} catch (Exception ee) {
			System.out.println("Msg: " + ee.getMessage());
			ee.printStackTrace();
		}
		
	}
}
