#include <stdlib.h>
#include <stdio.h>

struct link_node {
	struct link_node *next;
	void *data;
};

/*
 * list creation and deletion functions
 */

struct link_node *alloc_nodes(int len) {
	struct link_node *head = NULL;
	if (len > 0)
	{
		head = malloc(sizeof(struct link_node));
		head->next = NULL;
		head->data = NULL;
	}
	struct link_node *prev = head;
	struct link_node *temp = NULL;
	for(int i = 0; i < len-1; i++) {
		temp = malloc(sizeof(struct link_node));
		temp->next = NULL;
		prev->next = temp;
		prev = temp;
	}
	return head;
}

void dealloc_nodes(struct link_node *head) {
	if (!head)
		return;
	struct link_node *cur_node = head;
	struct link_node *temp;
	do {
		temp = cur_node;
		cur_node = temp->next;
		free(temp);
	} while (cur_node);
}

void __for_each_data_ptr(struct link_node *head, void (*func)(void **)) {
	struct link_node *t = head;
	while (t) {
		(*func)(&t->data);
		t = t->next;
	}
}

void init_list(struct link_node *head, void (*initializer)(void **)) {
	__for_each_data_ptr(head, initializer);
}

void clear_list(struct link_node *head, void (*deinitializer)(void **)) {
	__for_each_data_ptr(head, deinitializer);
}

struct link_node *new_list(int len, void (*initializer)(void **)) {
	struct link_node *head = alloc_nodes(len);
	init_list(head, initializer);
	return head;
}

void del_list(struct link_node *head, void(*deinitializer)(void **)) {
	clear_list(head, deinitializer);
	dealloc_nodes(head);
}

/*
 * list printing functions
 */
void print_list(struct link_node *head, void (*printer)(void *)) {
	struct link_node *t = head;
	while (t) {
		(*printer)(t->data);
		t = t->next;
	}
}

void print_list_fancy(struct link_node *head, void (*printer)(void *), char *delim, char *begin, char *end) {
	fputs(begin, stdout);
	struct link_node *t = head;
	while (t) {
		(*printer)(t->data);
		if (t->next)
			fputs(delim, stdout);
		t = t->next;
	}
	fputs(end, stdout);
}
