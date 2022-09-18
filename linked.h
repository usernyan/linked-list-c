#ifndef LINKED_H
#define LINKED_H

char *getfoo();

struct link_node {
	struct link_node *next;
	void *data;
};

struct link_node *new_list(int len);
void init_list(struct link_node *head, void (*initializer)(void **));
void clear_list(struct link_node *head, void (*deinitializer)(void **));
void dealloc_nodes(struct link_node *head);
void print_list(struct link_node *head, void (*printer)(void *));

#endif
