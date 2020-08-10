package unioeste.gestao.estoque.fornecedor;

import Fornecedor;

import java.sql.ResultSet;

import unioeste.geral.endereco.Endereco;
import unioeste.gestao.estoque.infra.GlobalApp;
import esI.geral.infra.ConexaoBD;


public class ColFornecedor {

	public ColFornecedor() {}
	
	
	// ver comentarios recuperaProdutoPK.
	// caso endereco: Como objeto endereco é persistido na mesma tabela BD
	// a instância objeto endereco é recuperado e compõe o objeto fornecedor.
	public Fornecedor recuperaFornecedorPK(int cod) throws Exception  {
		
		Fornecedor fornecedor = null;
		
		ConexaoBD conexaoBD = GlobalApp.getConexaoBD();
   		
		ResultSet result = conexaoBD.execSelect("SELECT * FROM TAB_FORNECEDOR WHERE CODFORNECEDOR = " + cod); 
		
		if (result.next()) {
		  fornecedor = new Fornecedor();
          Endereco endereco = new Endereco();
		  fornecedor.setCodFornecedor(result.getInt("CODFORNECEDOR"));
          fornecedor.setCnpj(result.getLong("cnpj"));
          fornecedor.setEmail(result.getString("EMAIL"));
          fornecedor.setNome(result.getString("NOME"));
          fornecedor.setTelefone(result.getString("TELEFONE"));
          endereco.setBairro(result.getString("END_BAIRRO"));
          endereco.setCep(result.getLong("END_CEP"));
          endereco.setCidade(result.getString("END_CIDADE"));
          endereco.setComplemento(result.getString("END_COMPL"));
          endereco.setLogradouro(result.getString("END_LOGRADOURO"));
          endereco.setUf(result.getString("END_UF"));
          
          fornecedor.setEnderecoPrincipal(endereco);
		
		}

		result.close();
		
		if (fornecedor == null) {
			throw new Exception ("F não existe");
		}
		
		return fornecedor;
		
	}

}
