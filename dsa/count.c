#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,high=-1;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int x,y;
      printf("Enter 1st number: ");
      scanf("%d",&x);
      printf("Enter 2nd number: ");
      scanf("%d",&y);
      int xpos=-1,ypos=-1;
      for(i=0;i<n;i++)
      {
            if(a[i]==x){
                  xpos=i;
                  if(ypos>=0)
                  break;}
            if(a[i]==y){
                  ypos=i;
                  if(xpos>=0)
                  break;}
      }
      int c=0;
      if(xpos==-1||ypos==-1)
            printf("Invalid numbers!\n");
      else
            c=(xpos<ypos)?ypos-xpos-1:xpos-ypos-1;
      printf("%d numbers present between %d and %d\n",c,x,y);
      return 0;
 }
