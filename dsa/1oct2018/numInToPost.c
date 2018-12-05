#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//will only work for numbers as operands even for multidigit numbers
struct node
{
      char b;int a;
      struct node* next;
};
void push(struct node** s,int ch)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->a=ch;
      temp->next=*s;
      *s=temp;
      return;
}
int pop(struct node** s)
{
      if(s==NULL)
      {
            return -999;
      }
      int v=(*s)->a;
      (*s)=(*s)->next;
      return v;
}int operator(char ch)
{
      if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
            return 1;
      return 0;
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
    return 0;
}
int isValidExpression(char* st)
{
      struct node* stack=NULL;
      int i,lt=strlen(st);
      for(i=0;i<lt;i++)
      {printf("\n ..asd %c asd.. \n",st[i]);

            if((st[i]>='a'&&st[i]<='z') || (st[i]>='A'&&st[i]<='Z'))
            {
                  printf("Variables not allowed!");
                  return 0;
            }
            if(operator(st[i])==1)
            {
                  if( ( (i!=(lt-1)) && operator(st[i+1])==1 ) || i==0 )
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
            }
            if(st[i]=='(' || st[i]=='{' || st[i]=='[')
            {
                  printf("POINTAAA\n");

                  if( (i!=(lt-1) && operator(st[i+1])==1) || (i!=0 && st[i-1]>='0' && st[i-1]<='9'))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  printf("POINTAAA\n");
                  push(&stack,(int)(st[i]));
            }
            else if(st[i]==')' || st[i]=='}' || st[i]==']')
            {
                  printf("POINTBB\n");
                  if((i!=0 && operator(st[i-1])==1) || (i!=(lt-1) && st[i+1]>='0' && st[i+1]<='9'))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  if(stack==NULL)
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  char p=(char)pop(&stack);
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
/*
int operator(char ch)
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
    return 0;
}
int isValidExpression(char* st)
{
      struct node* stack=NULL;
      int i,lt=strlen(st);
      for(i=0;i<lt;i++)
      {
            if((st[i]>='a'&&st[i]<='z') || (st[i]>='A'&&st[i]<='Z'))
            {
                  printf("Variables not allowed!");
                  return 0;
            }
            if(operator(st[i]))
            {
                  if(((i!=(lt-1))&&operator(st[i+1]))||i==0)
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
            }
            if(st[i]=='(' || st[i]=='{' || st[i]=='[')
            {
                  if( (i!=(lt-1) && operator(st[i+1])) || (i!=0 && operator(st[i-1])==0))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  push(&stack,(int)st[i]);
            }
            else if(st[i]==')' || st[i]=='}' || st[i]==']')
            {
                  if((i!=0 && operator(st[i-1])) || (i!=(lt-1) && operator(st[i+1])==0))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  if(stack==NULL)
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  char p=(char)pop(&stack);
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
*/
int evaluate(int* postfix,int k)
{
      struct node* stack=NULL;
      int val=0;
      for(int i=0;i<k;i++)
      {
            if(postfix[i]<0)
            {
                  int top=pop(&stack);
                  int topButOne=pop(&stack);
                  switch((char)(-1*postfix[i]))
                  {
                        case '+':push(&stack,topButOne+top);break;
                        case '-':push(&stack,topButOne-top);break;
                        case '*':push(&stack,topButOne*top);break;
                        case '/':push(&stack,topButOne/top);break;
                        case '^':push(&stack,pow(topButOne,top));
                  }
            }
            else
            {
                  push(&stack,postfix[i]);
            }
      }
      if(stack!=NULL)
      {
            return pop(&stack);
      }
      return 0;
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
      int postfix[strlen(st)];
      if(isValidExpression(st))
      {
            int i,k=0,lt=strlen(s);
            push(&stack,(int)'(');
            for(i=0;i<lt;i++)
            {
                  if(s[i]=='(')
                  {
                        push(&stack,(int)s[i]);
                  }
                  else if(s[i]==')')
                  {
                        char ch=(char)pop(&stack);
                        while(ch!='(')
                        {
                              postfix[k++]=-1*(int)ch;
                              ch=(char)pop(&stack);
                        }
                  }
                  else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='^')
                  {
                        char top=(char)stack->a;
                        while(operator(top)>=operator(s[i]))
                        {
                              postfix[k++]=-1*pop(&stack);
                              top=stack->a;
                        }
                        push(&stack,(int)s[i]);
                  }
                  else
                  {
                        postfix[k++]=atoi(&s[i]);
                        while(s[i+1]>='0' && s[i+1]<='9')
                        {
                              i++;
                        }
                  }
            }
            printf("PostFix: ");
            for(int i=0;i<k;i++)
            {
                  if(postfix[i]<0)
                  {
                        printf("%c ",(-1*postfix[i]));
                  }
                  else
                  printf("%d ",postfix[i]);
            }
            printf("%c",'\n');
            int eval=evaluate(postfix,k);
            printf("\nAnswer: %d\n",eval);
      }
      return 0;
}
