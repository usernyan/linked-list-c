#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

//these functions are passed as pointers to the library
void init_int(void **to_data);
void print_int(void *data);
void free_int(void **to_data);

//these are just helper functions for testing.
void int_list_tester(struct link_node *list_head);
int *new_int(int val);

int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	int l = 5;

	puts("creating and deleting a list:");
	struct link_node *my_list = alloc_nodes(l);
	init_list(my_list, &init_int);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	int_list_tester(my_list);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	clear_list(my_list, &free_int);
	dealloc_nodes(my_list);

	puts("creating and deleting a list:");
	my_list = new_list(l, &init_int);
	int_list_tester(my_list);
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	del_list(my_list, &free_int);

	puts("list insertion");
	my_list = new_list(0, &init_int);
	//val, idx, val, idx, ...
	print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	for (int i = 0; i < 3; i++) {
		my_list = append(my_list, new_int(i));
		print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	}
	for (int i = 4; i < 7; i++) {
		my_list = insert_first(my_list, new_int(i));
		print_list_fancy(my_list, &print_int, ", ", "[ ", " ]\n");
	}
	del_list(my_list, &free_int);
	puts("insert_first on NULL head");
	print_list_fancy(NULL, &print_int, ", ", "[ ", " ]\n");
	struct link_node *temp = insert_first(NULL, new_int(40));
	print_list_fancy(temp, &print_int, ", ", "[ ", " ]\n");
	del_list(temp, &free_int);

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

int *new_int(int val) {
	int *m = malloc(sizeof(int));
	*m = val;
	return m;
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
