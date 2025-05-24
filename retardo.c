#include <stdio.h>

void retardo(unsigned long int a) {
    while (a) {
        a--;
    }
}

int main() {
    printf("Iniciando retardo...\n");
    retardo(1000);
    printf("Retardo finalizado.\n");
    return 0;
}