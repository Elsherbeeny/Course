CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=First_Project

all: $(Project_name).bin $(Project_name).hex
	@echo "**************Finish************" 		
	



	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf 
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@ 

$(Project_name).hex:$(Project_name).elf
	$(CC)objcopy.exe -O ihex $< $@

clean_all: 
	rm *.o *.elf *.bin *.hex	
	
