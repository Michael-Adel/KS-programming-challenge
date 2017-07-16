CC = g++
CFLAGS  = -g

default: Source
# object file
Source: source.o
	$(CC) $(CFLAGS) -o Source Source.cpp

# files 
source.o: Source.cpp 
	$(CC) $(CFLAGS) -c Source.cpp

# make clean 
clean:
	$(RM) Source *.o *~
