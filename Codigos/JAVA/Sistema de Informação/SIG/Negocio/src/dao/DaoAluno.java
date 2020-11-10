package dao;

import java.sql.*;

public class DaoAluno {

    public int insereAluno(String nome, int idade, int ano, int serie, Connection con) throws SQLException {

        String sql = "INSERT INTO \"Aluno\" (\"NomeCompleto\", \"Idade\", \"Ano\",\"Serie\")" +
                " VALUES (?,?,?) RETURNING \"idAluno\"";

        PreparedStatement create = con.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
        create.setString(1,nome);
        create.setInt(2, idade);
        create.setInt(3,ano);
        create.setInt(4,serie);
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


}
