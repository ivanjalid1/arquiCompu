// secuencia de leds donde se encienden los pares e impares y se va intercalando

#define GPIO_BASE   0x20200000
#define GPIO_DIR    0x04
#define GPIO_OUT    0x0C
#define DELAY_COUNT 1000000

void delay_routine(void) {
    volatile unsigned int i;
    for (i = 0; i < DELAY_COUNT; i++);  // Retardo aproximado
}

void franco_par (void){
    unsigned int i;
    for (i = 0; i <= 7; i += 2) {
        unsigned int i1 = (1 << i);
        leds(i1);
        delay_routine();
    }
}

void franco_impar (void){
    unsigned int i;
    for (i = 1; i <= 7; i += 2 ) {
        unsigned int i1 = (1 << i);
        leds(i1);
        delay_routine();
    }
}

void par_impar_alternado(void) {
    unsigned int repeticiones = 7;  
    unsigned int i;

    for (i = 0; i < repeticiones; i++) {
        franco_par();      
        delay_routine();   

        franco_impar();    
        delay_routine();   
    }

    leds(0x00);
}
