CC            = g++
CFLAGS        = -O3 -Wall -I/Users/liu/kouui/cpp/includes/
DEST          = /usr/local/bin
LDFLAGS       = -L/usr/local/lib
LIBS          = -lhoge -lm
OBJS          = main.o
PROGRAM       = Demo

all:	$(PROGRAM)		clean
	./$(PROGRAM)

$(PROGRAM):	$(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

clean:;         rm -f *.o *~

cleanall:;         rm -f *.o *~ $(PROGRAM)

install: $(PROGRAM)
	install -s $(PROGRAM) $(DEST)
