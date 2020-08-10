package singleton;

import java.sql.SQLException;

import connection_db.ConnectionBase;

/**
 * 
 * @author Teresinha Arnauts Hachisuca
 */
public class SingletonDb extends ConnectionBase  {
	
	private static SingletonDb me = new SingletonDb(); 
	
	private SingletonDb() {
	}

	public static SingletonDb getInstance() throws SQLException {
		
		if (me.stmt==null) {
			me.connect( "banco" );
		}
				
		return me;
	}
		
	public String toString () {
		try {
			return "Status connection Banco database: " + (me.db.isClosed()? "closed" : "open");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "";
	}
}
