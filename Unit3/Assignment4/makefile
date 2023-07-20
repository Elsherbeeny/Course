#Done by Ahmed elsherbeeny
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name =CORTEXM4-DEBUG

all: $(project_name).bin
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) -mthumb $< -o $@

$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker.ld  $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf

	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

	
clean_all:
	rm *.o *.elf *.bin 

	

	