package controller;

import model.Circulo;
import model.Poligono;
import model.Ponto;
import model.Retangulo;
import model.TrianguloRetangulo;

public class ControllerMain {

	
	
	
	public static void main(String[] args) {

		Ponto p = new Ponto ( 10, 10 );
				
		Poligono t  = new TrianguloRetangulo(10, 20, 20, 30);
		Poligono r  = new Retangulo(10, 20, 20, 30);
		Poligono c1 = new Circulo(p, 30);
		Poligono c2 = new Circulo(p, 40);
		
		System.out.println(t.getArea());
		System.out.println(r.getArea());
		System.out.println(c1.getArea());
		System.out.println(c2.getArea());
			
		System.out.println("Ponto: " +p);
		System.out.println(t);
		System.out.println(r);
		System.out.println(c1);
		System.out.println(c2);
		
		p.setX(50);
		System.out.println("Ponto: " +p);

		System.out.println(c1);
		System.out.println(c2);
				
	}
}
