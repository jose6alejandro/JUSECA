#include <stdio.h>

int main(){


char palabra[30] = {"programar"};

	for (int i = 0; palabra[i]!= '\0'; ++i){
		
		if(palabra[i] ==  'a'){ palabra[i] = '6'; }
		
	}

	printf("La nueva palabra es: %s \n",palabra);


	return 0;
}