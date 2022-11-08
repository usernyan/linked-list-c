#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

//these functions are passed as pointers to the library
void *init_int(void *to_data);
void print_int(void *data);
bool int_eq(void *data1, void *data2);

//these are just helper functions for testing.
void int_list_tester(struct link_node *list_head);
int *new_int(int val);
void my_print(struct link_node *head);
void retrieval_test(struct link_node *l, int begin_at, int end_at);

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

	//Functions that might change which node is the head of the list return the new head.
	my_list = new_list(0, &init_int);
	puts("insert_first");
	my_print(my_list);
	for(int i = 0; i < 4; i++) {
		my_list = insert_first(my_list, new_int(i));
		my_print(my_list);
	}

	puts("linear_find");
	struct link_node *found = NULL;
	for(int i = -1; i < 5; i++) {
		found = linear_find(my_list, &i, &int_eq);
		if (found) {
			printf("found:");
			print_int(found->data);
			printf("\n");
		}
		else {
			printf("not found:");
			print_int(&i);
			printf("\n");
		}
	}

	puts("delete_last");
	for(int i = 0; i < 5; i++) {
		my_list = delete_last(my_list, &free); 
		my_print(my_list);
	}

	puts("insert_last");
	for(int i = 0; i < 4; i++) {
		my_list = insert_last(my_list, new_int(i));
		my_print(my_list);
	}

	retrieval_test(my_list, -1, 5);

	puts("insert_at");
	int arr[] = {0, 1, 2, 6, 8};
	int arr_l = 5;
	for (int i = 0; i < arr_l; i++) {
		printf("%d:", arr[i]);
		my_list = insert_at(my_list, arr[i], new_int(i+5));
		my_print(my_list);
	}

	puts("delete_at");
	for (int i = 0; i < arr_l; i++) {
		printf("%d:", arr[i]);
		my_list = delete_at(my_list, arr[i], &free);
		my_print(my_list);
	}

	puts("delete_first");
	my_print(my_list);
	for(int i = 0; i < 5; i++) {
		my_list = delete_first(my_list, &free);
		my_print(my_list);
	}

	int arr2[] = {200, -20, 1, 0, -20};
	int arr2_l = 4;
	puts("insert_at from null");
	for (int i = 0; i < arr2_l; i++)
	{
		printf("%d:", arr2[i]);
		my_list = insert_at(my_list, arr2[i], new_int(i));
		my_print(my_list);
	}
	puts("delete_at to null");
	for (int i = 0; i < arr2_l + 1; i++)
	{
		printf("%d:", arr2[i]);
		my_list = delete_at(my_list, arr2[i], &free);
		my_print(my_list);
	}

	retrieval_test(my_list, 0, 1);

	del_list(my_list, &free);
	return 0;
}

void retrieval_test(struct link_node *l, int begin_at, int end_at) {
	puts("get_first");
	print_int(get_first(l));
	printf("\n");

	puts("get_last");
	print_int(get_last(l));
	printf("\n");

	for (int i = begin_at; i < end_at; i++) {
		printf("%d:", i);
		print_int(get_at(l, i));
		printf("\n");
	}
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

bool int_eq(void *data1, void *data2) {
	return *(int *)data1 == *(int *)data2;
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
	if (data)
		printf("%d", *(int *)data);
	else
		printf("null data ptr");
}

void my_print(struct link_node *head) {
	print_list_fancy(head, &print_int, ", ", "[ ", " ]\n");
}
