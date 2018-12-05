9.Find subsequences such that their sum is equal to next term.

#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node* next;
}*start=NULL;
void create(int n)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=n;
      temp->next=NULL;
      if(start==NULL)
      {
            start=temp;
            return;
      }
      struct node* p=start;
      while(p->next!=NULL)
      {
            p=p->next;
      }
      p->next=temp;
      return;
}
struct node* getNodeAddress(int n)
{
      struct node* p=start;
      int i;
      for(i=0;i<n;i++)
      {
            p=p->next;
      }
      return p;
}
int main()
{
      int c,lt=0,i,j,k;
      printf("Enter numbers, press -1 to stop creation of link list!\n");
      scanf("%d",&c);
      while(c!=-1)
      {
            lt++;
            create(c);
            scanf("%d",&c);
      }
      if(lt==1)
      printf("Invalid length of lists subsets cannot be checked!\n");
      for(i=2;i<=lt;i++)
      {
            for(j=0;j<lt;j++)
            {
                  if(j+i-1<lt)
                  {
                        int s=0;
                        struct node* x=getNodeAddress(j);
                        struct node* y=getNodeAddress(j+i-1);
                        struct node* p=x;
                        s=s+p->data;
                        while(p->next!=y)
                        {
                              p=p->next;
                              s=s+p->data;
                        }
                        if(s==y->data)
                        {
                              p=x;
                              while(p!=y)
                              {
                                    printf("%d,",p->data);
                                    p=p->next;
                              }
                              printf("\n");
                        }
                  }
            }
      }
      return 0;
}
