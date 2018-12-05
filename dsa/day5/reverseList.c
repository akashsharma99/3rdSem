#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node* next;
};
void printReverse(struct node* head)
{
      if(head->next!=NULL)
            printReverse(head->next);
      printf("%d\n",head->data);
}
int getNth(struct node**head, int n)
{
      int c=1;
      struct node* start=*head;
      while(c!=n)
      {
            if(start==NULL)
            {
                  return -999;
            }
            start=start->next;
            c++;
      }
      return start->data;
}
void insert(struct node** head,int num)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=num;
      temp->next=NULL;
      struct node* p=*head;
      if(*head==NULL)
      {
            *head=temp;
            return;
      }
      while(p->next!=NULL)
      {
            p=p->next;
      }
      p->next=temp;
      return;
}
int main()
{
      struct node* head=NULL;
      int n,c=0;
      char ch;
      printf("Create a link list.\nEnter y to continue or n to stop after each input!\n");
      scanf("%c",&ch);
      while(ch=='y'||ch=='Y')
      {
            c++;
            printf("Number: ");
            scanf("%d%c",&n,&ch);
            insert(&head,n);
            scanf("%c",&ch);

      }
      if(c==0){
      printf("List empty bye!");
      return 0;}
      printf("How do you want to reverse the list?\na. Recursively\nb. Iteratively\n");
      scanf("%c%c",&ch,&ch);
      switch(ch)
      {
            case 'a': printf("The reverse is:\n");
            printReverse(head);
            break;
            case 'b': printf("The reverse is: \n");
            while(c!=0)
            {
                  printf("%d\n",getNth(&head,c));
                  c--;
            }
            break;
            default: printf("Wrong choice\n");
      }

      return 0;
}
