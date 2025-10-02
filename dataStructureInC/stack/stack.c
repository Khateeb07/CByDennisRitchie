#include <stdlib.h>
#include "stack.h"
int push(int data) {
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL) return 0;
	temp->data=data;
	temp->next=NULL;
	if(top==NULL) top=temp;
	else {
		temp->next=top;
		top=temp;
	}
	return 1;
}
int pop() {
	if(top==NULL) return -1;
	struct node* temp=top;
	top=temp->next;
	temp->next=NULL;
	int data=temp->data;
	free(temp);
	return data;
}
