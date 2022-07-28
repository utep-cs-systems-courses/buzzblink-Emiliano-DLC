# makfile configuration
COMMON_OBJECTS  = main.o led.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o switches.o stateMachines.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button-c.elf: ${COMMON_OBJECTS}state_advance-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button-c.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
