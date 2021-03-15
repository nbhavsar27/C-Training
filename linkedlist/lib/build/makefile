CC=gcc
CFLAGS=-c
RM=rm -rf
SRCDI=../src
EXEDI=../bin

all: Compile Lib

Compile: #$(SRCDI)/linkedlist.c
	$(CC) $(CFLAGS) $(SRCDI)/linkedlist.c -o $(SRCDI)/linkedlist.o

Lib: #$(SRCDI)/linkedlist.c
	mkdir $(EXEDI)
	ar rcs $(EXEDI)/liblinkedlist.a $(SRCDI)/linkedlist.o
clean:
	$(RM) $(SRCDI)/linkedlist.o
	$(RM) $(EXEDI)
