CC = g++
CFLAGS  = -g -Wall

default: print
# object file
print: source.o
	$(CC) $(CFLAGS) -o print Source.cpp

# files that the object file depend on
source.o: Source.cpp printConsole.h printAPI.h printA.h
	$(CC) $(CFLAGS) -c Source.cpp

# make clean to remove the executable file and start over
clean:
	$(RM) print *.o *~
