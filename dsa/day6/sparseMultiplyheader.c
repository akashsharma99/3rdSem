#include<stdio.h>
#include<malloc.h>
struct node
{
      int r,c,val;
      struct node* next;
};
struct head
{
      int rows,cols,tot;
      struct node* next;
};
void insert(struct head** h)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      scanf("%d%d%d",&temp->r,&temp->c,&temp->val);
      temp->next=NULL;
      struct node* p=(*h)->next;
      if(p==NULL)
      {
            (*h)->next=temp;
            return;
      }
      while(p->next!=NULL)
      {
            p=p->next;
      }
      p->next=temp;
      return;
}
void search(struct head **h,int a,int b,int val)
{
        struct node* p=(*h)->next;
        if(p==NULL)
        {
             struct node* temp=(struct node*)malloc(sizeof(struct node));
             temp->val=val;
             temp->r=a;
             temp->c=b;
             temp->next=NULL;
             (*h)->next=temp;
             ((*h)->tot)++;
             return;
        }
        while(p->next!=NULL)
        {
             if(p->r==a && p->c==b)
             {
                  p->val=p->val+val;
                  return;
             }
             p=p->next;
        }
        if(p->r==a && p->c==b)
        {
             p->val=p->val+val;
             return;
        }
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->val=val;
        temp->r=a;
        temp->c=b;
        temp->next=NULL;
        p->next=temp;
        ((*h)->tot)++;
        return;
}
int main()
{
      struct head *head1=(struct head*)malloc(sizeof(struct head));
      struct head *head2=(struct head*)malloc(sizeof(struct head));
      struct head *head3=(struct head*)malloc(sizeof(struct head));
      head3->next=NULL;
      printf("Enter number of rows-columns-elements in the first triplet form:\n");
      scanf("%d%d%d",&head1->rows,&head1->cols,&head1->tot);
      head1->next=NULL;
      printf("Enter number of rows-columns-elements in the second triplet form:\n");
      scanf("%d%d%d",&head2->rows,&head2->cols,&head2->tot);
      head2->next=NULL;
      if(head1->cols==head2->rows)
      {
            head3->rows=head1->rows;
            head3->cols=head2->cols;
            head3->tot=0;
            printf("Enter row index, column index, element value for 1st matrix:\n");
            for(int i=1;i<=head1->tot;i++)
            {
                  insert(&head1);
            }
            printf("\n\nEnter row index, column index, element value for 2nd matrix:\n");
            for(int i=1;i<=head2->tot;i++)
            {
                  insert(&head2);
            }
            struct node* m1=head1->next;
            for(int i=1;i<=head1->tot;i++)
            {
                  struct node* m2=head2->next;
                  for(int j=1;j<=head2->tot;j++)
                  {
                        if(m1->c==m2->r)
                        {
                              int num=m1->val*m2->val;
                              search(&head3,m1->r,m2->c,num);
                        }
                        m2=m2->next;
                  }
                  m1=m1->next;
            }
            printf("Result is:\n");
            printf("rows=%d\ncols=%d\ntot=%d\n",head3->rows,head3->cols,head3->tot);
            struct node* m3=head3->next;
            while(m3!=NULL)
            {
                  printf("%d %d %d\n",m3->r,m3->c,m3->val);
                  m3=m3->next;
            }
      }
      else
      {
            printf("Multiplication not possible!\n");
      }
      return 0;
}



  /*
  if(a[0][1]==b[0][0])
  {
    int **c=(int **)calloc(t1+t2+1,sizeof(int *));
    for (int i=0;i<=(t1+t2);i++)
         c[i]=(int *)calloc(3,sizeof(int));
    int num=0;
    int size=1;
    for(int i=1;i<=t1;i++)
    {
      for(int j=1;j<=t2;j++)
      {
        if(a[i][1]==b[j][0])
        {
          num=a[i][2]*b[j][2];
          int p=search(c,size,a[i][0],b[j][1]);
          if(p==-1)
          {
            c[size][0]=a[i][0];
            c[size][1]=b[j][1];
            c[size][2]=num;
            size++;
          }
          else
          {
            c[p][2]+=num;
          }
        }
      }
    }
    printf("Multiplied form is:\n");
    c[0][0]=a[0][0];
    c[0][1]=b[0][1];
    c[0][2]=size-1;
    for(int i=size;i<=t1+t2;i++)
      free(c[i]);
    for(int i=0;i<size;i++)
    {
      printf("%d\t%d\t%d\n",c[i][0],c[i][1],c[i][2]);
    }
  }
  else
    printf("Multiplication not possible\n");
  return 0;
}
*/
