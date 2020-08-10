package dao;

import java.sql.SQLException;
import java.util.ArrayList;

import model.Model;
import model.ModelCliente;
import model.ModelMovimentacao;
import util.Param;

public class DaoMovimentacao extends Dao {
	
	@Override
	protected Model getModelFromTable() throws SQLException {
		ModelMovimentacao model = new ModelMovimentacao();
		model.setIdmovimentacao(resultado.getInt("idmovimentacao") );
		model.setIdconta( resultado.getInt("idconta") );
		model.setDescricao( resultado.getString("descricao"));
		model.setValor( resultado.getDouble("valor"));
		model.setTipo( resultado.getString("tipo"));
		return model;
	}
	

	public ArrayList<Model> consultar( ArrayList<Param> params ) {
		String where = getWhere(params); 
		String sql = "select * from movimentacao "+
		             ((where.length()>0)? " where " + where: "") +
		             " order by idmovimentacao";
		this.executar(sql);
		return this.getResultado();
	}
	
	public boolean salvar ( Model model ) {
		ModelMovimentacao mov = (ModelMovimentacao)model;
		String sql="";
		
		if (mov.getId()==-1) {
			sql = "insert into movimentacao (idconta, descricao, valor, " +
				   "tipo) values (" +
		     mov.getIdconta()+", " +
		     "'"+ mov.getDescricao() + "', " +
		     mov.getValor()          + ", " +
			 "'"+mov.getTipo()       + "') ";
		} 
		boolean result = this.executar(sql);
		if (mov.getId()==-1) mov.setIdmovimentacao(getMysqlId());
		return result; 		
	}
	
	
	
	public boolean remover(Model model) {
		ModelCliente cliente = (ModelCliente)model;
		String sql = "delete from cliente " + " where idcliente = " + cliente.getIdcliente();
		
		return this.executar(sql);
	}
	
	
	
	
	
	
}
