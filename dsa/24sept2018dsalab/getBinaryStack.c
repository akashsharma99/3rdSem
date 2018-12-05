#include<stdio.h>
#include<stdlib.h>
struct node
{
      struct node* next;
      int data;
}*top=NULL;
void push(int n)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=n;
      temp->next=top;
      top=temp;
      return;
}
int pop()
{
      if(top==NULL)
      {
            return -9;
      }
      int v=top->data;
      top=top->next;
      return v;
}
void makeBinary(int num)
{
      if(num==0){
            push(0);
            return;
      }
      while(num!=0)
      {
            push(num%2);
            num=num/2;
      }
      return;
}

int main()
{
      int n;
      printf("Enter a decimal number: ");
      scanf("%d",&n);
      makeBinary(n);
      int b=pop();
      while(b!=-9){
            printf("%d",b);
            b=pop();
      }
      printf("\n");
      return 0;
}
