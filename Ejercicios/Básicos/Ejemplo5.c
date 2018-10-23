/*
Realice un programa usando la biblioteca PR1-ULA
para determinar cuantas vocales tiene una frase
y luego muestre por la pantalla el resultado.
*/

#include <stdio.h>

int main(){

int Cont[5] = {0,0,0,0,0};
int i = 0, j = 0;
char frase[30] = {"Hola mundo"};
	
	for (i = 0; frase[i]!='\0'; ++i){

		if(frase[i] == 'a' || frase[i] == 'A' ) Cont[0]++;
		if(frase[i] == 'e' || frase[i] == 'E' ) Cont[1]++;
		if(frase[i] == 'i' || frase[i] == 'I' ) Cont[2]++;
		if(frase[i] == 'o' || frase[i] == 'O' ) Cont[3]++;
		if(frase[i] == 'u' || frase[i] == 'U' ) Cont[4]++;
	}

	for (i = 0; i < 5; ++i)
		j += Cont[i];
		
	printf("La frase: \"%s\" tiene %i vocales.\n",frase, j);

	return 0;
}