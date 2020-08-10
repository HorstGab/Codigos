package dao;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import model.Model;
import singleton.SingletonDb;
import util.Param;

public abstract class Dao {

	protected ResultSet resultado = null;

	protected abstract Model getModelFromTable ( ) throws SQLException; 

	protected boolean executar( String sql ) {
		try {
			SingletonDb.getInstance().getStatement().execute(sql);
			System.out.println(sql);
			this.resultado = SingletonDb.getInstance().
					getStatement().getResultSet();
		} catch (SQLException e) {
			System.out.println("N foi");
			e.printStackTrace();
			return false;
		}
		return true;
	}

	protected ArrayList<Model> getResultado () {
		ArrayList<Model> array = new ArrayList<Model>();
		try {
			this.resultado.beforeFirst();
			while (this.resultado.next()) {				
				array.add( getModelFromTable ( ) );
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return array;
	}
	
	protected Model getResultadoSimples () {		
		try {
			this.resultado.beforeFirst();
			if (this.resultado.next()) {				
				return getModelFromTable ( );
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	protected Integer getMysqlId() {
		try {
			ResultSet rs = SingletonDb.getInstance().getStatement().getGeneratedKeys();
			if (rs.next()){
				return rs.getInt(1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return -1;
	}

	protected String getWhere ( ArrayList<Param> params ) {
		String where="";
		for (Param param : params) {
			if (where.length()>0) {
				where += " and ";
			}
			if (param.getTipo() == Param.Tipo.STRING) {
				where += "(" + param.getNome() +
						" like '%" + param.getValor() + "%')"; 
			} else {
				where += "(" + param.getNome() +
						"=" + param.getValor() + ")"; 				
			}			
		}
		return where;
	}

}
