package controller;

import model.Produto;

public class ControllerMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Produto p = new Produto ( 1, "Arroz", 10, 15 );
		System.out.println(p);
		p.atualizaPreco(5);
		System.out.println(p);
	}

}
