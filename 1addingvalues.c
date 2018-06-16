#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*head=NULL;
struct node* insert(int num,struct node* head){
	struct node* tempN=(struct node*)malloc(sizeof(struct node));
	tempN->data=num;
	if(head==NULL){
		head=tempN;
		printf("First node created\n");
	}
	else{
		printf("Next node created\n");
		tempN->next=head;
		head=tempN;
	}
	return head;
}
void printList(struct node* head){
	while(head!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
	return;
}
int main()
{
	//struct node *head=(struct node*)malloc(sizeof(struct node));
	int N,i=0;
	printf("Creating a new list....Enter the number of elements: ");
	scanf("%d",&N);
	if(N<=0){
		printf("The list is empty so terminating program\n");
		return 0;
	}
	printf("Enter the elements\n");
	while(N>0){
		scanf("%d",&i);
		head=insert(i,head);
		N--;
	}
	//adding a value to all elements
	printf("Enter a value to add: ");
	scanf("%d",&i);
	struct node *x;
	for(x=head;x!=NULL;x=x->next){
		x->data+=i;
	}
	printf("The modified list is..\n");
	printList(head);
	return 0;
}
