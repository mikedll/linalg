#	Author: Michael Rivera
#	Lab4 Makefile

CC = g++
CFLAGS = -Wall -W -Werror
OBJs = linalg.o \
Matrix.o \
RealNumber.o \

all: $(OBJs) prog

prog: $(OBJs)
	$(CC) $(CFLAGS) -o prog $(OBJs)

linalg.o: Matrix.h RealNumber.h
	$(CC) $(CFLAGS) -c linalg.cpp

RealNumber.o: RealNumber.h RealNumber.cpp
	$(CC) $(CFLAGS) -c RealNumber.cpp

Matrix.o: Matrix.h Matrix.cpp RealNumber.h
	$(CC) $(CFLAGS) -c Matrix.cpp

clean:
	rm prog *.o
