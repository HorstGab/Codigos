package dao;

import java.sql.SQLException;
import java.util.ArrayList;

import model.Model;
import model.ModelCliente;
import util.Param;

public class DaoCliente extends Dao {
	
	@Override
	protected Model getModelFromTable() throws SQLException {
		ModelCliente model = new ModelCliente();
		model.setIdcliente( resultado.getInt("idcliente") );
		model.setCpf( resultado.getString("cpf") );
		model.setNome( resultado.getString("nome"));
		model.setSobrenome( resultado.getString("sobrenome"));
		return model;
	}
	
	public ArrayList<Model> consultarTodos( ) {
		String sql = "select * from cliente order by nome, sobrenome";
		this.executar(sql);
		return this.getResultado();
	}
	
	public ArrayList<Model> consultar( ArrayList<Param> params ) {
		String where = getWhere(params); 
		String sql = "select * from cliente "+
		             ((where.length()>0)? " where " + where: "") +
		             " order by nome, sobrenome";
		this.executar(sql);
		return this.getResultado();
	}
	
	public Model consultaPorId( int idcliente ) {
		
		String sql = "select * from cliente "+
					 " where idcliente="+String.valueOf(idcliente);
		this.executar(sql);
		return this.getResultadoSimples();
	}

	
	public boolean salvar ( Model model ) {
		ModelCliente cliente = (ModelCliente)model;
		String sql="";
		System.out.println("DEBUG");
		if (cliente.getIdcliente()==-1) {
			sql = "insert into cliente (cpf, nome, sobrenome) values (" +
		     "'"+cliente.getCpf()+"', " +
		     "'"+cliente.getNome()+"', " +
			 "'"+cliente.getSobrenome()+"') ";
		} else {
			sql = " update cliente set " +
		            "cpf = '"+cliente.getCpf() + "', " +
		            "nome = '"+cliente.getNome() + "', " +
		            "sobrenome = '"+cliente.getSobrenome() + "' " +
		            "where idcliente=" + cliente.getIdcliente();			
		}
		boolean result = this.executar(sql);
		if (cliente.getIdcliente()==-1) cliente.setIdcliente(getMysqlId());
		return result; 		
	}
	
	public boolean remover ( Model model ) {
		ModelCliente cliente = (ModelCliente)model;
		String sql="delete from cliente "+
	               " where idcliente="+cliente.getIdcliente();
		return this.executar(sql);		
	}

}
