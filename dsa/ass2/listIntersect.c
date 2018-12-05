4.Find intersection point of two linked lists

#include<stdio.h>
#include<stdlib.h>
struct node
{
      struct node* next;
      int data;
};
struct node* getNodeAddress(int n,struct node** s)
{
      struct node* p=*s;
      int i;
      if(p==NULL)
      return NULL;
      for(i=0;i<n;i++)
      {
            //printf("%d\n",p->data);
            p=p->next;
            if(p==NULL)
            return NULL;
      }
      return p;
}
void intersect(struct node** s1,struct node** s2)
{
      struct node* st1=*s1,*st2=*s2;
      int p1,p2;
      struct node* x=NULL,*y=NULL;
      do{
            printf("Enter correct position of list 1 and list 2 to intersect at: ");
            scanf("%d%d",&p1,&p2);
            x=getNodeAddress(p1,&st1);
            y=getNodeAddress(p2,&st2);
      }while(x==NULL || y==NULL);
      y->next=x;

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
      if(st==NULL)
      {
            printf("Empty!\n");
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
      struct node* st=*s;
      int c=0;
      while(st!=NULL){
            c++;
            st=st->next;
      }
      return c;
}
int getIntersection(struct node** s1,struct node** s2)
{
      struct node *st1=*s1,*st2=*s2;
      int c1=getCount(&st1);
      int c2=getCount(&st2);
      if(c1>c2)
      {
            for(int i=1;i<=c1-c2;i++,st1=st1->next);
            while(st1!=st2)
            {
                  st1=st1->next;
                  st2=st2->next;
            }
            return st1->data;
      }
      if(c1<c2)
      {
            for(int i=1;i<=c2-c1;i++,st2=st2->next);
            while(st1!=st2)
            {
                  st1=st1->next;
                  st2=st2->next;
            }
            return st1->data;
      }
      while(st1!=st2)
      {
            st1=st1->next;
            st2=st2->next;
      }
      return st2->data;

}
int main()
{
      struct node* start1=NULL,*start2=NULL;
      printf("Lets create the lists first!\n");
      create(&start1);
      create(&start2);
      if(start1==NULL || start2==NULL){
            printf("No intersection!\n");
      }
      else{
            intersect(&start1,&start2);
            printf("First modified list:\n");
            display(&start1);
            printf("Second modified list:\n");
            display(&start2);
            int v=getIntersection(&start1,&start2);
            printf("Intersecting at : %d",v);
      }
      return 0;
}
