package controller;

import model.Node;

public class ControllerMain {

	public static void main(String[] args) {
		
		Node n = Node.montaExpressaoInFix("7 + 8 * 5");
		
		System.out.println(n.processa());
		System.out.println(n);
	}

}
