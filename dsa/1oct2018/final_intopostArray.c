#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//will only work for numbers as operands even for multidigit numbers
int top;
int stack[100];
int size;
int postfix[100];
void initStack(int s)
{
      size=s;
      top=-1;
      for(int i=0;i<=size;i++)
            stack[i]=0;
}
void push(int ch)
{
      if(top==size-1){
            printf("pushOVERFLOW!\n");
            return;
      }
      stack[++top]=ch;
      return;
}
int pop()
{
      if(top==-1){
            printf("popUNDERFLOW!\n");
            return -999;
      }
      int v=stack[top];
      top--;
      return v;
}
int peek()
{
      if(top==-1){
            printf("peekUNDERFLOW!\n");
            return -999;
      }
      int v=stack[top];
      return v;
}
int operatorr(char ch)
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
int isValidExpression(char* st,int lt)
{
      initStack(lt);
      int i;
      for(i=0;i<lt;i++)
      {
            if((st[i]>='a'&&st[i]<='z') || (st[i]>='A'&&st[i]<='Z'))
            {
                  printf("Variables not allowed!");
                  return 0;
            }
            if(operatorr(st[i])==1)
            {
                  if( ( (i!=(lt-1)) && operatorr(st[i+1])==1 ) || i==0 )
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
            }
            if(st[i]=='(' || st[i]=='{' || st[i]=='[')
            {
                  if( (i!=(lt-1) && operatorr(st[i+1])==1) || (i!=0 && st[i-1]>='0' && st[i-1]<='9'))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  push((int)(st[i]));
            }
            else if(st[i]==')' || st[i]=='}' || st[i]==']')
            {
                  if((i!=0 && operatorr(st[i-1])==1) || (i!=(lt-1) && st[i+1]>='0' && st[i+1]<='9'))
                  {
                        printf("Invalid expression!\n");
                        return 0;
                  }
                  if(top==-1)
                  {
                        printf("Unbalanced Brackets\n");
                        return 0;
                  }
                  char p=(char)(pop());
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
      if(top!=-1)
      {
            printf("Unbalanced Brackets\n");
            return 0;
      }
      //printf("Balanced\n");
      return 1;
}

int evaluate(int k)
{
      initStack(k);
      for(int i=0;i<k;i++)
      {
            if(postfix[i]<0)
            {
                  int pot=pop();
                  int topButOne=pop();
                  switch((char)(-1*postfix[i]))
                  {
                        case '+':push(topButOne+pot);break;
                        case '-':push(topButOne-pot);break;
                        case '*':push(topButOne*pot);break;
                        case '/':push(topButOne/pot);break;
                        case '^':push((int)pow(topButOne,pot));
                  }
            }
            else
            {
                  push(postfix[i]);
            }
      }
      if(top!=-1)
      {
            return pop();
      }
      return 0;
}
int main()
{
     printf("Enter infix expression: ");
      char* st=(char*)malloc(sizeof(char));
      scanf("%s",st);
      char s[strlen(st)+1];
      //copy st into s
      int i;
      for(i=0;i<strlen(st);i++)
            s[i]=st[i];

      s[strlen(st)]=')';
      //s[strlen(st)+1]='\0';
      if(isValidExpression(st,strlen(st)))
      {
            int i,k=0,lt=strlen(st)+1;
            initStack(lt);
            push((int)'(');
            for(i=0;i<lt;i++)
            {
                if(s[i]=='(')
                {
                        push((int)'(');
                }
                else if(s[i]==')')
                {
                    char ch=(char)pop();
                    while(ch!='(')
                    {
                        postfix[k++]=-1*(int)ch;
                        ch=(char)pop();
                    }
                }
                else if(operatorr(s[i])==1)
                {
                    char pot=(char)peek();
                    while(operatorr(pot)==1 && precedence(pot)>=precedence(s[i]))
                    {
                          postfix[k++]=-1*pop();
                          pot=(char)peek();
                    }
                    push((int)s[i]);
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
            printf("Postfix: ");
            for(int i=0;i<k;i++)
            {
                  if(postfix[i]<0)
                  {
                        printf("%c ",(-1*postfix[i]));
                  }
                  else
                  printf("%d ",postfix[i]);
            }
            int eval=evaluate(k);
            printf("\nAnswer: %d\n",eval);
      }
      return 0;
}
