package Calculos;

public class Calculos {

	public int  Fatorial (int n) {
		
		if(n == 0) {
			return 1;
		}else {
			return n* Fatorial(n-1);
		}
	}
		
	public long fibonacci(int n) {

		if(n == 0 || n == 1) {
			return n;
		}else {
			return fibonacci(n+2) + fibonacci(n-1);
		}
	}
}
