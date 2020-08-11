package Jogo;

import java.util.Random;

public class Craps {
	
	private Random random = new Random();
	
	private enum Status {CONTINUE, WON, LOST};
	
	private int lancarDados() {
		
		int d1 = random.nextInt(6) + 1;
		int d2 = random.nextInt(6) + 1;

		int soma = d1 + d2;
		
		System.out.printf("Jogada: %d + %d = %d \n", d1, d2, soma);
		
		return soma;
	}

	public void jogar () {
		int pontos = 0;
		Status status;

		int soma = lancarDados();

		switch (soma) {
		case 7:
		case 11:

			status = Status.WON;
			break;
		case 2:
		case 3:
		case 12: 

			status = Status.LOST;
			break;
		default://4,5,6,8,9,10
			pontos = soma;
			status = Status.CONTINUE;
			break;
		}

		while(status == Status.CONTINUE) {
			soma = lancarDados();

			if(soma == pontos) {
				status = Status.WON;			
			}
			if(soma == 7) {
				status = Status.LOST;
			}
		}
		
		if(status == Status.WON) {
			System.out.println("Jogador Ganha!");
		}else {
			System.err.println("Casa Ganha!");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new Craps().jogar();
		
	}

}
