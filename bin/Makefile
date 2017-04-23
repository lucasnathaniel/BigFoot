PROG = BigFoot
CC = g++

CPPFLAGS = -O0 -g -Wall -pedantic -std=c++11

OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : ../src/main.cpp
	$(CC) $(CPPFLAGS) -c ../src/main.cpp

clean:
	rm -f core $(PROG) $(OBJS)
