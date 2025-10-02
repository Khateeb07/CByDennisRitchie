#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
}*head=NULL;
void createNode(int);
void traversal();
void insertNode(int, int);
int deleteNode(int);
int main(int argc, char* argv[]){
	int option, data, pos, result, size;
	while(1){
		printf("\n1. Create Node\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node\n");
		printf("4. Delete Node\n");
		printf("10. Exit\n");
		printf("Enter the option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter size of linked list: ");
				scanf("%d",&size);
				for(int i=0; i<size; i++){
					printf("Enter data: \n");
					scanf("%d",&data);
					createNode(data);
				}
				break;
			case 2:
				traversal();
				printf("\nList Traversed\n");
				break;
			case 3:
				printf("Enter position: \n");
				scanf("%d", &pos);
				printf("Enter data: \n");
				scanf("%d", &data);
				insertNode(pos, data);
				break;
			case 4:
				printf("Enter position: \n");
				scanf("%d", &pos);
				result=deleteNode(pos);
				printf("Deleted Node %d at position %d\n", result,pos);
				break;
			case 10:
				exit(0);
			default:
				printf("Wrong option\n");
		}
	}
	return 0;
}
void createNode(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=temp;
	if(head==NULL)
		head=temp;
 	struct node* p=head;
	while(p->next!=head){
		p=p->next;
	}
	p->next=temp;
	temp->next=head;
}
void traversal(){
	struct node* p=head;
	if(p->next==head){
		printf("\n%d\n", p->data);
	}else{
		printf("\n%d\t", p->data);
		do{
			p=p->next;
			printf("%d\t",p->data);
		}while(p->next!=head);
	}
}
void insertNode(int pos, int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	struct node* p=head;
	if(pos!=1){
		int count=1;
		while(count<pos-1){
			p=p->next;
			count++;
		}
	}else{
		while(p->next!=head)
			p=p->next;
		head=temp;
	}
	temp->next=p->next;
	p->next=temp;
}
int deleteNode(int pos){
	struct node* p=head;
	if(pos!=1){
		int count=1;
		while(count<pos-1){
			p=p->next;
			count++;
		}
	}else{
		while(p->next!=head)
			p=p->next;
		head=p->next->next;
	}
	struct node* q=p->next;
	p->next=q->next;
	q->next=NULL;
	int data=q->data;
	free(q);
	return data;
}
