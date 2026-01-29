#include "mylib.h"
#include "list.h"

//PRIMITIVE

list emptyList(void) { return NULL; }

boolean empty(list l) {
	if (l == NULL) return True; else return False;
}
element head(list l) {
	if (empty(l)) exit(1);
	else return l->value;
}
list tail(list l) {
	if (empty(l)) exit(1);
	else return l->next;
}
list cons(element e, list l) {
	list t;
	t = (list)malloc(sizeof(item));
	if (t == NULL){
		printf("\nMemory allocation error (cons)\n");
		exit(-1);
	}
	t->value = e; t->next = l; return t;
}

//NON PRIMITIVE

/*
boolean member(element el, list l) {
	if (empty(l)) return False;
	else if (el == head(l)) return True;
	else return member(el, tail(l));
}
*/

int length(list l) {
	if (empty(l)) return 0;
	else return 1 + length(tail(l));
}

list append(list l1, list l2) {
	if (empty(l1)) return l2;
	else return cons(head(l1), append(tail(l1), l2));
}

list reverse(list l) {
	if (empty(l)) return emptyList();
	else return append(reverse(tail(l)),
		cons(head(l), emptyList()));
}

list copy(list l) {
	if (empty(l)) return l;
	else return cons(head(l), copy(tail(l)));
}

/*
list delete(element el, list l) {
	if (empty(l)) return emptyList();
	else if (el == head(l)) return copy(tail(l));
	else return cons(head(l), delete(el, tail(l)));
}
*/

void showList(list l) {
	printf("[");
	while (!empty(l)) {
		printf(" %d", head(l));
		l = tail(l);
		if (!empty(l)) printf(", ");
	} printf(" ]\n");
}

void freeList(list l) {
	if (empty(l))
		return;
	else {
		freeList(tail(l));
		free(l);
	}
	return;
}
