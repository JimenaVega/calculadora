
AS:=nasm
ASFLAGS:=-f elf
CFLAGS:=-m32
LDFLAGS:=-m32
CC:=gcc
CXX:=g++
CXXFLAGS:=-m32
TARGETS:=calculator

.PHONY:clean

%.o:%.asm
	$(AS) $(ASFLAGS) $< 

all:clean $(TARGETS)

calculator:calc.o

clean :
	rm -f *.o $(TARGETS)