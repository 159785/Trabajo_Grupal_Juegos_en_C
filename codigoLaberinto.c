#include <stdio.h> // entrada y salida de datos 
#include <stdlib.h> // nos ayuda con las funciones estandar, como rand y srand 
#include <time.h> // nos ayuda con el manejo del tiempo 

#define ANCHO 20 // aqui vamos a definir el ancho y el alto del laberinto 
#define ALTO 10


void generarLaberinto(char laberinto[ALTO][ANCHO]) {
    int i, j; // declaramos variables de interacion de filas y columnas del laberinto 
    
    // Inicializar el laberinto con paredes
    for (i = 0; i < ALTO; i++) { 
        for (j = 0; j < ANCHO; j++) {
            laberinto[i][j] = '*'; // Se asigna '*' a cada posición del laberinto
        }
    }
    
    // Generar caminos aleatorios dentro del laberinto 
    for (i = 1; i < ALTO - 1; i++) {
        for (j = 1; j < ANCHO - 1; j++) {
            if (rand() % 3 == 0) {
                laberinto[i][j] = ' ';
            }
        }
    }
    
    // Asegurar un camino desde la entrada hasta la salida
    for (i = 1; i < ALTO - 1; i++) {
        laberinto[i][1] = ' ';
    }
    for (j = 1; j < ANCHO - 1; j++) {
        laberinto[ALTO - 2][j] = ' ';
    }
    
    // Colocar entrada y salida
    laberinto[1][0] = 'E';
    laberinto[ALTO - 2][ANCHO - 1] = 'S';
}

void imprimirLaberinto(char laberinto[ALTO][ANCHO]) {
    int i, j;
    for (i = 0; i < ALTO; i++) {
        for (j = 0; j < ANCHO; j++) {
            printf("%c", laberinto[i][j]);
        }
        printf("\n");
    }
}

int resolverLaberinto(char laberinto[ALTO][ANCHO]) {
    int x = 1, y = 0; // Posición inicial (entrada)
    int pasos = 0;
    char movimiento;

    while (laberinto[y][x] != 'S') {
        imprimirLaberinto(laberinto);
        printf("Posicion actual: (%d, %d)\n", x, y);
        printf("\t IMPORTANTE. Recuerda que si el movimiento no es valido tienes oportunidad para que sigas intentandolo\n");
        printf("\t por esa razon mira el laberinto y analiza bien tu proximo movimiento\n");
        printf("Ingrese movimiento (a: arriba, b: abajo, c: izquierda, d: derecha): ");
        scanf(" %c", &movimiento);

        switch(movimiento) {
            case 'a':
                if (y > 0 && laberinto[y-1][x] != '*') y--;
                break;
            case 'b':
                if (y < ALTO-1 && laberinto[y+1][x] != '*') y++;
                break;
            case 'c':
                if (x > 0 && laberinto[y][x-1] != '*') x--;
                break;
            case 'd':
                if (x < ANCHO-1 && laberinto[y][x+1] != '*') x++;
                break;
            default:
                printf("Movimiento invalido.\n");
                continue;
        }

        pasos++;
    }

    return pasos;
}

int main() {
    char laberinto[ALTO][ANCHO];
    srand(time(NULL));

    generarLaberinto(laberinto);
    printf("Laberinto generado:\n");
    imprimirLaberinto(laberinto);

    printf("\nComienza a resolver el laberinto!\n");
    int pasos = resolverLaberinto(laberinto);

    printf("\n¡FELICIDADES! Has llegado a la salida en %d pasos.\n", pasos);

    return 0;
}
