CC = gcc

test: test.o linked.o
	${CC} test.o linked.o -o test


test.o: test.c
	${CC} -c test.c

linked.o: linked.c
	${CC} -c linked.c

# We could compile this way, also.
# test: test.c linked.c linked.h
# 	${CC} test.c linked.c -o test

clean:
	rm -f -- *.o test
