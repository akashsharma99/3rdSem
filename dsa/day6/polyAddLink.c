#include<stdio.h>
#include<stdlib.h>
struct node
{
      int coeff,expo;
      struct node* next;
}*poly1=NULL,*poly2=NULL,*poly3=NULL;
void insert(struct node** start,int coeff,int expo)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->expo=expo;
      temp->coeff=coeff;
      temp->next=NULL;
      if(*start==NULL)
      {
            *start=temp;
            return;
      }
      struct node* p=*start;
      while(p->next!=NULL)
      {p=p->next;}
      p->next=temp;
      return;
}

void display(struct node* start)
{
      struct node* p=start;
      if(p==NULL)
      {
            printf("EMpty!\n");
            return;
      }
      while(p->next!=NULL)
      {
            printf("%dx%d + ",p->coeff,p->expo);
            p=p->next;
      }
      printf("%dx%d",p->coeff,p->expo);
      printf("\n");
      return;
}
int main()
{
      printf("Creating first polynomial: - \n");
      printf("No.of terms");
      int n,i;
      scanf("%d",&n);
      printf("Enter coefficients and exponents in descending order of exponents...\n");
      for(i=0;i<n;i++)
      {
            int coeff,expo;
            scanf("%d%d",&coeff,&expo);
            insert(&poly1,coeff,expo);
      }
      printf("Displaying poly1: \n");
      display(poly1);
      return 0;
}
