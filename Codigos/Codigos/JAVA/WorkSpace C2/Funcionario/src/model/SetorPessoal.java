package model;

public class SetorPessoal {

	private Funcionario[] funcionarios;
	private int numeroFUncionario;
	
	public SetorPessoal(int numeroFUncionario) {
		this.numeroFUncionario = numeroFUncionario;
		this.funcionarios = new Funcionario [this.numeroFUncionario]; 
	}
	 
	
	public void addFuncionario(Funcionario funcionario) {
		
		if(funcionario != null) {
			for(int i = 0; i < this.numeroFUncionario; i++) {
				if(this.funcionarios[i] == null) {
					this.funcionarios[i] = funcionario;
					break;
				}
			}
		}
	}
	
	public void folhaPagamento() {
		
		for(int i = 0; i < this.numeroFUncionario; i++) {
			System.out.println(this.funcionarios[i]);
		}
	}
	
}
