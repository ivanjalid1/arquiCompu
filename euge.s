.global leds_con_espacio
.text
leds_con_espacio:
    push {r4-r11, lr}   

    ldr r0, =GPIO_BASE
    mov r4, #0xFF
    str r4, [r0, #GPIO_DIR] 
    mov r1, #0          

loop:
    mov r2, #1          
    lsl r2, r2, r1      
    mov r3, #1          
    add r4, r1, #2      
    lsl r3, r3, r4
    orr r2, r2, r3      
    str r2, [r0, #GPIO_OUT] 
    bl delay_routine

    add r1, r1, #1      
    cmp r1, #5          
    ble loop

    pop {r4-r11, lr}   
    bx lr              

delay_routine:
    push {r3, lr}      
    ldr r3, =DELAY_COUNT
delay_loop:
    subs r3, r3, #1
    bne delay_loop
    pop {r3, lr}       
    bx lr

.data
.align 4
GPIO_BASE:    .word 0x20200000 
GPIO_DIR:     .equ 0x04       
GPIO_OUT:     .equ 0x0C       
DELAY_COUNT:  .word 1000000 