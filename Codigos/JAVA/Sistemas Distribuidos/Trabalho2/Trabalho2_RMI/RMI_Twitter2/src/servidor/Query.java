package servidor;

import java.sql.*;

public class Query {
	public static Connection getConnection() throws SQLException {

        try {
            DriverManager.registerDriver(new org.postgresql.Driver());
            Class.forName("org.postgresql.Driver").getDeclaredConstructor().newInstance();

            Connection conn = DriverManager
                    .getConnection("jdbc:postgresql://localhost:5432/Twitter", "postgres", "root");
//			?useTimezone=true&serverTimezone=UTC
            return conn;

        } catch (Exception e) {
            System.out.println(e);
        }

        return null;
    }
}
