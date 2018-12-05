#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
      char b;
      struct node* next;
};
void push(struct node** s,char ch)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->b=ch;
      temp->next=*s;
      *s=temp;
      return;
}
char pop(struct node** s)
{
      if(s==NULL)
      {
            return 'a';
      }
      char v=(*s)->b;
      (*s)=(*s)->next;
      return v;
}
int main()
{
      struct node* stack=NULL;
      char *st=(char*)malloc(sizeof(char));
      printf("Enter an expression: ");
      scanf("%s",st);
      int i,lt=strlen(st);
      for(i=0;i<lt;i++)
      {
            if(st[i]=='(' || st[i]=='{' || st[i]=='[')
            {
                  push(&stack,st[i]);
            }
            else if(st[i]==')' || st[i]=='}' || st[i]==']')
            {
                  if(stack==NULL)
                  {
                        printf("Unbalanced\n");
                        return 0;
                  }
                  char p=pop(&stack);
                  if(st[i]==')' && p!='(')
                  {
                        printf("Unbalanced\n");
                        return 0;
                  }
                  else if(st[i]=='}' && p!='{')
                  {
                        printf("Unbalanced\n");
                        return 0;
                  }
                  else if(st[i]==']' && p!='[')
                  {
                        printf("Unbalanced\n");
                        return 0;
                  }
            }
      }
      if(stack!=NULL)
      {
            printf("Unbalanced\n");
            return 0;
      }
      printf("Balanced\n");
      return 0;
}
