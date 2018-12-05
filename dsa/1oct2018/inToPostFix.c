#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//will only work for alphabets as operands
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
int checkBrackets(char* st)
{
      struct node* stack=NULL;
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
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  char p=pop(&stack);
                  if(st[i]==')' && p!='(')
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  else if(st[i]=='}' && p!='{')
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  else if(st[i]==']' && p!='[')
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
            }
      }
      if(stack!=NULL)
      {
            printf("Unbalanced Brackets\n");
            return 0;
      }
      //printf("Balanced\n");
      return 1;
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int main()
{
      struct node* stack=NULL;
      printf("Enter infix expression: ");
      char* st=(char*)malloc(sizeof(char));
      scanf("%s",st);
      char s[strlen(st)+1];
      strcpy(s,st);
      s[strlen(st)]=')';
      s[strlen(st)+1]='\0';
      char postfix[strlen(st)];
      if(checkBrackets(st)==1)
      {
            int i,k=0,lt=strlen(s);
            push(&stack,'(');
            for(i=0;i<lt;i++)
            {
                  if(s[i]=='(')
                  {
                        push(&stack,s[i]);
                  }
                  else if(s[i]==')')
                  {
                        char ch=pop(&stack);
                        while(ch!='(')
                        {
                              postfix[k++]=ch;
                              ch=pop(&stack);
                        }
                  }
                  else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='^')
                  {
                        char top=stack->b;
                        while(precedence(top)>=precedence(s[i]))
                        {
                              postfix[k++]=pop(&stack);
                              top=stack->b;
                        }
                        push(&stack,s[i]);
                  }
                  else
                  {
                        postfix[k++]=s[i];
                  }
            }
            printf("PostFix: %s",postfix);
      }
      return 0;

}
