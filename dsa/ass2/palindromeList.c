3.Check if the linked list is Palindrome

#include<stdio.h>
#include<stdlib.h>
struct node
{
      struct node* next;
      int data;
};
void create(struct node** s)
{
      int v,i;
      struct node* temp, *last;
      printf("Enter -1 to exit creation of link list: ");
      scanf("%d",&v);
      while(v!=-1)
      {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=v;
            temp->next=NULL;
            if(*s==NULL)
            {
                  (*s)=temp;
                  last=temp;
            }
            else
            {
                  last->next=temp;
                  last=temp;
            }
            scanf("%d",&v);
      }
      return;
}
void display(struct node** s)
{
      struct node *st=*s;
      if(st==NULL){
            printf("Empty\n");
            return;
      }
      while(st!=NULL)
      {
            printf("%d\n",st->data);
            st=st->next;
      }
      return;
}
int getCount(struct node** s)
{
      struct node*st=*s;
      int count=0;
      while(st!=NULL)
      {
            count++;
            st=st->next;
      }
      return count;
}
void insert(struct node** s,int v)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=v;
      if(*s==NULL)
      {
            temp->next=NULL;
            *s=temp;
            return;
      }
      temp->next=*s;
      *s=temp;
      return;
}
int isPalindrome(struct node** s)
{
      int count=getCount(s);
      if((*s)->next==NULL)
      {
            return 1;//single element palindrome
      }
      struct node* slow_ptr=*s,*last=NULL;
      struct node* fast_ptr=*s;
      struct node* p=*s;
      while(fast_ptr!=NULL && fast_ptr->next!=NULL)
      {
            p=slow_ptr;
            insert(&last,p->data);
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
      }
      p=p->next;
      if(count%2!=0)
      p=p->next;
      int flag=0;
      while(p!=NULL)
      {
            if(p->data!=last->data)
                  return 0;
            p=p->next;
            last=last->next;
      }
      return 1;
}
int main()
{
      struct node* start=NULL;
      int p;
      printf("Lets create the list first!\n");
      create(&start);
      printf("The list is: \n");
      display(&start);
      if(start!=NULL){
            if(isPalindrome(&start)==1)
            printf("Yes Palindrome\n");
            else
            printf("Not a palindrome\n");
      }
      return 0;
}
