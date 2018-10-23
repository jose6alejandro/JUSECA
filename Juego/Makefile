biblioteca = 32bits

dir = include/$(biblioteca)/

all: proyecto

proyecto:  src/juego.o main/main.o
	gcc $(dir)pr1-ula.o $(dir)preguntas.o src/juego.o main/main.o -o juego -lpthread

clear:
	rm  src/*.o main/*.o juego

