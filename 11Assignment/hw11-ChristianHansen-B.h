#ifndef HW11_CHRISTIANHANSEN_B_H
#define HW11_CHRISTIANHANSEN_B_H

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void DELETE_NODE(int numToDelete, struct node **head, struct node **tail, struct node **trashHead, struct node **trashTail);

#endif //HW11_CHRISTIANHANSEN_B_H
