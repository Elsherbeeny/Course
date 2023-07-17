#Done by Ahmed elsherbeeny
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name =CORTEXM3-S

all: $(project_name).bin
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) -mthumb $< -o $@
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker.ld  $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	

	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

	
clean_all:
	rm *.o *.elf *.bin 

	

	