CC = gcc

test-driver: test-driver.o linked.o
	${CC} -g test-driver.o linked.o -o test-driver


#make this dependent on linked.h?
test-driver.o: test-driver.c linked.h
	${CC} -g -c test-driver.c

linked.o: linked.c
	${CC} -g -c linked.c

# We could compile this way, also.
# test-driver: test-driver.c linked.c linked.h
# 	${CC} test-driver.c linked.c -o test-driver

clean:
	rm -f -- *.o test-driver
