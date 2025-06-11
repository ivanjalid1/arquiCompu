// Definición de los pines LED
const int led[] = {14,15,18,23,24,25,8,7}; 

#include <stdio.h>
#include <string.h>
#include "EasyPIO.h"

// constantes
#define PASSWORD "12345"
#define MAX_INTENTOS 3

// funciones externas
extern void autof(void);
extern void choque(void);
extern void leds_con_espacio(void);
extern void par_impar_alternado(void);

// funciones auxiliares
void mostrarMenu(void);
void disp_binary(int i);
int leds(int num);
void ingresarPassword(char *input);
int verificarPassword(void);
void retardo(unsigned long int a);

int main() {
    if (verificarPassword() == 1) {
        printf("Bienvenido al Sistema\n");
    } else {
        printf("Demasiados intentos. Abortando...\n");
        return 0;
    }

    pioInit();
    int i;
    for(i=0; i<8; i++){
        pinMode(led[i], OUTPUT); // Configure los 8 pines para los LEDs como salidas en main
    }
    leds(0xFF); //Turn off leds active low 

    int opcion;
    
    do {
        mostrarMenu();
        
        // Manejo de errores en scanf
        if (scanf("%d", &opcion) != 1) {
            // Limpiar buffer de entrada
            while (getchar() != '\n');
            opcion = 0; 
        }
        
        // Limpiar el buffer después de scanf
        while (getchar() != '\n' && getchar() != EOF);

        switch (opcion) {
            case 1:
                printf("Ejecutando Auto Fantástico. . .\n");
                autof();
                break;
            case 2:
                printf("Ejecutando Choque. . .\n");
                choque();
                break;
            case 3:
                printf("Ejecutando Par - Impar. . .\n");
                leds_con_espacio();
                break;
            case 4:
                printf("Ejecutando Luces de Navidad. . .\n");
                par_impar_alternado();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 5);

    return 0;
}

// Definiciones de funciones
void mostrarMenu() {
    printf("Seleccione una opción:\n");
    printf("1. Opción auto_fantástico\n");
    printf("2. Opción choque\n");
    printf("3. Opción par_impar\n");
    printf("4. Opción franco\n");
    printf("5. Salir\n");
    printf("Ingrese su opción: \n");
}

void disp_binary(int i) {
    int t;
    for (t = 128; t > 0; t = t/2) {
        if(i & t) printf("*");
        else printf("_");
    }
    printf("\n");
}

int leds(int num) {
    int i, numval;
  
    for(i = 0; i < 8; i++) {
        // Write the number to the 8 LEDs
        numval = (num >> i) & 0x01;
        digitalWrite(led[i], numval);
    }
    //delayMillis(3000); // Espera 3 segundos
  
    return 0;
}

void ingresarPassword(char *input) {
    printf("Ingrese su password de 5 dígitos: ");
    
    // Método más seguro usando fgets
    char temp[20];
    fgets(temp, sizeof(temp), stdin);
    
    // Copiar solo 5 caracteres máximo
    int i;
    for (i = 0; i < 5 && temp[i] != '\0' && temp[i] != '\n'; i++) {
        input[i] = temp[i];
    }
    input[i] = '\0';  // Asegurar terminación de cadena
}

int verificarPassword() {
    char input[6];
    int intentos = 0;
    int var = 0;

    while (intentos < MAX_INTENTOS) {
        ingresarPassword(input);

        if (strcmp(input, PASSWORD) == 0) {
            var = 1;
            break;
        } else {
            printf("Password no válida\n");
            intentos++;
        }
    }

    return var;
}

void retardo(unsigned long int a) {
    while (a) {
        a--;
    }
}