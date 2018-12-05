7. Merge two sorted linked lists
#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node* next;
};
struct node* merge(struct node** a,struct node** b)
{
      struct node result;
      result.next=NULL;
      struct node *p=*a,*q=*b,*r=&result;
      while(p!=NULL && q!=NULL)
      {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            if(p->data==q->data)
            {
                  temp->data=p->data;
                  r->next=temp;
                  r=r->next;
                  /*struct node* temp2=(struct node*)malloc(sizeof(struct node));
                  temp2->data=q->data;
                  temp2->next=NULL;
                  r->next=temp2;
                  r=r->next;*/
                  //uncomment the above code if you want repetitions
                  p=p->next;
                  q=q->next;
            }
            else if(p->data < q->data)
            {
                  temp->data=p->data;
                  r->next=temp;
                  r=r->next;
                  p=p->next;
            }
            else if(p->data > q->data)
            {
                  temp->data=q->data;
                  r->next=temp;
                  r=r->next;
                  q=q->next;
            }
      }//end of either of the lists or both
      while(p!=NULL)
      {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            temp->data=p->data;
            r->next=temp;
            r=r->next;
            p=p->next;
      }//merging remaining elements of p
      while(q!=NULL)
      {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            temp->data=q->data;
            r->next=temp;
            r=r->next;
            q=q->next;
      }//merging remaining elements of q
      return result.next;
}
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
      while(st!=NULL)
      {
            printf("%d\n",st->data);
            st=st->next;
      }
      return;
}
int main()
{
      struct node* a=NULL,*b=NULL,*res=NULL;
      printf("1st list:\n");
      create(&a);
      printf("2nd list:\n");
      create(&b);
      res=merge(&a,&b);
      if(res==NULL)
      {
            printf("Empty result!\n");
            return 0;
      }
      printf("The merged list is :\n");
      display(&res);
      return 0;
}
