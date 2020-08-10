package view;

import java.util.ArrayList;

import javax.swing.table.AbstractTableModel;

import model.Model;
import model.ModelCliente;

public class TableModelCliente extends AbstractTableModel {	
	private static final long serialVersionUID = 1L;
	private String[] columnNames = { "CPF", "Nome completo" };

	private ArrayList<Model> array = null;

	public void setData ( ArrayList<Model> array  ) {
		this.array = array;		
		fireTableDataChanged();
	}
	
	public ModelCliente getModel ( int index ) {
		if (index>=0 && index <getRowCount()) {
			return (ModelCliente)array.get(index);
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
		
		ModelCliente model = (ModelCliente)array.get(row);
		switch (col) {
			case 0: return model.getCpf();
			case 1: return model.getNome() + " " + model.getSobrenome();
		}
		return "";
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
		
	public void atualizar(ModelCliente modelCliente) {
		int id = modelCliente.getIdcliente();
		for (int i=0; i<array.size(); i++ ) {
			if (((ModelCliente)array.get(i)).getIdcliente()==id) {
				array.set(i, modelCliente);
				fireTableDataChanged();
				return;
			}				
		}
		
		// Se não encontrou então inclui
		array.add(0,modelCliente);
		fireTableDataChanged();
	}
	
	public void remover(ModelCliente modelCliente) {

		int id = modelCliente.getIdcliente();
		for (Model model : array) {
			if (((ModelCliente)model).getIdcliente()==id) {
				array.remove(model);
				fireTableDataChanged();
				return;
			}				
		}
	}

}
