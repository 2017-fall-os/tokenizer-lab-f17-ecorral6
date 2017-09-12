# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

mytoc: test.o mytoc.o
	gcc -o mytoc test.c mytoc.c

test.o: test.c
	gcc -c test.c -o test.o

mytoc.o: mytoc.c
	gcc -c mytoc.c -o mytoc.o

clean:
	rm -f *.o mytoc

