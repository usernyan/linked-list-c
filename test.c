#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void init_int(void **to_data);
void print_int(void *data);

int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	printf(getfoo()); //Testing #include "linked.h"
	struct link_node *my_list = new_list(5);
	init_list(my_list, &init_int);
	print_list(my_list, &print_int);
	return 0;
}

void init_int(void **to_data) {
	*to_data = malloc(sizeof(int));
	*(int *)*to_data = 0;
}

void print_int(void *data) {
	printf("%d\n", *(int *)data);
}
