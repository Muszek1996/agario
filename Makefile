CFLAGS=-Wall -std=c++14

ifdef DEBUG
	CFLAGS+=-g3
endif

all:
	g++ $(CFLAGS) *.cpp -o exec -lsfml-graphics -lsfml-window -lsfml-system

#example: example.o
#	g++ example.o -o example -lsfml-graphics -lsfml-window -lsfml-system -lBox2D

#EXAMPLE
#example.o: example.cpp
#	g++ $(CFLAGS) -c example.cpp -o example.o

#runExample: 
#	./example

run: 
	./exec

clean:
	rm -f *.o 