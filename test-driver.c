#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

//these functions are passed as pointers to the library
void *init_int(void *to_data);
void print_int(void *data);

//these are just helper functions for testing.
void int_list_tester(struct link_node *list_head);
int *new_int(int val);
void my_print(struct link_node *head);

int main(int argc, char *argv[]) {
	printf("Hello, test.\n");
	int l = 5;

	puts("creating and deleting a list:");
	struct link_node *my_list = alloc_nodes(l);
	init_list(my_list, &init_int);
	my_print(my_list);
	int_list_tester(my_list);
	my_print(my_list);
	clear_list(my_list, &free);
	dealloc_nodes(my_list);

	puts("creating and deleting a list:");
	my_list = new_list(l, &init_int);
	int_list_tester(my_list);
	my_print(my_list);
	del_list(my_list, &free);

	puts("list insertion");
	my_list = new_list(0, &init_int);
	//val, idx, val, idx, ...
	my_print(my_list);
	for (int i = 0; i < 3; i++) {
		my_list = append(my_list, new_int(i));
		my_print(my_list);
	}
	for (int i = 4; i < 7; i++) {
		my_list = insert_first(my_list, new_int(i));
		my_print(my_list);
	}
	del_list(my_list, &free);
	puts("insert_first on NULL head");
	my_print(NULL);
	struct link_node *temp = insert_first(NULL, new_int(40));
	my_print(temp);
	del_list(temp, &free);

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

void *init_int(void *to_data) {
	int *i = malloc(sizeof(int));
	*i = 0;
	return i;
}

void print_int(void *data) {
	printf("%d", *(int *)data);
}

void my_print(struct link_node *head) {
	print_list_fancy(head, &print_int, ", ", "[ ", " ]\n");
}
