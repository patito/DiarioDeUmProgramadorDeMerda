CC      := gcc

CFLAGS  := -W -Wall -Werror -I.

BIN     := person

SRC := main.c person.c
OBJ := $(patsubst %.c,%.o,$(SRC))

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all: $(OBJ)
		$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

clean:
		$(RM) $(BIN) $(OBJ) *.o $(LIB)
