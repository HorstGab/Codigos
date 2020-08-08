package model;

import java.lang.reflect.Field;

public abstract class Model {

	public abstract int getId();
	
	public Object get( String name)  {
		Field field;
		try {
			field = this.getClass().getDeclaredField(name);		
			return field.get(this);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;    	
	}
	
	public void set(String name, Object value)  {
		Field field;
		try {
			field = this.getClass().getDeclaredField(name);
			field.set(this, value);
		} catch (NoSuchFieldException | SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
