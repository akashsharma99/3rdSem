#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node* prev,*next;
};
void insertEnd(struct node** head,int data)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=data;
      temp->next=NULL;
      temp->prev=NULL;
      struct node*p=*head;
      if(*head==NULL)
      {
            *head=temp;
            return;
      }
      while(p->next!=NULL)
      {
            p=p->next;
      }
      temp->prev=p;
      p->next=temp;
      return;
}
void insertBeg(struct node** head,int data)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=data;
      temp->next=NULL;
      if(*head==NULL)
      {
            *head=temp;
            return;
      }
      struct node* p=*head;
      temp->next=p;
      p->prev=temp;
      *head=temp;
      return;
}
void insertPos(struct node** head,int pos,int data)
{
      if(*head==NULL)
      return;
      if(pos<1)
      {
            printf("Invalid position!\n");
            return;
      }
      if(pos==1)
      {
            insertBeg(head,data);
            return;
      }
      struct node*p=*head;
      for(int i=1;i<pos-1;i++)
      {
            p=p->next;
            if(p->next==NULL)
            {
                  printf("Invaid position!\n");
                  return;
            }
      }
      //printf("%d",p->data);
      if(p->next==NULL)
      {
            printf("Invaid position!\n");
            return;
      }
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=data;
      temp->prev=p;
      temp->next=p->next;
      p->next=temp;
      temp->next->prev=temp;
      //printf("%d",p->data);
      return;
}
void insertAfterEle(struct node** head,int data,int ele)
{
      struct node* p=*head;
      if(*head==NULL)
            return;
      while(p->data!=ele)
      {
            p=p->next;
            if(p==NULL)
            {
                  printf("Element not found\n");
                  return;
            }
      }
      if(p->next==NULL)
      {
            insertEnd(head,data);
            return;
      }
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=data;
      temp->prev=p;
      temp->next=p->next;
      p->next=temp;
      temp->next->prev=temp;
      return;
}
void display(struct node** head)
{
      struct node*p=*head;
      if(*head==NULL)
      printf("List is empty");
      else{
            printf("List is: \n");
            while(p!=NULL)
            {
                  printf("%d\n",p->data);
                  p=p->next;
            }
      }
      return;
}
int main()
{
      struct node* head=NULL;
      int n;
      printf("Create a link list.\nEnter -1 to stop\n");
      scanf("%d",&n);
      while(n!=-1)
      {
            insertEnd(&head,n);
            scanf("%d",&n);
      }
      printf("1. Insert Beginning\n2. Insert End\n");
      printf("3. Insert at position\n4. Insert element\n");
      printf("Choose please: ");
      scanf("%d",&n);
      printf("Enter new data: ");
      int num,p;
      scanf("%d",&num);
      switch(n)
      {
            case 1:     insertBeg(&head,num);
                        break;
            case 2:     insertEnd(&head,num);
                        break;
            case 3:     printf("Enter position\n");
                        scanf("%d",&p);
                        insertPos(&head,p,num);
                        break;
            case 4:     printf("Enter element to search\n");
                        scanf("%d",&p);
                        insertAfterEle(&head,num,p);
                        break;
            default:printf("Wrong choice nibba!\n");
      }
      display(&head);
      return 0;
}
