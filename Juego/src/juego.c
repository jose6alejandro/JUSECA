/*
	José Alejandro Castro
	Octubre, 2018
*/
#include "../include/juego.h"
#include "../include/pr1-ula.h"
#include "../include/preguntas.h"
#include "../include/colores.h"

/*
	Mapa del juego
*/
int mapa(char* jugador){

int numero;
int nivel = 0;
int verificar = 3;
int aux = 0;
int completado=0;
int puntos = 0; 

char boton;
char* Map =  "mplayer sonidos/mapa.wav </dev/null >/dev/null 2>&1 &";
char* N1 =  "mplayer sonidos/N1.mp3 </dev/null >/dev/null 2>&1 &";
char* N2 =  "mplayer sonidos/N2.mp3 </dev/null >/dev/null 2>&1 &";

	system(Map);

	do{

		limpiar();
		
		mostrarMapa(completado);
		printf(" %sJugador: %s %s\n",AMARILLO,BLANCO,jugador);
		printf(" %sPuntos : %s %i\t",AMARILLO,BLANCO,puntos);
		boton = leerTecla();

		if (boton == 81 || boton == 113){	
			system("killall -q  mplayer ");
			return 0;
		}

		if (boton == 49){

			if(completado == 0){

				system("killall -q  mplayer ");
				mostrarMapa(3);
				system(N1);
				numero=1;
				verificar = plantilla(numero);
				numero++;

				if(verificar != 0){

					mostrarMensaje(1);		
					puntos = 50;
					verificar = plantilla(numero);
					aux = 1;
					numero++;

					if(verificar == 1){ mostrarMensaje(1); }
				}	

				if(numero == 3){

					completado++;
					puntos += 50;
					system(Map);	
				}

			}else if(completado >= 1){

				printf("Nivel 1 completado\n");
				esperar(1);
			}

		}else if (boton == 50){
			
			if(completado == 1){

				system("killall -q  mplayer ");
				mostrarMapa(4);
				system(N2);

				if(aux != 0 ){

					do{
						verificar = plantilla(numero);

						if (verificar == 1){

							mostrarMensaje(1);
							numero++;
							nivel++;						
							puntos += 50;
						}

					}while(verificar != 0 && nivel < 4);

					aux = 2;
				}

				if(numero == 7){

					completado++;
					system(Map);
				}

			}else if(completado == 2){

				printf("Nivel 2 completado\n");
				esperar(1);
			}else{

				printf("Nivel 2 bloqueado\n");
				esperar(1);
			}

		}else if (boton == 51){
			
			if(completado == 2){

				system("killall -q  mplayer ");
				mostrarMapa(5);
				system(N1);

				if(nivel == 4){

					do{
						verificar = plantilla(numero);
						
						if (verificar == 1){

							mostrarMensaje(1);
							numero++;
							nivel++;						
							puntos += 50;
						}

					}while(verificar != 0 && nivel < 8);			
				}

				/*if(numero == 11){ completado++; }*/

			}else if(completado == 3){

				printf("Nivel 3 completado\n");
				esperar(1);
			}else{

				printf("Nivel 3 bloqueado\n");
				esperar(1);
			}
			
		}

	}while(verificar != 0 && numero != 11);

	system("killall -q  mplayer ");

	if (verificar == 0){

		mostrarMensaje(0);
		printf("\n\t\t\t     Conseguiste %i puntos\n\n",puntos);
		printf("\t\t\t    Presiona cualquier tecla\n");
		boton = leerTecla();	
	}

	if (numero == 11 ){
		mostrarMensaje(2);
		printf("\n\t\t\t     Conseguiste %i puntos\n\n",puntos);
		printf("\t\t\t    Presiona cualquier tecla\n");
		boton = leerTecla();
		system("killall -q  mplayer ");
	}

		/* Guardar historial */		
		FILE *escritura;
		int nbytes = strlen(jugador);
		escritura = fopen ("historial", "ab");
		fwrite (&nbytes, sizeof nbytes, 1, escritura);
	    fwrite (jugador, nbytes, 1, escritura);
	    fwrite (&puntos, sizeof(int), 1, escritura);//
		fclose(escritura);

}

/*
	Presentacion del juego
*/
void presentacion(){

 	int i; 

    mostrarLogo2(1);

  	for(i = 0; i < 100; i++){

	    barra(i,30);
	    esperarMilisegundos(90);
 	}
    	printf("\n\n");
}

/*
	Resaltar la opcion del menú
*/
void menu(char boton ){

	if((boton == 87) || (boton == 119) ){

		mostrarLogo(1);
	
	}else if((boton == 83) || (boton == 115) ){

		mostrarLogo(2);
	
	}else{ mostrarLogo(3); }
}

/*
	Resaltar la opcion del Sub-menú
*/
void subMenu(char boton2 ){
	
	if((boton2 == 87) || (boton2 == 119)){

		mostrarLogo(4);

	}else if((boton2 == 83) ||(boton2 == 115) ){

		mostrarLogo(5);

	}else{ mostrarLogo(6); }

}
/*
	Generar números aleatorios entre (0 - 3)
*/
int randOm(int opcion){

srand(time(NULL)); 
	
	int op1 = rand() % 4; 
	int op2 = rand() % 4;

	if(op2 == op1){

		do{

			op2 = rand() % 4;

		}while(op2 == op1);
	}

	int op3 = rand() % 4;

	if(op3 == op1 || op3 == op2){

		do{
			op3 = rand() % 4;

		}while((op3 == op1) || (op3 == op2) );
	}

	int op4 = rand() % 4;

	if(op4 == op1 || op4 == op2 || op4 == op3){
		do{
			op4 = rand() % 4;

		}while((op4 == op1 || op4 == op2 || op4 == op3));
	}


	if (opcion == 0 ){
		return op1+1;

	}else if(opcion == 1){
		return op2+1;

	}else if(opcion == 2){
		return op3+1;

	}

	return op4+1;
}

/*
	Mostrar logotipo y menú
*/
void mostrarLogo(int mostrar){

	if (mostrar < 8){

		printf("\n\n\n\n\n\n");
		printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
		printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
		AMARILLO, BLANCO, VERDE, BLANCO);
		printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
		AMARILLO, BLANCO, MAGENTA,NARANJA, BLANCO);
		printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
		AMARILLO, BLANCO, AZUL, BLANCO);
		printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");

	}else{

		printf("\n\n\n\n\n\n");
		printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
		printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
		GRIS, BLANCO, VERDE, BLANCO);
		printf("\t\t\t     █%s █  ▀%s   ▄▄▄   %sA   %sD%s █\n",
		GRIS, BLANCO, MAGENTA,NARANJA, BLANCO);
		printf("\t\t\t     █%s ▀▄▄▀%s  ─────    %sS%s   █\n", 
		GRIS, BLANCO, AZUL, BLANCO);
		printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
	}


	if(mostrar == 1){

		printf("%s", CYAN);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     JUGAR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     SALIR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
	
	}else if(mostrar == 2){

		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     JUGAR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", CYAN);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     SALIR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);

	}else if(mostrar == 3){

		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     JUGAR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║     SALIR     ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);

	}else 	if(mostrar == 4){

		printf("%s", CYAN);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ EMPEZAR JUEGO ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ INSTRUCCIONES ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
	
	}else if(mostrar == 5){

		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ EMPEZAR JUEGO ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", CYAN);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ INSTRUCCIONES ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);

	}else if(mostrar == 6){

		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ EMPEZAR JUEGO ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);
		printf("\t\t\t       ╔═══════════════╗\n");
		printf("\t\t\t       ║ INSTRUCCIONES ║\n");
		printf("\t\t\t       ╚═══════════════╝\n\n");
		printf("%s", BLANCO);

	}else if(mostrar == 7){

		printf("%s\t\t\t       GRACIAS POR JUGAR\n",
		BLANCO); 
	
	}else{

		printf("%s\t\t\t       GRACIAS POR JUGAR%s\n",
		CYAN, BLANCO); 
	}
}

/*
	Mapa del juego
*/
void mostrarMapa(int mostrar){

	if(mostrar == 0){

		printf("\n");
		printf("       	 %s▄       ▄█▄       ▄                                               \n", NARANJA);
		printf("       	%s▐█▌  %s▄  %s█████  %s▄%s  ▐█▌                                %s█%s▄%s██%s▄%s█%s\n",
		NARANJA2,NARANJA, NARANJA2, NARANJA, NARANJA2,GRIS, GRIS2, GRIS, GRIS2, GRIS, BLANCO);
		printf("         %s█  ███▄▄█▄█▄▄███  █                        %s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█%s▐█%s┼┼%s█▌%s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█\n",
		BLANCO,GRIS, GRIS2, GRIS, GRIS2, GRIS,GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2,GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("         %s█  █▄█▄█████▄█▄█  █                        %s█%s█%s█%s█%s█%s█%s┼%s█%s█▐████▌█%s█%s┼%s█%s█%s█%s┼%s█%s█\n",
		BLANCO, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS , GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2);
		printf("        %s██▄▄█▄█▄█ 1 █▄█▄█▄▄██                       %s█ %s2%s █%s█%s█%s█%s█%s▐█  █▌%s█%s█%s█%s█%s█%s█%s█%s█%s█\n",
		BLANCO, GRIS, BLANCO, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("        %s         ░░░                                 ░░░       ░░          \n", MARRON);
		printf("               ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░       ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               %s░░                                              ░░           \n",
		MARRON);
		printf("%s   ▄█▄         %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s ▄██◙██▄       %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s▀███████▀      %s░░                    %s▄█▀▄          ▄█▀▄%s        ░░     \n", 
		MARRON2,MARRON, AMARILLO, MARRON);
		printf("%s ██%s▄▀▄%s██       %s░░                  %s▄██▀▀▀▀▄      ▄██▀▀▀▀▄%s      ░░ \n", 
		MARRON2, BLANCO, MARRON2,MARRON,AMARILLO, MARRON);
		printf(" %s░░░░░░░░░░░░░░░░                %s▄███▀▀▀▀▀▀▀▄  ▄███▀▀▀▀▀▀▀▄%s    ░░       \n", 
		MARRON,AMARILLO, MARRON);
		printf("                                             %s▄█ %s3%s █▀▀▀▀▀▀▀▀▀▄%s  ░░     \n", 
		AMARILLO, BLANCO, AMARILLO, MARRON );
		printf("                                               %s░░░             ░░           \n",MARRON);
		printf("                                               ░░░░░░░░░░░░░░░░░░           %s\n", BLANCO);

	}else if(mostrar == 1){

		printf("\n");
		printf("       	  %sNIVEL COMPLETADO\n", VERDE);
		printf("       	 %s▄       ▄█▄       ▄                                               \n", NARANJA);
		printf("       	%s▐█▌  %s▄  %s█████  %s▄%s  ▐█▌                                %s█%s▄%s██%s▄%s█%s\n",
		NARANJA2,NARANJA, NARANJA2, NARANJA, NARANJA2,GRIS, GRIS2, GRIS, GRIS2, GRIS, BLANCO);
		printf("         %s█  ███▄▄█▄█▄▄███  █                        %s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█%s▐█%s┼┼%s█▌%s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█\n",
		BLANCO,GRIS, GRIS2, GRIS, GRIS2, GRIS,GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2,GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("         %s█  █▄█▄█████▄█▄█  █                        %s█%s█%s█%s█%s█%s█%s┼%s█%s█▐████▌█%s█%s┼%s█%s█%s█%s┼%s█%s█\n",
		BLANCO, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS , GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2);
		printf("        %s██▄▄█▄█▄█ 1 █▄█▄█▄▄██                       %s█ %s2%s █%s█%s█%s█%s█%s▐█  █▌%s█%s█%s█%s█%s█%s█%s█%s█%s█\n",
		BLANCO, GRIS, BLANCO, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("        %s         ░░░                                 ░░░       ░░          \n", MARRON);
		printf("               ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░       ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               %s░░                                              ░░           \n",
		MARRON);
		printf("%s   ▄█▄         %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s ▄██◙██▄       %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s▀███████▀      %s░░                    %s▄█▀▄          ▄█▀▄%s        ░░     \n", 
		MARRON2,MARRON, AMARILLO, MARRON);
		printf("%s ██%s▄▀▄%s██       %s░░                  %s▄██▀▀▀▀▄      ▄██▀▀▀▀▄%s      ░░ \n", 
		MARRON2, BLANCO, MARRON2,MARRON,AMARILLO, MARRON);
		printf(" %s░░░░░░░░░░░░░░░░                %s▄███▀▀▀▀▀▀▀▄  ▄███▀▀▀▀▀▀▀▄%s    ░░       \n", 
		MARRON,AMARILLO, MARRON);
		printf("                                             %s▄█ %s3%s █▀▀▀▀▀▀▀▀▀▄%s  ░░     \n", 
		AMARILLO, BLANCO, AMARILLO, MARRON );
		printf("                                               %s░░░             ░░           \n",MARRON);
		printf("                                               ░░░░░░░░░░░░░░░░░░           %s\n", BLANCO);
	
	}else if(mostrar == 2){

		printf("\n");
		printf("       	  %sNIVEL COMPLETADO                              NIVEL COMPLETADO\n", VERDE);
		printf("       	 %s▄       ▄█▄       ▄                                               \n", NARANJA);
		printf("       	%s▐█▌  %s▄  %s█████  %s▄%s  ▐█▌                                %s█%s▄%s██%s▄%s█%s\n",
		NARANJA2,NARANJA, NARANJA2, NARANJA, NARANJA2,GRIS, GRIS2, GRIS, GRIS2, GRIS, BLANCO);
		printf("         %s█  ███▄▄█▄█▄▄███  █                        %s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█%s▐█%s┼┼%s█▌%s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█\n",
		BLANCO,GRIS, GRIS2, GRIS, GRIS2, GRIS,GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2,GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("         %s█  █▄█▄█████▄█▄█  █                        %s█%s█%s█%s█%s█%s█%s┼%s█%s█▐████▌█%s█%s┼%s█%s█%s█%s┼%s█%s█\n",
		BLANCO, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS , GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2);
		printf("        %s██▄▄█▄█▄█ 1 █▄█▄█▄▄██                       %s█ %s2%s █%s█%s█%s█%s█%s▐█  █▌%s█%s█%s█%s█%s█%s█%s█%s█%s█\n",
		BLANCO, GRIS, BLANCO, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("        %s         ░░░                                 ░░░       ░░          \n", MARRON);
		printf("               ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░       ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               ░░                                              ░░             \n");
		printf("               %s░░                                              ░░           \n",
		MARRON);
		printf("%s   ▄█▄         %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s ▄██◙██▄       %s░░                                              ░░         \n", 
		MARRON2, MARRON);
		printf("%s▀███████▀      %s░░                    %s▄█▀▄          ▄█▀▄%s        ░░     \n", 
		MARRON2,MARRON, AMARILLO, MARRON);
		printf("%s ██%s▄▀▄%s██       %s░░                  %s▄██▀▀▀▀▄      ▄██▀▀▀▀▄%s      ░░ \n", 
		MARRON2, BLANCO, MARRON2,MARRON,AMARILLO, MARRON);
		printf(" %s░░░░░░░░░░░░░░░░                %s▄███▀▀▀▀▀▀▀▄  ▄███▀▀▀▀▀▀▀▄%s    ░░       \n", 
		MARRON,AMARILLO, MARRON);
		printf("                                             %s▄█ %s3%s █▀▀▀▀▀▀▀▀▀▄%s  ░░     \n", 
		AMARILLO, BLANCO, AMARILLO, MARRON );
		printf("                                               %s░░░             ░░           \n",MARRON);
		printf("                                               ░░░░░░░░░░░░░░░░░░           %s\n", BLANCO);
	
	}else if(mostrar == 3){

		limpiar();
		printf("\n\n\n\n");
		printf("\t\t\t       %sEL  PALACIO  BLINK\n\n", BLANCO);
		printf("\t\t\t       %s▄       ▄█▄       ▄\n", NARANJA);
		printf("\t\t\t      %s▐█▌  %s▄  %s█████  %s▄%s  ▐█▌\n",
		NARANJA2,NARANJA, NARANJA2, NARANJA, NARANJA2);
		printf("\t\t\t       %s█  ███▄▄█▄█▄▄███  █\n",
		BLANCO);
		printf("\t\t\t       %s█  █▄█▄█████▄█▄█  █\n",
		BLANCO);
		printf("\t\t\t      %s██▄▄█▄█▄█   █▄█▄█▄▄██\n",
		BLANCO);
		printf("\n\n\t  ► Se presentan 2 problemas para avanzar al siguiente nivel.\n\n");
		printf("\t  ► Debes estar muy atento y si es posible no parpadear.\n\n\n");
		printf("\t\t      %sPulsa cualquier tecla para empezar%s\n", CYAN, BLANCO);
		int boton = leerTecla();

	}else if(mostrar == 4){

		limpiar();
		printf("\n\n\n\n");
		printf("\t\t\t       %sEL  CASTILLO  PÍCON\n\n", BLANCO);
		printf("\t\t\t             %s█%s▄%s██%s▄%s█%s\n",
		GRIS, GRIS2, GRIS, GRIS2, GRIS, BLANCO);
		printf("\t\t\t    %s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█%s▐█%s┼┼%s█▌%s█%s▄%s█%s▄%s█%s▄%s█%s▄%s█\n",
		GRIS, GRIS2, GRIS, GRIS2, GRIS,GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2,GRIS, GRIS2, GRIS, GRIS2, GRIS);
		printf("\t\t\t    %s█%s█%s█%s█%s█%s█%s┼%s█%s█▐████▌█%s█%s┼%s█%s█%s█%s┼%s█%s█\n",
		GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS , GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2);
		printf("\t\t\t    %s█ %s %s █%s█%s█%s█%s█%s▐█  █▌%s█%s█%s█%s█%s█%s█%s█%s█%s█%s\n",
		GRIS, BLANCO, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, GRIS2, GRIS, BLANCO);
		printf("\n\n\t   ► Se presentan 4 problemas para avanzar al último nivel.\n\n");
		printf("\t   ► Los números y letras se desplazan por el castillo.\n\n");
		printf("\t   ► Identifíca los códigos que hacen que esto ocurra.\n\n\n");
		printf("\t\t      %sPulsa cualquier tecla para continuar%s\n", CYAN, BLANCO);
		int boton = leerTecla();

	}else{

		limpiar();
		printf("\n\n\n\n");
		printf("\t\t\t     %sLAS PIRÁMIDES DE EGIPTO\n\n", BLANCO);
		printf("%s\t\t\t      ▄█▀▄          ▄█▀▄\n", AMARILLO);
		printf("\t\t\t    ▄██▀▀▀▀▄      ▄██▀▀▀▀▄\n");
		printf("\t\t\t  ▄███▀▀▀▀▀▀▀▄  ▄███▀▀▀▀▀▀▀▄\n");
		printf("\t\t\t               ▄█  █▀▀▀▀▀▀▀▀▀▄%s\n", BLANCO); 
		printf("\n\t ► Se presentan los últimos 4 problemas para superar el juego.\n\n");
		printf("\t ► En las pirámides encontramos:\n\n\t\tDesde jeroglíficos hasta figuras hechas en código de C.\n\n");
		printf("\t ► La misión es decifrar los códigos que cumplen con las figuras.\n\n\n");
		printf("\t\t      %sPulsa cualquier tecla para continuar%s\n", CYAN, BLANCO);
		int boton = leerTecla();
	}

}

/*
	Mostrar mensajes
*/
void mostrarMensaje(int mostrar){

char* correcta =  "mplayer sonidos/correcta.mp3 </dev/null >/dev/null 2>&1 &";
char* incorrecta =  "mplayer sonidos/incorrecta.mp3 </dev/null >/dev/null 2>&1 &";
char* ganador =  "mplayer sonidos/ganador.mp3 </dev/null >/dev/null 2>&1 &";

	if(mostrar == 0){

		system(incorrecta);
		printf("\n\n\n\n\n\n");
		printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
		printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
		ROJO, BLANCO, VERDE, BLANCO);
		printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
		ROJO, BLANCO, MAGENTA,NARANJA, BLANCO);
		printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
		ROJO, BLANCO, AZUL, BLANCO);
		printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
		printf("%s", ROJO);
		printf("\t\t\t      ════════════════════\n");
		printf("\t\t\t      RESPUESTA INCORRECTA \n");
		printf("\t\t\t      ════════════════════\n\n");
		printf("%s", BLANCO);

	}else if(mostrar == 1){

		system(correcta);
		printf("\n\n\n\n\n\n");
		printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
		printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
		VERDE, BLANCO, VERDE, BLANCO);
		printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
		VERDE, BLANCO, MAGENTA,NARANJA, BLANCO);
		printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
		VERDE, BLANCO, AZUL, BLANCO);
		printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
		printf("%s", VERDE);
		printf("\t\t\t      ════════════════════\n");
		printf("\t\t\t       RESPUESTA CORRECTA \n");
		printf("\t\t\t      ════════════════════\n\n\n");
		printf("\t\t      %sPulsa cualquier tecla para continuar%s\n", VERDE, BLANCO);	
		int boton = leerTecla();
		system("killall -q  mplayer ");

	}else{

		int i;
		system(ganador);
		limpiar();

		for (i = 0; i < 20; ++i){

			printf("\n\n\n\n\n\n");
			printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
			printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
			AMARILLO, BLANCO, VERDE, BLANCO);
			printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
			AMARILLO, BLANCO, MAGENTA,NARANJA, BLANCO);
			printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
			AMARILLO, BLANCO, AZUL, BLANCO);
			printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
			printf("%s", VERDE);
			printf("\t\t        ═══════════════════════════════\n");
			printf("\t\t        FELICITACIONES GANASTE EL JUEGO \n");
			printf("\t\t        ═══════════════════════════════\n\n");
			printf("%s", BLANCO);

			esperarMilisegundos(100);
			limpiar();

			printf("\n\n\n\n\n\n");
			printf("%s", AMARILLO);
			printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
			printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
			VERDE, BLANCO, VERDE, AMARILLO);
			printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
			VERDE, BLANCO, MAGENTA,NARANJA, AMARILLO);
			printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
			VERDE, BLANCO, AZUL, AMARILLO);
			printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
			printf("%s", AMARILLO);
			printf("\t\t        ═══════════════════════════════\n");
			printf("\t\t        FELICITACIONES GANASTE EL JUEGO \n");
			printf("\t\t        ═══════════════════════════════\n\n");
			printf("%s", BLANCO);

			esperarMilisegundos(100);
			limpiar();
		}
			printf("\n\n\n\n\n\n");
			printf("%s", AMARILLO);
			printf("\t\t\t      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄\n");
			printf("\t\t\t     █ %s ▄▄ %s    ►      %sW%s   █\n",
			VERDE, BLANCO, VERDE, AMARILLO);
			printf("\t\t\t     █ %s█  ▀%s   ▄▄▄   %sA   %sD%s █\n",
			VERDE, BLANCO, MAGENTA,NARANJA, AMARILLO);
			printf("\t\t\t     █ %s▀▄▄▀%s  ─────    %sS%s   █\n", 
			VERDE, BLANCO, AZUL, AMARILLO);
			printf("\t\t\t      ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n\n");
			printf("%s", AMARILLO);
			printf("\t\t        ═══════════════════════════════\n");
			printf("\t\t        FELICITACIONES GANASTE EL JUEGO \n");
			printf("\t\t        ═══════════════════════════════\n\n");
			printf("%s", BLANCO);
	}

}

/*
	Barra de cargar el juego
*/
void barra(int incremento,int distancia){
  
  int i;
  printf("\r\t\t\t");

 	for(i = 0; i < distancia; i++){
    
	    if(incremento*distancia/100 < i)
	    	 printf("%s█",BLANCO);

	     else{
	  		printf("%s█%s",CYAN, BLANCO);
	  	} 	
 	}

	printf("%i%%",incremento+1);
} 

/*
	Mostrar logotipo secundario
*/
void mostrarLogo2(int mostrar){
	
	if(mostrar == 1){
		
		printf("\n\n\n\n");
		printf("\t\t\t            %s▄████▄  \n", AMARILLO);
		printf("\t\t\t           ▒██▀ ▀█  \n" );
		printf("\t\t\t           ▒▓█    ▄ \n" );
		printf("\t\t\t           ▒▓▓▄ ▄██▒\n" );
		printf("\t\t\t           ▒ ▓███▀ ░\n" );
		printf("\t\t\t           ░ ░▒ ▒  ░\n" );
		printf("\t\t\t           ░  ▒   \n" );
		printf("\t\t\t           ░        %s\n\n", BLANCO );
    
    }else{

		printf("\n");
		printf("\t\t\t            %s▄████▄  \n", AMARILLO);
		printf("\t\t\t           ▒██▀ ▀█  \n" );
		printf("\t\t\t           ▒▓█    ▄ \n" );
		printf("\t\t\t           ▒▓▓▄ ▄██▒\n" );
		printf("\t\t\t           ▒ ▓███▀ ░\n" );
		printf("\t\t\t           ░ ░▒ ▒  ░\n" );
		printf("\t\t\t           ░  ▒     %s\n", BLANCO);
    }  

}

/*
	Mostrar instrucciones del juego
*/
void mostrarInstrucciones(int mostrar){

    mostrarLogo2(2);
    
    if(mostrar == 1){

      printf("   INSTRUCCIONES:\n\n");
      printf("   Este es un juego inspirado en \"Desafío al saber\",  el cual consiste en\n");
      printf("   un conjunto de preguntas, que deben ser respondidas correctamente para\n");
      printf("   cumplir la misión de corregir los problemas que existen en 3 sitios alrededor\n");
      printf("   del mundo y que el jugador visitará al avanzar en el juego.\n\n");
      printf("   El juego se distribuye en 3 niveles: 2 problemas muy fáciles, 4 problemas \n");
      printf("   fáciles y 4 problemas intermedios.\n\n");
      printf("   El juego está elaborado por medio de la biblioteca pr1-ula.h y el objetivo\n");
      printf("   principal es el análisis de las animaciones presentadas para detectar\n");
      printf("   los códigos que corresponden a cada una ellas.\n\n");
      printf("   REGRESAR AL MENÚ %s(Q)%s                                VER CONTROLES %s(D)%s\n", 
      CYAN, BLANCO, NARANJA, BLANCO); 

    }else{

      printf("\t           Descripción                    Teclas\n\n");
      printf("\t           Regresar                       %s(Q)%s \n", CYAN, BLANCO);
      printf("\t           Mover abajo                    %s(S)%s \n", AZUL, BLANCO);
      printf("\t           Mover arriba                   %s(W)%s \n", VERDE, BLANCO);
      printf("\t           Mover derecha                  %s(D)%s \n", NARANJA, BLANCO);
      printf("\t           Mover izquierda                %s(A)%s \n\n", MAGENTA, BLANCO);

      printf("\t           Seleccionar opción en el menú  %s(ESPACIO)%s\n\n", ROJO, BLANCO);

      printf("\t                                          %s(1)%s \n", MARRON, BLANCO);
      printf("\t           Acceder a los niveles          %s(2)%s \n", MARRON, BLANCO);
      printf("\t                                          %s(3)%s \n\n", MARRON, BLANCO);
      printf("\t  REGRESAR AL MENÚ %s(Q)%s                    VER INSTRUCCIONES %s(D)%s\n", 
      CYAN, BLANCO, NARANJA, BLANCO); 

    }

}
