#ifndef HW11_CHRISTIANHANSEN_A_H
#define HW11_CHRISTIANHANSEN_A_H

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void insertNode(struct node *item, struct node **head, struct node **tail);

#endif //HW11_CHRISTIANHANSEN_A_H
