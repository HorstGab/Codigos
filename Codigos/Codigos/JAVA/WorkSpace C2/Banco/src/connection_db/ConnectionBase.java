package connection_db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * 
 * @author Teresinha Arnauts Hachisuca 
 */
public abstract class ConnectionBase {

	protected Connection db = null;
	protected Statement stmt = null;

	public Statement getStatement() {
		return stmt;
	}

	protected void connect ( String banco ) {
		String connect_str = "jdbc:mysql://localhost:3306/"+banco; 
		try {
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			if (this.db != null)
				this.db.close();
			db = DriverManager.getConnection(connect_str, "root", "root");
			createStatement();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	protected void createStatement() throws SQLException {
		if (this.stmt != null)
			this.stmt.close();

		stmt = db.createStatement();
	}

}
