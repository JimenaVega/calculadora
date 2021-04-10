CC	:= gcc
AS		:= nasm
ASFLAGS := -f elf

calc: clean addition.o calc.o
	$(CC) -m32 addition.o calc.o -o calc
# addition.o:
# 	nasm -f elf addition.asm
# calc.o:
# 	$(CC) calc.c -o calc.o

%.o: %.asm
	$(AS) $(ASFLAGS) $< 
clean:
	rm -f *.o addition calc
