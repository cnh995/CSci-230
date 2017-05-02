#ifndef HW11_CHRISTIANHANSEN_C_H
#define HW11_CHRISTIANHANSEN_C_H

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void DISPLAY_INORDER(struct node *head, struct node *tail);

void DISPLAY_POSTORDER(struct node *head, struct node *tail);

void DISPLAY_TRASH(struct node *head, struct node *tail);

#endif //HW11_CHRISTIANHANSEN_C_H
