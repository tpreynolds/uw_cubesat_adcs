CC=gcc
CFLAGS=-I.
DEPS = oac.h
OBJ = run_demo.o oac.o tools.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run_demo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~