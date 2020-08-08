package controller;

import model.Funcionario;
import model.SetorPessoal;

public class ControllerMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		

		Funcionario pessoa1 = new Funcionario(1, "Gabriel Horst", 1, (float)1000.50, "Gerente");
		Funcionario pessoa2 = new Funcionario(2, "Iraci Horst", 2, (float)1000, "Diretor");

		SetorPessoal setor = new SetorPessoal(2);

		
		setor.addFuncionario(pessoa1);
		setor.addFuncionario(pessoa2);
		
		setor.folhaPagamento();
	}

}
