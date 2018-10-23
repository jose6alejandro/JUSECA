#include <stdio.h>

int main(){

char palabra [30] = {"reconocer"}; /* ana, sometemos, radar */
int tam = 0;
int der, izq;
int bandera = 1;

	while(palabra[tam] != '\0'){ tam++; }

	for (der = 0, izq = tam -1; palabra[der]!='\0'; der++, izq-- ){
	
		if(palabra[der] != palabra [izq]){ bandera = 0; }
	}

	if(bandera == 0){
		printf("La palabra: \"%s\" NO es palindromo\n", palabra); 
	
	}else{
		printf("La palabra: \"%s\" es palindromo\n", palabra);		
	}


	return 0;
}