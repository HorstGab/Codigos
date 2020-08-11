package model;

public class Circulo extends Poligono {
	
	private Ponto  p;
	private double r;
	
	public Circulo ( int x, int y, double r ) {
		p = new Ponto ( x, y );
		this.r = r;		
	}

	public Circulo ( Ponto p, double r ) {
		this.p = p.clone();
		this.r = r;		
	}		

	@Override
	public double getArea() {
		return Math.PI * Math.pow(r, 2);		
	}
	
	public String toString () {
		return this.p + ", " + r;
	}
	

}
