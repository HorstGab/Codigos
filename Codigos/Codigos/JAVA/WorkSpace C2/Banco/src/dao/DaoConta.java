package dao;

import java.sql.SQLException;
import java.util.ArrayList;

import model.Model;
import model.ModelCliente;
import model.ModelConta;
import util.Param;

public class DaoConta extends Dao {

	@Override
	protected Model getModelFromTable() throws SQLException {
		ModelConta conta = new ModelConta();
		conta.setIdconta( resultado.getInt("idconta") );
		conta.setIdcliente( resultado.getInt("idcliente") );
		conta.setNumero( resultado.getInt("numero") );
		conta.setSaldo( resultado.getDouble("saldo"));
		conta.setStatus( resultado.getString("status"));
		conta.setLimite( resultado.getInt("limite"));
		
		ModelCliente cliente = new ModelCliente();
		cliente.setIdcliente( resultado.getInt("idcliente") );
		cliente.setCpf( resultado.getString("cpf") );
		cliente.setNome( resultado.getString("nome"));
		cliente.setSobrenome( resultado.getString("sobrenome"));
		conta.setCliente(cliente);
				
		return conta;
	}
	
	public Model consultaPorId( int idconta ) {
		
		String sql = "select * from conta "+
					 " where idconta="+String.valueOf(idconta);
		this.executar(sql);
		return this.getResultadoSimples();
	}
	
	public ArrayList<Model> consultar( ArrayList<Param> params ) {		
		String where = getWhere(params);
		
		String sql = "select * from conta, cliente "+
					" where (conta.idcliente=cliente.idcliente) " +
					 ((where.length()>0)? " and " + where: "") +
				     " order by nome, sobrenome";
		this.executar(sql);
		return this.getResultado();
	}
	
	public boolean sacar ( Model model, double valor ) {
		ModelConta conta = (ModelConta)model;
		if (conta.sacar(valor)) {
			String sql = "insert into movimentacao values (null," + 
					String.valueOf(conta.getId()) + "," +
					"''," + 
					String.valueOf(valor)+ "," +
					"'debito')"; 
			this.executar(sql);
			this.salvar(conta);
			return true;
		} 
		return false;
	}
	
	public void depositar ( Model model, double valor ) {
		ModelConta conta = (ModelConta)model;
		
		conta.depositar(valor);
		
		String sql = "insert into movimentacao values (null," + 
				String.valueOf(conta.getId()) + "," +
				"''," + 
				String.valueOf(valor)+ "," +
				"'credito')";
		
		this.executar(sql);	
		this.salvar(conta);
		
		
	}
	
	public boolean salvar ( Model model ) {
		ModelConta conta = (ModelConta)model;
		
		String sql="";
		System.out.println("DEBUG1");
		if (conta.getIdconta()==-1) {
			sql = "insert into conta (idcliente, numero, saldo, status, limite) "
					+ "values ("           +
					conta.getIdcliente()   + ", " +
					conta.getNumero()      + ", " +
					conta.getSaldo()       + ", " +
					"'" +conta.getStatus() + "', " +
					conta.getLimite()+ ") ";
		} else {
			sql = " update conta set " +
		            "saldo = "   + conta.getSaldo() + ", " +
		            "status = '" + conta.getStatus()+ "', " +
		            "limite = "  + conta.getLimite()+ " " +
		            "where idconta=" + conta.getIdconta();			
		}
		boolean result = this.executar(sql);
		if (conta.getIdconta()==-1) {
			conta.setIdconta(getMysqlId());
			conta.getCliente();
		}
			
		return result; 		
	}
	
	public boolean remover ( Model model ) {
		ModelConta conta = (ModelConta)model;

		String sql="delete from conta "+
	               " where idconta="+conta.getIdconta();
		return this.executar(sql);		
	}

}
