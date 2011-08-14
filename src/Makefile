CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lSDL -lSDL_gfx
SOURCES=flashing.c trip.c panic.c
EXES=${SOURCES:.c=}

all: ${EXES}
	
${EXES}: ${SOURCES}
	$(CC) $@.c $(LDFLAGS) $(CFLAGS) -o $@
