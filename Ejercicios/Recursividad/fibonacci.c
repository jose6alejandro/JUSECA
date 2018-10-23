#include <stdio.h>

int suma(int);

int main(){

int n = 6;

	printf("La suma fibonacci de %i es: %i\n", n, suma(n));

	return 0;
}

int suma(int n){
	
	if(n == 1){
		n = 1;

	}else
		n = n + suma(n-1);

return n;
}