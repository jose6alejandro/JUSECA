#include <stdio.h>

int main(){

int i; 
char palabra[30] = {"Aprender"};

	for (i = 0; palabra[i]!= '\0'; ++i){}

	printf("La palabra: \"%s\" tiene %i letras\n",palabra ,i);


	return 0;
}