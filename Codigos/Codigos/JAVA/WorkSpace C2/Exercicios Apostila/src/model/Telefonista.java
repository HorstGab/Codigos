package model;

public class Telefonista extends Funcionario {

	private int estacaoTrabalho;
	
	public int getEstacao () {
		return this.estacaoTrabalho;
	}
	
	public void setEstacao (int estacaoTrabalho) {
		this.estacaoTrabalho = estacaoTrabalho;
	}
}
