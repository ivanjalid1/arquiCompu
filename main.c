#include <stdio.h>

void mostrarMenu() {
    printf("Seleccione una opción:\n");
    printf("1. Opción 1\n");
    printf("2. Opción 2\n");
    printf("3. Salir\n");
    printf("Ingrese su opción: ");
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Opción 1 seleccionada.\n");
                break;
            case 2:
                printf("Opción 2 seleccionada.\n");
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Inténtelo nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}
