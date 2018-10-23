#include <stdio.h>

int main(){

int cont = 0;
char palabra[30] = {"programar es divertido"};

	for (int i = 0; palabra[i]!= '\0'; ++i){
		
		if(palabra[i] ==  ' '){ cont++; }
	}

	printf("La frase: \"%s\" tiene %i palabras\n", palabra, cont + 1);


	return 0;
}