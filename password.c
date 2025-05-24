#include <stdio.h>
#include <string.h>

#define PASSWORD "12345"
#define MAX_INTENTOS 3

void ingresarPassword(char *input) {
    printf("Ingrese su password de 5 dígitos: ");
    int i;
    for (i = 0; i < 5; i++) {
        input[i] = getchar(); // Leer carácter por carácter
        printf("*");         // Mostrar asterisco
    }
    input[5] = '\0'; // Agregar terminador de cadena
    getchar();       // Consumir el carácter de nueva línea
    printf("\n");
}

int main() {
    char input[6];
    int intentos = 0;

    while (intentos < MAX_INTENTOS) {
        ingresarPassword(input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("Bienvenido al Sistema\n");
            return 0;
        } else {
            printf("Password no válida\n");
            intentos++;
        }
    }

    printf("Demasiados intentos. Abortando...\n");
    return 1;
}
