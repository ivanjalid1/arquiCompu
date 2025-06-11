.global franco_par
.global franco_impar
.global par_impar_alternado
.text

franco_par:
    push {r4-r11, lr}   
    ldr r0, =GPIO_BASE
    mov r4, #0xFF
    str r4, [r0, #GPIO_DIR] 
    mov r1, #0          

loop_par:
    mov r2, #1
    lsl r2, r2, r1      
    str r2, [r0, #GPIO_OUT] 
    bl delay_routine

    add r1, r1, #2      
    cmp r1, #7
    ble loop_par

    pop {r4-r11, lr}   
    bx lr              

franco_impar:
    push {r4-r11, lr}   
    ldr r0, =GPIO_BASE
    mov r4, #0xFF
    str r4, [r0, #GPIO_DIR] 
    mov r1, #1          

loop_impar:
    mov r2, #1
    lsl r2, r2, r1      
    str r2, [r0, #GPIO_OUT] 
    bl delay_routine

    add r1, r1, #2      
    cmp r1, #7
    ble loop_impar

    pop {r4-r11, lr}   
    bx lr              

par_impar_alternado:
    push {r4-r11, lr}   
    mov r4, #7          
    mov r5, #0          

loop_alternado:
    bl franco_par       
    bl delay_routine   
    bl franco_impar    
    bl delay_routine   

    add r5, r5, #1      
    cmp r5, r4          
    blt loop_alternado

    ldr r0, =GPIO_BASE
    mov r1, #0          
    str r1, [r0, #GPIO_OUT]

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