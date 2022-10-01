#include "linked.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

void init_list(struct link_node *head, void *(*initializer)()) {
	struct link_node *t = head;
	while (t) {
		t->data = (*initializer)();
		t = t->next;
	}
}

void clear_list(struct link_node *head, void (*deinitializer)(void *)) {
	struct link_node *t = head;
	while (t) {
		(*deinitializer)(t->data);
		t = t->next;
	}
}

struct link_node *new_list(int len, void *(*initializer)()) {
	struct link_node *head = alloc_nodes(len);
	init_list(head, initializer);
	return head;
}

void del_list(struct link_node *head, void (*deinitializer)(void *)) {
	clear_list(head, deinitializer);
	dealloc_nodes(head);
}

/*
 * list-printing functions
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

/*
 * Insertion
 */

/*
 * insert data at the end of the list
 * return the new head of the list
 */

struct link_node *insert_last(struct link_node *head, void *data) {
	struct link_node *new_node = malloc(sizeof(struct link_node));
	new_node->data = data;
	new_node->next = NULL;
	//find where to insert it
	struct link_node *last_node = head;
	if (head) {
		while (last_node->next) {
			last_node = last_node->next;
		}
		last_node->next = new_node;
		return head;
	}
	else
		return new_node;
}

/*
 * insert data at the start of the list
 * return the new head of the list
 */

struct link_node *insert_first(struct link_node *head, void *data) {
	struct link_node *new_node = malloc(sizeof(struct link_node));
	new_node->next = head;
	new_node->data = data;
	return new_node;
}

/*
 * Deletion
 */

/*
 * delete the last node of the list
 * return the new head of the list
 */

struct link_node *delete_first(struct link_node *head, void (*deinitializer)(void *data)) {
	struct link_node *new_head = NULL;
	if (head) {
		new_head = head->next;
		(*deinitializer)(head->data);
		free(head);
	}
	return new_head;
}

/*
 * delete the first node of the list
 * return the new head of the list
 */

struct link_node *delete_last(struct link_node *head, void (*deinitializer)(void *data)) {
	struct link_node *last = head;
	struct link_node *second_to_last = NULL;
	if (head) {
		while (last->next) {
			second_to_last = last;
			last = last->next;
		}
		(*deinitializer)(last->data);
		free(last);
		if (second_to_last)
			second_to_last->next = NULL;
		else
			head = NULL;

	}
	return head;
}

/*
 * Retrieval
 */

/*
 * get the data pointer of a node, returns null if the pointer to the node is null
 */

void *get_data(struct link_node *n) {
	void *data = NULL;
	if (n)
		data = n->data;
	return data;
}

/*
 * get the last node
 */

struct link_node *get_last_node(struct link_node *head) {
	struct link_node *cur_node = head;
	if (head) {
		while (cur_node->next) {
			cur_node = cur_node->next;
		}
	}
	return cur_node;
}

/*
 * get the node placed n nodes after the head
 */

struct link_node *get_nth_node(struct link_node *head, int n) {
	if (n < 0)
		return NULL;
	struct link_node *cur_node = head;
	int cur_idx = 0;
	while(cur_node && cur_idx < n) {
		cur_node = cur_node->next;
		cur_idx++;
	}
	return cur_node;
}

/*
 * get the data pointer belonging to the node placed n nodes after the head
 */

struct link_node *get_at(struct link_node *head, int n) {
	return get_data(get_nth_node(head, n));
}

/*
 * get the data pointer belonging to the last node
 */

void *get_last(struct link_node *head) {
	struct link_node *l = get_last_node(head);
	return get_data(l);
}

/*
 * get the data pointer belonging to the first node
 */

void *get_first(struct link_node *head) {
	return get_data(head);
}

/*
 */

/*
 * find the first node that contains data equal to the target
 * returns NULL if the node cannot be found
 * the eq function should return true if the two pointers point to equal data, false otherwise
 */

struct link_node *linear_find(struct link_node *head, void *target, bool (*eq)(void *data1, void *data2)) {
	struct link_node *cur_node = head;
	while (cur_node && !eq(cur_node->data, target)) {
		cur_node = cur_node->next;
	}
	return cur_node;
}
