#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void init_int(void **to_data);

int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	printf(getfoo()); //Testing #include "linked.h"
	struct link_node *my_list = new_list(5);
	init_list(my_list, &init_int);
	return 0;
}

void init_int(void **to_data) {
	*to_data = malloc(sizeof(int));
	*(int *)*to_data = 0;
}
