#include <stdio.h>

int main(){

	char palabra[30] ={"programar"};
	char aux;
	int i;
	 
	 while(palabra[i] != '\0'){ i++; }

	aux = palabra[i/2];
	palabra[i/2] = palabra[0];
	palabra[0] = aux;

	printf("La nueva palabra es %s\n", palabra);

	return 0;
}