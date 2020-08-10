package controller;

import java.util.Arrays;

import model.Conta;
import model.Funcionario;

public class ControlerMain {

	public static void main(String[] args) {
		
		
		int[] valores = {10, 50, 35, 45, 65, 75, 86, 84};
		int soma = 0;
		int i;
		
		//media
		for(i = 0; i < valores.length; i++) {
			soma += valores[i];
		}
		System.out.println("media: " + soma/valores.length);
		
		//maior valor
		Arrays.sort(valores);
		int x = valores.length;
		System.out.println("Maior Valor: " + valores[x - 1]);
		
		//numero de instancias
		Conta x1 = new Conta();
		System.out.println("Numero da Primeira Conta x1: " + x1.valor);
		
		Conta x2 = new Conta();
		System.out.println("Numero da Segunda Conta x2: " + x2.valor);


		System.out.println(x2);
		
		Conta.zerar();
		
		Funcionario f = new Funcionario();
		
		try {
			f.aumentarSalario(-100);
		}catch(IllegalArgumentException e) {
			System.out.println("Houve uma IllegalArgumentException ao aumentar o salário");
		}
		
	}

}
