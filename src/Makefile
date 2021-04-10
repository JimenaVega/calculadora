
AS		:= nasm
ASFLAGS := -f elf
CFLAGS	:= -m32
LDFLAGS := -m32
CC		:= gcc
CXX		:= g++
CXXFLAGS := -m32
TARGETS := addition

.PHONY: clean

%.o: %.asm
	$(AS) $(ASFLAGS) $< 

all: $(TARGETS) 

addition: calc.o

clean :
	rm -f *.o $(TARGETS)