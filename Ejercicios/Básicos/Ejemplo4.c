#include <stdio.h>

int main(){

int i = 0, Cont = 0;
char frase[30] = {"Hola mundo"};
	
	for (i = 0; frase[i]!='\0'; ++i){

		if(frase[i] != 'a' && frase[i] != 'A' 
		&& frase[i] != 'e' && frase[i] != 'E'
		&& frase[i] != 'i' && frase[i] != 'I'
		&& frase[i] != 'o' && frase[i] != 'O' 
		&& frase[i] != 'u' && frase[i] != 'U' 
		&& frase[i] != ' ' && frase[i] != ',')
			Cont++;
	}	

	printf("La frase: \"%s\" tiene %i consonantes.\n",frase, Cont);

	return 0;
}