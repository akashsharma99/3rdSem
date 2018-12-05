#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *lchild,*rchild;
}*root;

void search(int info,struct node**c,struct node**p)
{
  if(root==NULL)
    return;
  if(root->info==info)
  {
    *p=NULL;
    *c=root;
    //printf("FOUND\n");
    return;
  }
  *c=root;
  *p=NULL;
  while(*c!=NULL)
  {
    if(info<(*c)->info)
    {
      *p=*c;
      (*c)=(*c)->lchild;
    }
    else if(info>(*c)->info)
    {
      *p=*c;
      (*c)=(*c)->rchild;
    }
    else
    {
      //printf("%d",(*p)->info);
      //printf("FOUND");
      return;
    }
  }
  //p=c=NULL;
}

void insert(int info)
{
  struct node *c=NULL,*p=NULL;
  search(info,&c,&p);
  if(c!=NULL)
  {
    //printf("Element already exists");
    return;
  }
  struct node *t=(struct node *)malloc(sizeof(struct node));
  t->info=info;
  t->lchild=t->rchild=NULL;
  if(root==NULL)
  {
    root=t;
    return;
  }
  if(info<p->info)
    p->lchild=t;
  else
    p->rchild=t;
}

void delete_leaf(int info,struct node **c,struct node **p)
{
  if(*p==NULL)
    root=NULL;
  else if((*p)->lchild==(*c))
    (*p)->lchild=NULL;
  else
    (*p)->rchild=NULL;
  //free(*c);
}

void delete_one_child(int info,struct node **c,struct node **p)
{
  if((*c)->lchild!=NULL)
  {
    if(*p==NULL)
      root=(*c)->lchild;
    else if((*p)->lchild==(*c))
      (*p)->lchild=(*c)->lchild;
    else
      (*p)->rchild=(*c)->lchild;
  }
  else
  {
    if(*p==NULL)
      root=(*c)->rchild;
    else if((*p)->lchild==(*c))
      (*p)->lchild=(*c)->rchild;
    else
      (*p)->rchild=(*c)->rchild;
  }
  //free(*c);
}

void delete_two_child(int info,struct node **c,struct node **p)
{
  struct node *c1,*p1;
  c1=(*c)->rchild;
  p1=(*c);
  while(c1->lchild!=NULL)
  {
    p1=c1;
    c1=c1->lchild;
  }
  (*c)->info=c1->info;
  if(c1->rchild==NULL)
    delete_leaf(info,c,p);
  else
    delete_one_child(info,c,p);
  //free(*c);
}

void delete(int info)
{
  if(root==NULL)
  {
    printf("Empty Tree");
    return;
  }
  struct node*c=NULL,*p=NULL;
  search(info,&c,&p);
  printf("%d",(p)->info);
  if(c==NULL)
  {
    printf("%d not Found",info);
    return;
  }
  if(c->lchild==NULL && c->rchild==NULL)
  {
    //printf("Leaf\n");
    printf("%d",(p)->lchild->info);
    delete_leaf(info,&c,&p);
  }
  else if(c->lchild==NULL || c->rchild==NULL)
  {
    delete_one_child(info,&c,&p);
    //printf("Ek bachcha hai\n");
  }
  else
  {
    delete_two_child(info,&c,&p);
    //printf("Do bachcha hai\n");
  }
}

void preorder(struct node *ptr)//root->left->right
{
  if(ptr!=NULL)
  {
    printf("%d\t",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
  }
}

void inorder(struct node *ptr)//left->root->right
{
  if(ptr!=NULL)
  {
    inorder(ptr->lchild);
    printf("%d\t",ptr->info);
    inorder(ptr->rchild);
  }
}

void postorder(struct node *ptr)//left->right->root
{
  if(ptr!=NULL)
  {
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d\t",ptr->info);
  }
}

int height(struct node *ptr)
{
  int lheight,rheight;
  if(ptr==NULL)
    return -1;
  lheight=height(ptr->lchild);
  rheight=height(ptr->rchild);
  return(lheight>rheight?(lheight+1):(rheight+1));
}

int main()
{
  printf("Enter numbers or -1 to exit\n");
  int ch;
  scanf("%d",&ch);
  while(ch!=-1)
  {
    insert(ch);
    scanf("%d",&ch);
  }
  printf("Preorder:");
  preorder(root);
  printf("\n");
  printf("Inorder:");
  inorder(root);
  printf("\n");
  printf("Postorder:");
  postorder(root);
  printf("\n");
  delete(5);
  printf("Preorder:");
  preorder(root);
  printf("\n");
  printf("Inorder:");
  inorder(root);
  printf("\n");
  printf("Postorder:");
  postorder(root);
  printf("\n");
  printf("Height of the tree is %d",height(root));
}
