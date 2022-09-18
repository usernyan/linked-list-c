#ifndef LINKED_H
#define LINKED_H

char *getfoo();

struct link_node {
	struct link_node *next;
	void *data;
};
#endif
