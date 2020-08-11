package model;

public class Ponto {
	
	private int x;
	private int y;
	
	public Ponto ( int x, int y ) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
	
	public Ponto clone ( ) {
		return new Ponto ( this.x, this.y );
	}
	
	public String toString ( ) {
		return this.x + "," + this.y;
	}

}
