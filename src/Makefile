IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g -std=c++11

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = tetromino.h grid.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = tetromino.o grid.o tetris.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

tetris: $(OBJ)
		$(CC) -o $@.bin $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
