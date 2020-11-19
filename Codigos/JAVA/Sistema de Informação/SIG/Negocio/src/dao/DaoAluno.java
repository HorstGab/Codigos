package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DaoAluno {

    public int insereAluno(String nome, int idade, int ano, int serie, int curso, Connection con) throws SQLException {

        String sql = "INSERT INTO \"Aluno\" (\"NomeCompleto\", \"Idade\", \"Ano\",\"Serie\", \"idCurso\")" +
                " VALUES (?,?,?,?,?) RETURNING \"IdAluno\"";

        PreparedStatement create = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
        create.setString(1,nome);
        create.setInt(2, idade);
        create.setInt(3,ano);
        create.setInt(4,serie);
        create.setInt(5, curso);
        create.execute();
        ResultSet generatedKeys;
        try {
            generatedKeys = create.getGeneratedKeys();
            generatedKeys.next();
            return generatedKeys.getInt(1);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return 0;
        }
    }
    
    public int getIdAlunoPorNome (String nome, Connection con) throws SQLException{
    	
    	String sql = "SELECT \"IdAluno\" FROM \"Aluno\" WHERE (\"NomeCompleto\" = ?)";
    	
    	PreparedStatement stt = con.prepareStatement(sql);
		stt.setString(1, nome);
		ResultSet res = stt.executeQuery();
		if (!res.next()) return -1;
		
		return res.getInt("IdAluno");    	
    }
    
    public boolean consultarAlunoPorNome (String nome, Connection con) throws SQLException{
    	
    	String sql = "SELECT \"NomeCompleto\" FROM \"Aluno\" WHERE (\"NomeCompleto\" = ?)";
    	
    	PreparedStatement stt = con.prepareStatement(sql);
		stt.setString(1, nome);
		ResultSet res = stt.executeQuery();
		if (res != null) return true;
		
		return false;    	
    }
    
    public boolean validarAluno(String nome, Connection con) {
		
		try {
			if(consultarAlunoPorNome(nome, con)) return true;
		}catch(Exception e) {
			e.printStackTrace();
		}
		return false;
	}


}
