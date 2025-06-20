#define GPIO_BASE   0x20200000
#define GPIO_DIR    0x04
#define GPIO_OUT    0x0C
#define DELAY_COUNT 1000000

void delay_routine(void) {
    volatile unsigned int i;
    for (i = 0; i < DELAY_COUNT; i++);  // Retardo aproximado
}

void choque (void) {
    unsigned int i;
    unsigned int led_izquierda;
    unsigned int led_derecha;
    
    for (i = 0; i <= 4; i++) {
        led_izquierda = 1 << i;
        led_derecha = 1 << (7 - i);
        leds(led_izquierda | led_derecha);
        delay_routine();
    }

    for (i = 2; i >= 0; i--) {
        led_izquierda = 1 << i;
        led_derecha = 1 << (7 - i);
        leds(led_izquierda | led_derecha);
        delay_routine();
    }
}


