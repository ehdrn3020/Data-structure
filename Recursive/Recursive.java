package test;

public class Recursive {

	/*
	Ex)1+1+2+3+5+8+13
	n= 6;
	fibonacci(n) =  8
	*/  
	
	public int fibonacci(int n) {
		if (n < 2)
			return n;
		else
			return fibonacci(n - 1) + fibonacci(n - 2);
	}
	
//The greatest common divisor
	public static int gcd(int m, int n){
		if(m<n){ 
			int tmp = n; m=n; n=tmp; 
		}
		if(m%n==0)
			return n;
		else
			return gcd(n,m%n);
		
		/* another version
		if (n == 0)
			return m;
		else
			return gcd(n, M % n);
		 */
	}
}
