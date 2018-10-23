#include <stdio.h>

int main(){

char palabra1 [30] = {"reconoce"};
char palabra2 [30] = {"reconocer"};
int cont1 = 0, cont2 = 0;

	while(palabra1[cont1]!='\0'){ cont1++;}
	while(palabra2[cont2]!='\0'){ cont2++;}

	if(cont1 > cont2){
		printf("La palabra: \"%s\" tiene mayor longitud que la palabra: \"%s\"\n", palabra1, palabra2);
	
	}else if(cont1 < cont2){
		printf("La palabra: \"%s\" tiene mayor longitud que la palabra: \"%s\"\n", palabra2, palabra1);

	}else
		printf("La palabra: \"%s\" tiene la misma longitud que la palabra: \"%s\"\n", palabra1, palabra2);

	return 0;
}