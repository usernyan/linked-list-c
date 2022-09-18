#include <stdlib.h>

//for testing
char *getfoo() {
	char *foo = "bar\n";
	return foo;
}

struct link_node {
	struct link_node *next;
	void *data;
};


struct link_node *new_list(int len) {
	struct link_node *head;
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

void print_list(struct link_node *head, void (*printer)(void *)) {
	struct link_node *t = head;
	while (t) {
		(*printer)(t->data);
		t = t->next;
	}
}
