package controller;

import model.Node;

public class ControllerMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Node node = new Node ( 10 );
		
		node.add(9);
		node.add(5);
		node.add(12);
		node.add(15);
		node.add(13);
		
		System.out.println(node);

	}

}
