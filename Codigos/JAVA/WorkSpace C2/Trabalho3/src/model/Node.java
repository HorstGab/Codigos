package model;
import java.util.Stack;
import java.util.regex.Pattern;

import util.WrapperInt;


public abstract class Node {

	private String nome;
	protected Node esq;
	protected Node dir;
	private static Stack<Node> valor = new Stack<>();
	private static Stack<String> op = new Stack<>();
	
	//construct
	public Node(String nome) {
		this.nome = nome;
		this.esq = null;
		this.dir = null;
	}
	
	//setters
	public void setEsq (Node esq) {
		this.esq = esq;
	}
	public void setDir (Node dir) {
		this.dir = dir;
	}
	
	private static boolean isDouble (String s) {
		
		String reg = "^(-?\\\\d+)(\\\\.\\\\d+)?$";
		Pattern pattern = Pattern.compile(reg);
		return pattern.matcher(s).matches();
	}
	
	private static boolean isInt (String s) {
		String reg = "^(-?\\d+)$";
		Pattern pattern = Pattern.compile(reg);
		return pattern.matcher(s).matches();
	}
	
	public static Node montaExpressaoRec (String sl[], WrapperInt i) {
		Node node =  null;
		
		while(i.valor() < sl.length) {
			if(isInt(sl[i.valor()])) {
				valor.push(new NumeroInt(Integer.parseInt(sl[ i.valor()])));
			}
			
			if(isDouble( sl[ i.valor()])) {
				valor.push(new NumeroDouble(Double.parseDouble(sl[ i.valor()])));
			}
			
			if(sl[i.valor()].equals("(")){
				op.push(sl[i.valor()]);
			}
			
			if(sl[i.valor()].equals(")")){
				node = getOp(node);

				if(node != null){
					node.setEsq(valor.pop());
					node.setDir(valor.pop());
				}
				
				valor.push(node);
				op.pop();
			}
			
			if(sl[i.valor()].equals("+") || sl[i.valor()].equals("-") || sl[i.valor()].equals("*") || sl[i.valor()].equals("/")) {
				op.push(sl[i.valor()]);
			}
			
			if(valor.firstElement() != valor.lastElement()) {
				node = getOp(node);

				if(node != null){
					node.setEsq(valor.pop());
					node.setDir(valor.pop());
				}
				valor.push(node);
			}
			
			i.inc();
		}
		return valor.pop();
	}
	
	public static Node montaExpressaoInFix( String Expressão) {
		return montaExpressaoRec (Expressão.split(" "), new WrapperInt(0));
	}
	
	private static Node getOp(Node node) {
		switch(op.pop()) {
		case "+": node = new Soma(); break;
		case "-": node = new Subtração(); break;
		case "/": node = new Divisão(); break;
		case "*": node = new Multiplicação(); break;
		}
		return node;
	}
	
	public abstract double processa ();
	
	public String toString () {
		String s = "";
		
		if(this.esq != null) {
			s += this.esq;
		}
		
		s += this.nome;
		
		if(this.dir != null) {
			s += this.dir;
		}
		
		return s;
	}
}
