#include<stdlib.h>
#include<stdio.h>

struct node
{
	int key;
	struct node *left, *right;
};

// Utitlity function to create a new node
struct node* getNewnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node* insert(struct node* root, int key)
{
	struct node* newnode = getNewnode(key);
	struct node* curr = root;
	struct node* prev = NULL;
	while (curr != NULL) {
		prev = curr;
		if (key < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (prev == NULL)
		return newnode;
	else if (key < prev->key){
		prev->left = newnode;
            return root;
      }
	else{
		prev->right = newnode;
            return root;
      }

	// Returns the pointer where the new node is inserted
      return prev;

}

// A utility function to do inorder
// traversal of BST
void Inorder(struct node* root)
{
	if (root == NULL)
		return;
	else {
		Inorder(root->left);
		printf("%d,",root->key);
		Inorder(root->right);
	}
}

struct node* delete(struct node* root,int key)
{
      struct node* prev=NULL,*curr=root;
      int flag=0;
      while (curr != NULL) {
            if(key==curr->key)
            {
                  flag=1;
                  break;
            }
		prev = curr;

		if (key < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
      if(flag==0)
      {
            System.out.println("Key not found!");
            return root;
      }
      else{
            if (curr->left == NULL && curr->right==NULL)//when ley is at leaf node
            {
                  if(prev==NULL)//for single node in tree
                  {
                        root=NULL;
                        free(curr);
                  }
                  if(prev->left == curr)
                  {
                        prev->left=NULL;
                        free(curr);
                  }
                  else
                  {
                        prev->right=NULL;
                        free(curr);
                  }
            }
            else if(curr->left !=NULL)
            {
                  struct node* c=curr->left,*prevc=c;
                  while(c->right!=NULL)
                  {
                        prevc=c;
                        c=c->right;
                  }
                  if(prev==NULL)//root node
                  {
                        c->
                  }
                  curr->key=c->key;
                  prevc->right=NULL;



            }
      		return newnode;
      }


}
int main()
{
      struct node* root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);

	// Print inoder traversal of the BST
	Inorder(root);

	return 0;
}
