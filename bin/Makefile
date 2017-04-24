PROG = BigFoot
CC = g++

CPPFLAGS = -O0 -g -Wall -pedantic -std=c++11

OBJS = main.o host.o list.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : ../src/main.cpp
	$(CC) $(CPPFLAGS) -c ../src/main.cpp

list.o : ../src/list.cpp
	$(CC) $(CPPFLAGS) -c ../src/list.cpp

host.o : ../src/host.cpp
	$(CC) $(CPPFLAGS) -c ../src/host.cpp

clean:
	rm -f core $(PROG) $(OBJS)
