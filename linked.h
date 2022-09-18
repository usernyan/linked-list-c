#ifndef LINKED_H
#define LINKED_H

char *getfoo();

struct link_node {
	struct link_node *next;
	void *data;
};

struct link_node *new_list(int len);
void init_list(struct link_node *head, void (*initializer)(void **));

#endif
