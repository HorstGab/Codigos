package dao;

import unioeste.geral.parqueestudantil.bo.Curso;

import java.sql.*;
import java.util.ArrayList;

public class DaoCurso {

    public int InsereCurso(String nomeCurso, int ano, int serie, Connection con) throws SQLException {

        String SQL = "INSERT INTO \"Curso\" (\"nomeCurso\", \"ano\", \"serie\") VALUES (?,?,?) RETURNING \"idCurso\"";

        PreparedStatement create = con.prepareStatement(SQL, Statement.RETURN_GENERATED_KEYS);
        create.setString(1,nomeCurso);
        create.setInt(2, ano);
        create.setInt(3,serie);
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

    public ArrayList<Curso> consultarCurso(String nome, Connection con) throws SQLException {

        ArrayList<Curso> m = new ArrayList<>();
        String sql = "SELECT * FROM \"Curso\""
                + " WHERE \"nomeCurso\" = ?;";

        PreparedStatement stt = con.prepareStatement(sql);
        stt.setString(1, nome);
        ResultSet res = stt.executeQuery();

        int i = 0;
        while (res.next()) {

            Curso curso = new Curso();

            curso.setId(res.getInt("idevento"));
//            curso.setNomeCurso(res.getString("nome"));
            curso.setAno(res.getInt("ano"));
            curso.setSerie(res.getInt("serie"));

            m.add(i, curso);
            i++;
        }

        return m;
    }

}
