#include <stdio.h>

int main(){

char palabra1 [30] = {"reconoce"};
char palabra2 [30] = {"reconocer"};

int cont1 = 0, cont2 = 0;
int i = 0, j = 0, igual = 0;

	while(palabra1[cont1]!='\0'){ cont1++;}
	while(palabra2[cont2]!='\0'){ cont2++;}

	if(cont1 > cont2 || cont1 < cont2){
		printf("Las palabras: \"%s\" y \"%s\" son distintas \n", palabra1, palabra2);
	
	}else{
		
		while(palabra1[i]!='\0'){

			if(palabra1[i] != palabra2[j]){

				printf("La palabras: \"%s\" y \"%s\" son distintas \n", palabra1, palabra2);
				return 0;
			}

			i++, j++; 
		}
		
		printf("Las palabras: \"%s\" y \"%s\" son iguales \n", palabra1, palabra2);
	}
	return 0;
}