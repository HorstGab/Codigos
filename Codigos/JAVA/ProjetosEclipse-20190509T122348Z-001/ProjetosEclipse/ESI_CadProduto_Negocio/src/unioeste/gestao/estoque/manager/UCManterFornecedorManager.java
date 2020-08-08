package unioeste.gestao.estoque.manager;

import Fornecedor;
import unioeste.gestao.estoque.fornecedor.ColFornecedor;

public class UCManterFornecedorManager {

	
	public UCManterFornecedorManager() {}
	
	public Fornecedor obtemFornecedor(int codFornecedor) throws Exception {
		
		ColFornecedor colForn = new ColFornecedor();
		return colForn.recuperaFornecedorPK(codFornecedor);
		
	}
}
