package model;

public class Funcionario {

	private int matricula;
	private String nome;
	private int departamento;
	private float salario;
	private String funcao;
	
	
	public Funcionario() {
		this.matricula = 0;
		this.nome = null;
		this.departamento = 0;
		this.salario = 0;
		this.funcao = null;
	}
	
	public Funcionario(int matricula, String nome, int departamento, float salario, String funcao) {
		this.matricula = matricula;
		this.nome = nome;
		this.departamento = departamento;
		this.salario = salario;
		this.funcao = funcao;
	}
	
	public String toString() {
		return "matricula: " + this.matricula + " " + this.nome + " departamento: " + this.departamento + " salario: " + this.salario + " funcao: " + this.funcao;
	}
	
}
