package Model;

public class data {

	private int dia;
	private int mes;
	private int ano;
	
	public data (int dia, int mes, int ano) {
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	
	public int getDia() {
		return dia;
	}
	
	public void setDia(int dia) {
		this.dia = dia;
	}
	
	public int getMes() {
		return mes;
	}
	
	public void setMes(int mes) {
		this.mes = mes;
	}
	
	public int getAno() {
		return ano;
	}
	
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	public int diferencaAno( data other) { //formato da data: (2018)(09)(21) -> 20180921
		int d1 = (this.ano * 10000) + (this.mes * 100) + (this.dia); //deslocar digitos a esquerda
		int d2 = (other.ano * 10000) + (other.mes * 100) + (other.dia);
		return (d2 - d1)/10000;
	}
	
	public String toString() {
		return this.dia + "/" + this.mes + "/" + this.ano;
	}
}
