#include <stdio.h>

int exponencial(int base, int exponente);

int main(){

int base = 3;
int exponente = 4;

	printf("%i ^ %i = %i\n", base, exponente, exponencial(base,exponente) );
	
	return 0;
}

int exponencial(int base, int exponente){

	if(exponente == 0){ 
		return 1; 
	
	}else if(exponente > 0){ 
		return base*(exponencial(base,exponente-1)); 
	}
}