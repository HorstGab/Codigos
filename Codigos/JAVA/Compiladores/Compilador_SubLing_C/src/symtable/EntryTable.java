package symtable;

public class EntryTable {

	private String cadeia, token, categoria, tipo, valor, escopo;
	
	public EntryTable(String cad, String t, String cat, String tp, String v, String s) {
		this.cadeia = cad;
		this.token = t;
		this.categoria = cat;
		this.tipo = tp;
		this.valor = v;
		this.escopo = s;
	}

	public String getCadeia() {
		return cadeia;
	}

	public void setCadeia(String cadeia) {
		this.cadeia = cadeia;
	}

	public String getToken() {
		return token;
	}

	public void setToken(String token) {
		this.token = token;
	}

	public String getCategoria() {
		return categoria;
	}

	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}

	public String getValor() {
		return valor;
	}

	public void setValor(String valor) {
		this.valor = valor;
	}

	public String getEscopo() {
		return escopo;
	}

	public void setEscopo(String escopo) {
		this.escopo = escopo;
	}
	
	public String toString() {
		return this.cadeia + 		" || " 
				+ this.token + 		" || " 
				+ this.categoria + 	" || " 
				+ this.tipo + 		" || " 
				+ this.valor + 		" || " 
				+ this.escopo;
	}
}
