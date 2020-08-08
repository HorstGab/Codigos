package view;

import java.util.ArrayList;

import javax.swing.table.AbstractTableModel;

import model.Model;


public class TableModel extends AbstractTableModel {	
	private static final long serialVersionUID = 1L;
	private String[] columnNames = { };
	private String[] fieldNames = { };

	private ArrayList<Model> array = null;

	public void setHeaders ( String[] columnNames, String[] fieldNames ) {
		this.columnNames = columnNames;
		this.fieldNames  = fieldNames;
	}
	
	public void setData ( ArrayList<Model> array  ) {
		this.array = array;		
		fireTableDataChanged();//indica que precisa atualizar a interface grafica 
	}
	
	public Model getModel ( int index ) {
		if (index>=0 && index <getRowCount()) {
			return array.get(index);
		}
		return null;
	}
	
	public int getColumnCount() {
		return columnNames.length;
	}

	public int getRowCount() {
		if (array==null) return 0;
		return array.size();
	}

	public String getColumnName(int col) {
		return columnNames[col];
	}

	public Object getValueAt(int row, int col) {
		if (array==null) return null;
		return array.get(row).get(fieldNames[col]);
	}


	/*
	 * Don't need to implement this method unless your table's editable.
	 */
	public boolean isCellEditable(int row, int col) {
		return false;
	}

	public void setValueAt(Object value, int row, int col) {
		//data[row][col] = value;
	}
		
	public void atualizar(Model model ) {
		
		int id = model .getId();
		for (int i=0; i<array.size(); i++ ) {
			if (array.get(i).getId()==id) {
				array.set(i, model );
				fireTableDataChanged();
				return;
			}				
		}
		
		// Se não encontrou então inclui
		array.add(0,model);
		fireTableDataChanged();
		
	}
	
	public void remover(Model model) {
		int id = model.getId();
		for (Model m : array) {
			if (m.getId()==id) {
				array.remove(m);
				fireTableDataChanged();
				return;
			}				
		}
	}

}
