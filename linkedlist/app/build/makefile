CC=gcc
CFLAGS=-c
LDFLAGS= -L ../../lib/bin/
RM=rm -rf
SRCDI=../src
LIBDI=../lib
BINDI=../bin

all: makefile_link copy Compile link

makefile_link: 
	$(MAKE) -C ../../lib/build/

copy: 
	mkdir $(LIBDI)
	cp ../../lib/bin/liblinkedlist.a $(LIBDI)/liblinkedlist.a
Compile: 
	$(CC) $(CFLAGS) $(SRCDI)/applinkedlist.c -o $(SRCDI)/applinkedlist.o

link:
	mkdir $(BINDI)
	$(CC) -o $(BINDI)/applinkedlist $(SRCDI)/applinkedlist.o $(LDFLAGS) -llinkedlist
clean:
	$(RM) $(SRCDI)/applinkedlist.o
	$(RM) $(BINDI)
	$(RM) $(LIBDI)
	$(MAKE) clean -C ../../lib/build/
