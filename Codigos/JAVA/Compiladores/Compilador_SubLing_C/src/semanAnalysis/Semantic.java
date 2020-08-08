package semanAnalysis;

import compilador.SimpleNode;
import compilador.Token;
import symtable.EntryTable;
import symtable.SymTable;

public class Semantic {

	private SymTable symb;
	private int foundSemanticError;
	
	public SymTable getSymb() {
		return symb;
	}
	public void setSymb(SymTable symb) {
		this.symb = symb;
	}
	public int getFoundSemanticError() {
		return foundSemanticError;
	}
	public void setFoundSemanticError(int foundSemanticError) {
		this.foundSemanticError = foundSemanticError;
	}
	
	public Semantic () {
		this.symb = new SymTable();
		this.foundSemanticError = 0;
	}
	
	public void programCheck(SimpleNode root) throws SemanticException{
		
		for(int i = 0; i < root.jjtGetNumChildren(); i++) {
			functlistCheck((SimpleNode) root.jjtGetChild(i));
		}

	}
	
	public void functlistCheck(SimpleNode node) throws SemanticException{
		if(node == null) return;
		
		if(node.jjtGetNumChildren() > 0) {
			try {
				functdeclCheck((SimpleNode) node.jjtGetChild(0));
			}catch(SemanticException e) {
				System.err.println(e.getMessage());
				this.foundSemanticError++;
			}
		}
		
		if(node.jjtGetNumChildren() > 1) {
			functdeclCheck((SimpleNode) node.jjtGetChild(1));
		}
	}
	
	public void functdeclCheck(SimpleNode node)throws SemanticException{
		
		if(node == null)return;
		int pos = this.symb.getPosicao();
		String funct_nome = node.value1;
		String retorno = null;
		
		if(funct_nome == null)return;
		if(node.jjtGetChild(0)!= null) 
			retorno = functtypeCheck((SimpleNode)node.jjtGetChild(0));
			System.out.println(retorno);
		

			//se funct nao estiver na tabela de simbolos
			if(this.symb.find(funct_nome, "global") == 0) {
				if(funct_nome.equals("main"))
					this.symb.add(new EntryTable(funct_nome, "keyword", "proc", retorno, "null", "global"));
				else
					this.symb.add(new EntryTable(funct_nome, "id", "proc", retorno, "null", "global"));
			}else {
				throw  new SemanticException("Funcao" + funct_nome + "já declarada");
			}
		
		
		if(node.jjtGetChild(1)!= null) {
			try {paramlistCheck((SimpleNode)node.jjtGetChild(1));}
			catch(SemanticException e) {
				System.out.println(e.getMessage());
				this.foundSemanticError++;
			}
		}
		
		if(node.jjtGetNumChildren() > 2) {
			if(node.jjtGetChild(2)!= null) 
				functbodyCheck((SimpleNode)node.jjtGetChild(2), pos);
		}
		System.out.println(symb.toString());
	}
	
	public String functtypeCheck (SimpleNode node)throws SemanticException{
		String tipo = node.value1;
		return tipo;
	}
	
	public void paramlistCheck(SimpleNode node)throws SemanticException{
		
		if(node.jjtGetNumChildren()== 0)return;
		String tipo1 = null, tipo2 = null, nome1 = null, nome2 = null;
		if(node.jjtGetChild(0)!=null) 
			tipo1 = functtypeCheck((SimpleNode)node.jjtGetChild(0));
		if(node.jjtGetChild(1)!=null)
			tipo2 = functtypeCheck((SimpleNode)node.jjtGetChild(1));
		
		nome1 = node.value1;
		if(node.value2 != null) nome2 = node.value2;
		
		this.symb.add(new EntryTable(nome1, "id", "parametro", tipo1, "0", "local"));
		if(nome2 != null) this.symb.add(new EntryTable(nome2, "id", "param", tipo2, "0", "local"));
	}
	
	public void functbodyCheck(SimpleNode node, int pos)throws SemanticException{
		if(node == null)return;
		for(int i = 0; i < node.jjtGetNumChildren(); i++) {
			SimpleNode filho = (SimpleNode)node.jjtGetChild(i);
			try {
				switch(filho.jjtGetId()) {
				case 4:
					varlistCheck(filho);
					break;
				case 8:
					ifCheck(filho);
					break;
				case 9:
					switchCheck(filho);
					break;
				case 10:
					forCheck(filho);
					break;
				case 11:
					whileCheck(filho);
					break;
				case 12:
					atribCheck(filho);
				case 7:
					returnCheck(filho, pos);
					break;
				}
			}catch(SemanticException e) {
				System.out.println(e.getMessage());
				this.foundSemanticError++;
			}
		}
	}
	
	public void varlistCheck(SimpleNode node) throws SemanticException{
		if(node == null) return;
		
		String tipo = node.value1;
		String nome = node.value2;
		
		if(this.symb.find(nome, "local") == 0) {
			this.symb.add(new EntryTable(nome, "id", "var", tipo, "0", "local"));
		}else {
			throw new SemanticException("Variavel "+ nome+ " já declarada!");
		}
	}
	
	public void ifCheck(SimpleNode node) throws SemanticException{
		if(node == null) return;
		String[] e = null;
		if(node.jjtGetChild(0) != null)
			e = expressaoCheck((SimpleNode)node.jjtGetChild(0));
		
		if(node.jjtGetChild(1) != null)
			functbodyCheck((SimpleNode)node.jjtGetChild(1), this.symb.getPosicao());
		
		if(node.jjtGetNumChildren() > 2) {
			if(node.jjtGetChild(2) != null)
				functbodyCheck((SimpleNode)node.jjtGetChild(2), this.symb.getPosicao());
		}
	}
	public void switchCheck(SimpleNode node) throws SemanticException{
	
	}
	public void forCheck(SimpleNode node) throws SemanticException{
		if(node == null) return;
		String[] e = null;
		if(node.jjtGetChild(0) != null)
			atribCheck((SimpleNode)node.jjtGetChild(0));
		
		if(node.jjtGetChild(1) != null)
			e = expressaoCheck((SimpleNode)node.jjtGetChild(1));
		
		if(node.jjtGetNumChildren() > 2) {
			if(node.jjtGetChild(2) != null)
				atribCheck((SimpleNode)node.jjtGetChild(2));
		}
	}
	public void whileCheck(SimpleNode node) throws SemanticException{
	
	}
	public void atribCheck(SimpleNode node) throws SemanticException{	
		if(node == null)return;
		String nome = node.value1;
		
		if(this.symb.find(nome)==0) {
			throw new SemanticException("Variavel "+ nome+ " nao foi declarada!");
		}else {
			String [] valor = expressaoCheck((SimpleNode)node.jjtGetChild(0));

		}
		
		
	}
	
	public String[] expressaoCheck(SimpleNode node) throws SemanticException{
		if(node == null)return null;
		String nome1[] = null, nome2[]=null;
		if(node.jjtGetNumChildren() == 0) return null;
		
		if(node.jjtGetChild(0)!= null) 
			nome1 = numexprCheck((SimpleNode)node.jjtGetChild(0));
		
		if(node.jjtGetNumChildren() > 1) {
			if(node.jjtGetChild(1)!= null)
				nome2 = numexprCheck((SimpleNode)node.jjtGetChild(1));
		}
		
		return new String[] {"bla"};
	}
	
	public String[] numexprCheck(SimpleNode node)throws SemanticException{
		if(node == null)return null;
		String nome = (node.value1 == null)? "Null": node.value1;
		
		Token num1 = null;
		if(node.jjtGetNumChildren() == 0)return null;
		if(node.jjtGetChild(0)!=null)
			num1 = termCheck((SimpleNode)node.jjtGetChild(0));
		
		Token num2 = null;
		if(node.jjtGetNumChildren() > 1) {
			if(node.jjtGetChild(1)!=null)
				num2 = termCheck((SimpleNode)node.jjtGetChild(1));
		}
		
		if(nome.equals("+")&& num2 != null) {
			switch(num1.kind) {
			case 1:
				break;
			}
			return new String [] {"blu"};
		}else if(nome.equals("-") && num2 != null) {
			return new String [] {"blu"};
		}
		else {
			return new String [] {nome};
		}
		
	}
	
	public Token termCheck(SimpleNode node)throws SemanticException{
		if(node == null)return null;
		String nome = (node.value1 == null)? "Null": node.value1;
		
		Token[] num1 = null;
		if(node.jjtGetNumChildren() == 0)return null;
		if(node.jjtGetChild(0)!=null)
			num1 = unaryexprCheck((SimpleNode)node.jjtGetChild(0));
		
		Token[] num2 = null;
		if(node.jjtGetNumChildren() > 1) {
			if(node.jjtGetChild(1)!=null)
				num2 = unaryexprCheck((SimpleNode)node.jjtGetChild(1));
		}
		
	
		if(nome.equals("*")&& num2 != null) {
			switch(num1[0].kind) {
			case 1:
				break;
			}
			return num1[0];
		}else if(nome.equals("/") && num2 != null) {
			return num1[0];
		}
		else {
			return num1[0];
		}
	}
	
	public Token[] unaryexprCheck (SimpleNode node) throws SemanticException{
		String nome = node.value1;
		
		if(nome != null) {
			Token a = factorCheck((SimpleNode)node.jjtGetChild(0));
			Token nomea = node.k;
			return new Token[] {a, nomea};
		}else {
			return new Token[] {factorCheck((SimpleNode)node.jjtGetChild(0)), null};
		}
	}
	
	public Token factorCheck(SimpleNode node) throws SemanticException{
		String not = node.value1;
		Token result = new Token(), var = node.k;
		if(var == null)return null;
		if(var.kind == 46) return null;
		else if(var.kind == 49) {
			if(this.symb.find(var.image) == 0)
				throw new SemanticException("Variavel "+ var.image +" nao declarada!");
			else {
				result.kind = var.kind;
				result.image = this.symb.getValor(var.image);
				if(var.image.equals("None")) return null;
				else return result;
			}
		}else if(var.kind == 35) {
			
			String[] exp = expressaoCheck((SimpleNode)node.jjtGetChild(0));
			result.image = exp[0];
			result.kind = Integer.parseInt(exp[1]);
			
			if(not.equals("None")) {
				return result;
			}
			else {
				if(result.kind == 44) {
					int img = Integer.parseInt(result.image);
					img = (img == 0)? 1: 0;
					result.image = Integer.toString(img);
					return result;
				}
			}
		}else {
		
			return var;
		}
		return var;
	}
	public void returnCheck(SimpleNode node, int pos) throws SemanticException{	

	}
}
