package model;

public class Funcionario {

	private String nome;
	private double salario;
	
	public String getNome () {
		return this.nome;
	}
	
	public void setNome (String nome) {
		this.nome = nome;
	}
	
	public double getSalario () {
		return this.salario;
	}
	
	public void setSalario (double salario) {
		this.salario = salario;
	}
	
	public double CalculaBonificacao () {
		return this.salario * 0.1;
	}
	
	public void aumentarSalario (double aumento) {
		if(aumento < 0) {
			IllegalArgumentException erro = new IllegalArgumentException();
			throw erro;
		}
	}
}
