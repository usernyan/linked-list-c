CC = gcc

test: test.o linked.o
	${CC} -g test.o linked.o -o test


#make this dependent on linked.h?
test.o: test.c linked.h
	${CC} -g -c test.c

linked.o: linked.c
	${CC} -g -c linked.c

# We could compile this way, also.
# test: test.c linked.c linked.h
# 	${CC} test.c linked.c -o test

clean:
	rm -f -- *.o test
