// enciende dos luces que tengan una diferencia de uno entre ella
// ej: (led0, led2) , (le1, led3)

#define GPIO_BASE   0x20200000
#define GPIO_DIR    0x04
#define GPIO_OUT    0x0C
#define DELAY_COUNT 1000000

void delay_routine(void) {
    volatile unsigned int i;
    for (i = 0; i < DELAY_COUNT; i++);  // Retardo aproximado
}

void leds_con_espacio(void) {
    unsigned int i;
    for (i = 0; i <= 5; i++) {
        unsigned int i1 = (1 << i) | (1 << (i + 2));
        leds(i1);       // Enciende dos LEDs con uno apagado entre medio
        delay_routine();
    }
}
