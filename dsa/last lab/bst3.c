#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node{
int data,flag;
struct Node *l ,*r;
}N;
typedef struct stack
{
    struct tree *ptr;
    struct stack *next;
}stack;
stack *Push(stack *top, N *node)
{

    stack *curr;
    curr=(stack *)malloc(sizeof(stack));
    curr->ptr=node;
    curr->next=NULL;
    if(top==NULL)
            top=curr;
    else{
        curr->next=top;
        top=curr;
    }
    return top;
}
void TravInorder(N *node)
{

    stack *top=NULL,*curr,*temp;
    do
    {

        while(node!=NULL)
        {
            top=Push(top,node);
            node=node->l;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            printf("%d ",node->data);
            node=node->r;
            temp=top;
            top=top->next;
            free(temp);
        }
    }while(top!=NULL||node!=NULL);
}
void TravPreorder(N *node)
{
    stack *top=NULL,*curr,*temp;
    do
    {
        while(node!=NULL)
        {
            printf("%d ",node->data);
            if(node->r!=NULL)
            {
                top=Push(top,node->r);
            }
            node=node->l;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            temp=top;
            top=top->next;
            free(temp);
        }
    }while(top!=NULL||node!=NULL);
}
void TravPostorder(N *node)
{
    stack *top=NULL,*curr,*temp;
    do
    {
        while(node!=NULL)
        {
            node->flag=0;
            top=Push(top,node);
            if(node->r!=NULL)
            {
                node->r->flag=1;
                top=Push(top,node->r);
            }
            node=node->l;
        }
        if(top!=NULL)
        {
            node=top->ptr;
            while(node->flag==0)
            {
                printf("%d ",node->data);
                temp=top;
                top=top->next;
                free(temp);
                node=top->ptr;
            }

            temp=top;
            top=top->next;
            free(temp);
        }
    }while(top!=NULL||node!=NULL);
}



int main()
{

    int i,n;
    N *p,*q,*t;
    printf("enter the number of nodes");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {

        p=(N*)malloc(sizeof(N));
        scanf("%d",&p->data);
        p->l=NULL;
        p->r=NULL;
        if(i==0)
        {

            t=p;//point to root

        }
        else
        {
            q=t;//traversing of tree
            while(1)
            {

                if(p->data>q->data)
                {
                    if(q->r==NULL)
                    {
                        q->r=p;
                        break;
                    }
                    else
                    {
                        q=q->r;
                    }
                }
                else
                {
                    if(q->l==NULL)
                    {
                        q->l=p;
                        break;
                    }
                    else
                    {
                        q=q->l;
                    }
                }

            }
        }
    }
    printf("\n\n preorder :-");
    TravPreorder(t);
    printf("\n\n inorder :-");
    TravInorder(t);
    printf("\n\n postorder :-");
    TravPostorder(t);
    return 0;
}
