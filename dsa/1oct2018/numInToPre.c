#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//will only work for numbers as operands even for multidigit numbers
struct node
{
      int a;
      struct node* next;
};
void push(struct node** s,int ch)
{printf("helloPUSH\n");
      struct node* temp=(struct node*)malloc(sizeof(struct node));printf("Push1\n");
      temp->a=ch;printf("Push2\n");
      temp->next=*s;printf("Push3\n");
      *s=temp;printf("Push4\n");
      return;
}
int pop(struct node** s)
{
      int v=(*s)->a;
      (*s)=(*s)->next;
      return v;
}
int operator(char ch)
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

//                  if( (i!=(lt-1) && operator(st[i+1])==1) || (i!=0 && st[i-1]>='0' && st[i-1]<='9'))
//                  {
//                        printf("Invalid expression!\n");
//                        return 0;
//                  }
                  printf("POINTAAA\n");
                  push(&stack,(int)(st[i]));
            }
            else if(st[i]==')' || st[i]=='}' || st[i]==']')
            {
                  printf("POINTBB\n");
//                  if((i!=0 && operator(st[i-1])==1) || (i!=(lt-1) && st[i+1]>='0' && st[i+1]<='9'))
//                  {
//                        printf("Invalid expression!\n");
//                        return 0;
//                  }
                  if(stack==NULL)
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  char p=(char)(pop(&stack));
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

int evaluate(int* postfix,int k)
{
      struct node* stack2=NULL;
      int val=0;
      for(int i=k-1;i>=0;i--)
      {

            if(postfix[i]<0)
            {
                  int top=pop(&stack2);
                  int topButOne=pop(&stack2);
                  switch((char)(-1*postfix[i]))
                  {
                        case '+':push(&stack2,top+topButOne);break;
                        case '-':push(&stack2,top-topButOne);break;
                        case '*':push(&stack2,top*topButOne);break;
                        case '/':push(&stack2,top/topButOne);break;
                        case '^':push(&stack2,pow(top,topButOne));
                  }
                  printf("%d========",stack2->a);
            }
            else
            {
                  push(&stack2,postfix[i]);
                  printf("%d========",stack2->a);
            }
      }
      if(stack2!=NULL)
      {
            return pop(&stack2);
      }
      return 0;
}
int main()
{
      struct node* stack=NULL;
      printf("Enter infix expression: ");
      char* st=(char*)malloc(sizeof(char));
      scanf("%s",st);
      char s[strlen(st+1)];
      s[0]='(';
      strcat(s,st);
      int postfix[strlen(s)];
      if(isValidExpression(st))
      {
            int i,k=0,lt=strlen(s);
            push(&stack,(int)')');
            for(i=lt-1;i>=0;i--)
            {
                  printf("\n ..main %c main.. \n",s[i]);
                  if(s[i]=='(')
                  {
                        char ch=(char)pop(&stack);
                        while(ch!=')')
                        {
                              postfix[k++]=-1*(int)ch;
                              ch=(char)pop(&stack);
                        }
                  }
                  else if(s[i]==')')
                  {
                        push(&stack,(int)s[i]);
                  }
                  else if(operator(s[i]))
                  {
                        char top=(char)stack->a;
                        while(precedence(top)>precedence(s[i]))
                        {
                              postfix[k++]=-1*pop(&stack);
                              top=stack->a;
                        }
                        push(&stack,(int)s[i]);
                  }
                  else
                  {
                        while(i!=0 && s[i-1]>='0' && s[i-1]<='9')
                        {
                              i--;
                        }
                        postfix[k++]=atoi(&s[i]);
                  }
            }
            printf("PreFix: ");
            for(int i=k-1;i>=0;i--)
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
