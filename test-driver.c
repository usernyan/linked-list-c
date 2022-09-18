#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

//these functions are passes as pointers to the library
void init_int(void **to_data);
void print_int(void *data);
void free_int(void **to_data);

//these are just helper functions for testing.
void int_list_tester(struct link_node *list_head);


int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	printf(getfoo()); //Testing #include "linked.h"
	int l = 5;
	struct link_node *my_list = new_list(l);
	init_list(my_list, &init_int);
	print_list(my_list, &print_int);
	int_list_tester(my_list);
	print_list(my_list, &print_int);
	clear_list(my_list, &free_int);
	dealloc_nodes(my_list);
	return 0;
}

void int_list_tester(struct link_node *list_head) {
	int i = 0;
	struct link_node *cur_node = list_head;
	while (cur_node) {
		*(int *)cur_node->data = i * i + 1;
		cur_node = cur_node->next;
		i++;
	}
}

void init_int(void **to_data) {
	*to_data = malloc(sizeof(int));
	*(int *)*to_data = 0;
}

void free_int(void **to_data) {
	free(*to_data);
	*to_data = NULL;
}

void print_int(void *data) {
	printf("%d\n", *(int *)data);
}
