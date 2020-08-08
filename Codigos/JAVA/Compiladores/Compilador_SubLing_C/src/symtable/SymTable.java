package symtable;

import java.util.ArrayList;

public class SymTable {

	private ArrayList<EntryTable> table;
	private int posicao;
	
	public SymTable() {
		this.table = new ArrayList<EntryTable>();
		this.posicao = 0;
	}
	
	public ArrayList<EntryTable> getTable() {
		return table;
	}
	public void setTable(ArrayList<EntryTable> table) {
		this.table = table;
	}
	public int getPosicao() {
		return posicao;
	}
	public void setPosicao(int posicao) {
		this.posicao = posicao;
	}
	
	public void add(EntryTable entry) {
		this.table.add(entry);
		this.posicao++;
	}
	
	public int find(String nome) {
		for(EntryTable a : table) {
			if(a.getCadeia()==null)return 0;
			if(a.getCadeia().equals(nome)) {
				return 1;
			}
		}
		return 0;
	}
	
	public int find (String nome, String escopo) {
		for(EntryTable a : table) {
			if(a.getCadeia().equals(nome) && a.getEscopo().equals(escopo)) {
				return 1;
			}
		}
		return 0;
	}
	
	public String getValor(String img) {
		for(EntryTable a : table) {
			if(a.getCadeia().equals(img)) {
				return a.getValor();
			}
		}
		return "Null";
	}
	
	public String getType(int pos2) {
		return table.get(pos2).getTipo();
	}
	
	public String toString() {
		String print = "pos = " + this.posicao;
		
		for (EntryTable a: table) {
			print += "\n[";
			print += a.toString();
			print += "]";
		}
		return print;
	}
}
