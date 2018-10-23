#ifndef JUEGO_H
#define JUEGO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mapa(char*);
int randOm(int);

void presentacion();
void menu(char);
void subMenu(char);
void mostrarLogo(int);
void mostrarLogo2();
void mostrarMapa(int);
void mostrarMensaje(int);
void barra(int,int);
void mostrarInstrucciones(int);

#endif