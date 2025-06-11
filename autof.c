#define GPIO_BASE   0x20200000
#define GPIO_DIR    0x04
#define GPIO_OUT    0x0C
#define DELAY_COUNT 1000000

void delay_routine(void) {
    volatile unsigned int i;
    for (i = 0; i < DELAY_COUNT; i++);
}

void autof(void) {
    unsigned int i;

    // Encendido de izquierda a derecha (bit 0 a bit 7)
    for (i = 0; i < 8; i++) {
        leds(1 << i);      // Enciende solo el bit i
        delay_routine();
    }

    // Encendido de derecha a izquierda (bit 6 a bit 0)
    for (i = 6; i > 0; i--) {
        leds(1 << i);      // Enciende solo el bit i
        delay_routine();
    }
}

