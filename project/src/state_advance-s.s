  .arch msp430g 2553
  .p2align 1,0
  .text

; define switch
sw: .word case0
    .word case1
    .word case2
    .word case3
    
; method
    .global state_advance
; variables
    .extern switchSM
    
state_advance:
    cmp &switchSM, #4 ; if switchSm > 4 jump to end
    jnc end
    mov &switchSM, r12 ; move sw[switchSM] to r12
    add r12, r12
    mov sw(r12), r0
    
