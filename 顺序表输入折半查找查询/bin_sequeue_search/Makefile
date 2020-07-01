CC= gcc
CFLAGS = -Wall -g -O0

MYAPP = test
SRC = bin_seqqueue.c test.c

$(MYAPP) : $(SRC)
	$(CC) $(CFLAGS) -o $@ $^


clean:
	$(RM) $(MYAPP) 
