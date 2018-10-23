#include <stdio.h>

int buscar(int *, int, int );

int main(){

int tam = 5;
int array[5]={1, 9, 6, 7, 3};
int n = 6;

	
	printf("la posicion es: %i\n", buscar(array,tam,n));

	return 0;
}

int buscar(int *array, int tam, int n){

	if (tam != -1){
		
		if(n == array[tam]){
			return tam + 1;
		
		}else{
			tam = buscar(array, tam - 1, n);
		}
		
	}else{
		return -1;
	}
		
}