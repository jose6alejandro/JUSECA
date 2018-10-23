#include <stdio.h>

int factorial(int);

int main(){

int n = 5;

	printf("El factorial de %i es: %i\n", n, factorial(n) ); 

	return 0;
}

int factorial(int n){

	if(n == 0){ 
		n = 1; 

	}else 
		n = n *factorial(n-1);  
	
	
return n;
}