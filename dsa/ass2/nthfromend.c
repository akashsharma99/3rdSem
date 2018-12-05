5.Find nth node from end of a linked list.

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
int getEle(struct node** s,int n)
{
      struct node* p=*s;
      int m=0;
      while(p!=NULL)
      {
            m++;
            p=p->next;
      }
      if(n<1 || m<n)
      {
            printf("Invalid position\n");
            return -999;
      }
      n=m-n;
      p=*s;
      for(int i=1;i<=n;i++,p=p->next);
      return p->data;
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
            printf("Enter position from end: ");
            scanf("%d",&p);
            int num=getEle(&start,p);
            if(num!=-999)
                  printf("Element is : %d\n",num);
      }
      return 0;
}
