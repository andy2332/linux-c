CC = gcc
CFLAGS = -Wall -g -O0

MYAPP = test
SRC = main.c seq.c

$(MYAPP):$(SRC)
	   $(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(MYAPP)
