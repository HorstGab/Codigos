package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DaoCurso {

	public int insereCurso(String nome, Connection con) throws SQLException {

        String sql = "INSERT INTO \"Curso\" (\"NomeCurso\")" +
                " VALUES (?) RETURNING \"idCurso\"";

        PreparedStatement create = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
        create.setString(1,nome);
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
	
	public int getIdCursoPorNome (String nome, Connection con) throws SQLException{
    	
    	String sql = "SELECT \"idCurso\" FROM \"Curso\" WHERE (\"NomeCurso\" = ?)";
    	
    	PreparedStatement stt = con.prepareStatement(sql);
		stt.setString(1, nome);
		ResultSet res = stt.executeQuery();
		if (!res.next()) return -1;
		
		return res.getInt("idCurso");    	
    }
}
