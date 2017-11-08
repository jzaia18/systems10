all: c.c
	gcc -o signalo c.c

run: all
	./signalo

clean: rm *~ signalo
