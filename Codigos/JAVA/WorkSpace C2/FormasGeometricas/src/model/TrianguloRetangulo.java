package model;

public class TrianguloRetangulo extends Poligono {
	
	private Ponto  p1;
	private Ponto  p2;
	
	public TrianguloRetangulo ( int x1, int y1, int x2, int y2 ) {
		p1 = new Ponto ( x1, y1 );
		p2 = new Ponto ( x2, y2 );
	}

	public TrianguloRetangulo ( Ponto p1, Ponto p2 ) {
		this.p1 = p1.clone();
		this.p2 = p2.clone();
	}
		

	@Override
	public double getArea()  {		
		return (Math.abs(p2.getX() - p1.getX())*
				Math.abs(p2.getY() - p1.getY()))/2;		
	}
	
	public String toString () {
		return this.p1 + ", " + this.p2;
	}
	

}
