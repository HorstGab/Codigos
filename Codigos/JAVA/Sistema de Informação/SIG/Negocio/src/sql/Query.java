package sql;

import java.sql.*;
import java.util.ArrayList;

public class Query {
    public static int getId(Connection conn, String query) throws SQLException {

        try {
            PreparedStatement stat = conn.prepareStatement(query);

            ResultSet res = stat.executeQuery();
            if (res.next())
                return res.getInt(1);
            else
                return 0;
        } catch (Exception e) {
            System.out.println(e);
        }
        return 0;
    }

    public static ArrayList<String> getTabela(Connection conn, String query) throws Exception {
        try {

            PreparedStatement stat = conn.prepareStatement(query);

            ResultSet res = stat.executeQuery();
            ArrayList<String> cliente = new ArrayList<String>();
            ResultSetMetaData rsmd = res.getMetaData();
            int colunas = rsmd.getColumnCount();
            res.next();
            for (int i = 1; i <= colunas; i++) {

                cliente.add(res.getString(i));
            }

            return cliente;

        } catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    public static void insertSQLComand(Connection conn, String query) throws Exception {
        try {

            PreparedStatement create = conn.prepareStatement(query);
            create.executeUpdate();

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static Connection getConnection() throws SQLException {

        try {
            DriverManager.registerDriver(new org.postgresql.Driver());
            Class.forName("org.postgresql.Driver").getDeclaredConstructor().newInstance();

            Connection conn = DriverManager
                    .getConnection("jdbc:postgresql://localhost:5432/Evento", "postgres", "root");
//			?useTimezone=true&serverTimezone=UTC
            return conn;

        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }
}
