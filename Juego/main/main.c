/*
	José Alejandro Castro
	Octubre, 2018
*/
#include "../include/juego.h"
#include "../include/pr1-ula.h"
#include "../include/colores.h"

int main(){

limpiar();

char boton, boton2, boton3;
int opcion = 0, opcion2 = 0;
char jugador[100];

char* click =  "mplayer sonidos/click.mp3 </dev/null >/dev/null 2>&1 &"; 
char* click2 = "mplayer sonidos/click.flac </dev/null >/dev/null 2>&1 &";
char* inicio = "mplayer sonidos/ini.mp3 </dev/null >/dev/null 2>&1 &";
	
	system(inicio);
	presentacion();
	limpiar();
	mostrarLogo2(1);
	
	printf("\n\tIngrese su NOMBRE y pulsa ENTER: ");
	fgets(jugador, 100, stdin);
	char *nombre = jugador;
	
	limpiar();

	do{

		menu(boton);

		boton = leerTecla();

	  	switch(boton){
			
			case 87:	/* W */
			case 119:{	/* w */

				system(click);
		  		limpiar();
		  		opcion = 1;

	  		break;

			}
			case 83:	/* S */
			case 115:{	/* s */
				
				system(click);
		   		limpiar();
		  		opcion = 2;

	  		break;

	  		}
	  		case 32:{	/* Espacio */


		  		if (opcion == 1){

					system(click2);
		  			limpiar();
		  			
		  				do{
							subMenu(boton2);
							boton2 = leerTecla();

						  	switch(boton2){

								case 87:	/* W */
								case 119:{	/* w */

									system(click);
							  		limpiar();
							  		opcion2 = 1;

						  		break;
								}
								case 83:	/* S */
								case 115:{	/* s */
									
									system(click);
							   		limpiar();
							  		opcion2 = 2;

						  		break;
						  		}
						  		case 32:{	/* Espacio */	
							  		
							  		limpiar();

							  		if (opcion2 == 1){

							  			system(click2);
							  			mapa(nombre);
							  		}

							  		if(opcion2 == 2){

										system(click2);
							  			int mostrar = 1;
							  			mostrarInstrucciones(mostrar);

							  			do{
							  				boton = leerTecla();

							  				if(boton == 68 || boton == 100){ /*D || d*/

							  					system(click);
							  					limpiar();
							  					mostrar ++;
							  					mostrarInstrucciones(mostrar);

							  				}

							  				if(mostrar == 2){ mostrar = 0; }

							  			}while(boton != 81 && boton !=113);

							  			system(click2);
							  		}

							  		opcion2 = 0;
							  		limpiar();

						  		break;

						  		}
						  		case 81:	/* Q */
								case 113:{	/* q */

									system(click2);
						  			opcion = 0;
						  			opcion2 = 3;

						  		break;
						  		}
						  		default:
						  			limpiar();

						  	}

						}while( ((boton2 != 81) && (boton2 != 113)) || (opcion2 != 3));

		  			limpiar();
		  		
		  		}else if(opcion == 2){

		  			system(click2);
		  			int k;

		  			for (k = 0; k < 5; ++k){
		  				limpiar();
		  				mostrarLogo(7);
		  				esperarMilisegundos(100);
		  				limpiar();
		  				mostrarLogo(8);
		  				esperarMilisegundos(100);
		  			}
		  		esperar(2);
		  		limpiar();

		  		}else{ limpiar(); }

	  		break;
	  		}
	  		default:
	  			limpiar();
	  	}

	}while((boton != 32) || (opcion != 2));

	return 0;
}
