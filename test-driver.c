#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

//these functions are passed as pointers to the library
void init_int(void **to_data);
void print_int(void *data);
void free_int(void **to_data);

//these are just helper functions for testing.
void int_list_tester(struct link_node *list_head);

int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	int l = 5;
	struct link_node *my_list = alloc_nodes(l);
	init_list(my_list, &init_int);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	int_list_tester(my_list);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	clear_list(my_list, &free_int);
	dealloc_nodes(my_list);

	my_list = new_list(l, &init_int);
	int_list_tester(my_list);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	del_list(my_list, &free_int);
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
	printf("%d", *(int *)data);
}
