# makfile configuration
COMMON_OBJECTS  = main.o led.o buzzer.o p2_interrupt_handeler.o wdInterruptHandler.o switches.o statemachines.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} led.o switches.o buzzer.o main.o p2_interrupt_handler.o wdInterruptHandler.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
