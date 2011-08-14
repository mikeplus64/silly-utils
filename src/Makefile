CC=gcc
CFLAGS=-O3
LDFLAGS=-lSDL -lSDL_gfx
DEST=..

all: flashing trip panic

flashing: 
	$(CC) flashing.c $(CFLAGS) $(LDFLAGS) -o flashing
	mv flashing $(DEST)

trip: 
	$(CC) trip.c $(CFLAGS) $(LDFLAGS) -o trip
	mv trip $(DEST)

panic: 
	$(CC) panic.c $(CFLAGS) $(LDFLAGS) -o panic
	mv panic $(DEST)

clean:
	rm $(DEST)/panic $(DEST)/trip $(DEST)/flashing
