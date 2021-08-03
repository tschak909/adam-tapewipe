CC=zcc +coleco -pragma-redirect:CRT_FONT=_font_8x8_msx_system -subtype=adam
AS=z88dk-z80asm

all: tapewipe

clean:
	$(RM) -f tapewipe *.o *.ddp *bin

eoslib.o: eoslib.c
	$(CC) -o eoslib.o -c eoslib.c

main.o: main.c
	$(CC) -o main.o -c main.c

tapewipe: eoslib.o main.o
	$(CC) -otapewipe -create-app eoslib.o main.o
