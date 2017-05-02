#ifndef HW11_CHRISTIANHANSEN_D_H
#define HW11_CHRISTIANHANSEN_D_H

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void FREE_INORDER(struct node *head, struct node *tail);

#endif //HW11_CHRISTIANHANSEN_D_H
