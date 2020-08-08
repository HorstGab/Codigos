package model;

import java.util.Scanner;

public class Vetor {

	int[] array = new int[5];
	
	public void ler () {
		Scanner scanner = new Scanner(System.in);
		
		int i = scanner.nextInt();
		int j = 0;
		while (i != 0){
			array[j] = i;
			i = scanner.nextInt();
			j++;
		}
		
		scanner.close();
	}
		
		public void mostrar() {
			
			int i;
			for(i = 0; i < array.length; i++) {
				if(array[i] != 0) System.out.println(array[i]);
			}
		}
	
		
}
