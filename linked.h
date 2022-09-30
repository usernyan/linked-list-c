#ifndef LINKED_H
#define LINKED_H

#include <stdbool.h>

struct link_node {
	struct link_node *next;
	void *data;
};

struct link_node *alloc_nodes(int len);
void dealloc_nodes(struct link_node *head);

void init_list(struct link_node *head, void *(*initializer)());
void clear_list(struct link_node *head, void (*deinitializer)(void *));

struct link_node *new_list(int len, void *(*initializer)());
void del_list(struct link_node *head, void (*deinitializer)(void *));

void print_list(struct link_node *head, void (*printer)(void *));
void print_list_fancy(struct link_node *head, void (*printer)(void *), char *delim, char *begin, char *end);

struct link_node *insert_last(struct link_node *head, void *data);
struct link_node *insert_first(struct link_node *head, void *data);


struct link_node *delete_first(struct link_node *head, void (*deinitializer)(void *data));
struct link_node *delete_last(struct link_node *head, void (*deinitializer)(void *data));

struct link_node *linear_find(struct link_node *head, void *target, bool (*eq)(void *data1, void *data2));

#endif
