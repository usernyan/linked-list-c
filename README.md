# linked.c
A reusable linked list library written in c.

The library relies on the user to provide functions for allocating and deallocating pointers to data stored in each node in the linked list. In this way the list can be used on various datatypes.

## Usage

The user can create and delete a list of ints like so:
```c
#include <stdlib.h>
#include <linked.h>
void main() {
	int list_length = 3;
	struct link_node l = new_list(list_length, &alloc_int);
	del_list(l, &free);
}

void *alloc_int(void *to_data) {
	int *i = malloc(sizeof(int));
	*i = 0;
	return i;
}

```

Functions that might change which node is the head of the list return the new head.
For example, insert\_first and other functions that add or remove nodes should be used like so:
```c
#include <stdlib.h>
#include <linked.h>
void main() {
	struct link_node l = new_list(0, &alloc_int); //returns NULL
	l = insert_first(l, func_that_returns_ptr_to_data()); //returns the inserted node
}

int *new_int(int val) {
	int *m = malloc(sizeof(int));
	*m = val;
	return m;
}
```
