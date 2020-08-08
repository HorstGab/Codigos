package model;

public class Node {
	
	private int value;
	private Node left;
	private Node right;
	
	public Node ( int value ) {
		this.value = value;
		this.left  = null;
		this.right = null;
	}
	
	public void add ( int value ) {
		if (this.value>value) {
			if (this.left==null) {
				this.left = new Node(value);
			} else {
				this.left.add(value);
			}
		} else {
			if (this.right==null) {
				this.right = new Node(value); 
			} else {
				this.right.add(value);
			}
		}
	}
	
	// in ordem
	public String toString () {
		String s = "";
		if (this.left!=null) {
			s += this.left;
		}
		s += this.value + " ";
		if (this.right!=null) {
			s += this.right;
		}
		return s;
	}

}
