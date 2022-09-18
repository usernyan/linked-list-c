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
