# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: Main.elf 

#additional rules for files
Main.elf: ${COMMON_OBJECTS} Main.o stateMachines.o led.o function.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o Main.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: Main.elf
	msp430loader.sh Main.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

function.o: stateMachines.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

buzzer.c: buzzer.h

buzzerMain.c: buzzer.h

p2_interrupt_handler.o: p2_interrupt_handler.c
