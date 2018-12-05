/*
WAP to swap the a elemnts of two arrays such that their sum is equal.
a1: 3,2,10,12 = 27
a2: 6,4,9,10 = 29
after swap
a1: 4,2,10,12 = 28
a2: 6,3,9,10 = 28
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
      int arr1[5],arr2[5];
      printf("Enter elements of first array: ");
      scanf("%d%d%d%d%d",&arr1[0],&arr1[1],&arr1[2],&arr1[3],&arr1[4]);
      int s1=arr1[0]+arr1[1]+arr1[2]+arr1[3]+arr1[4];
      printf("Sum1: %d\n",s1);
      printf("Enter elements of second array: ");
      scanf("%d%d%d%d%d",&arr2[0],&arr2[1],&arr2[2],&arr2[3],&arr2[4]);
      int s2=arr2[0]+arr2[1]+arr2[2]+arr2[3]+arr2[4];
      printf("sum2: %d\n",s2);
      int flag=0;
      if(s2>s1 && ((s2-s1)/2)%2==0)
      {
            int diff=(s2-s1)/2;
            for(int i=0;i<5;i++)
            {
                  for(int j=0;j<5;j++)
                  {
                        if(arr2[i]-arr1[j]==diff)
                        {
                              int t=arr2[i];
                              arr2[i]=arr1[j];
                              arr1[j]=t;
                              flag=1;
                              s2=s2-diff;
                              s1=s1+diff;
                              break;
                        }
                  }
                  if(flag!=0)break;
            }

      }
      if(s1>s2 && ((s1-s2)/2)%2==0)
      {
            int diff=(s1-s2)/2;
            for(int i=0;i<5;i++)
            {
                  for(int j=0;j<5;j++)
                  {
                        if(arr1[i]-arr2[j]==diff)
                        {
                              int t=arr1[i];
                              arr1[i]=arr2[j];
                              arr2[j]=t;
                              flag=1;
                              s1=s1-diff;
                              s2=s2+diff;
                              break;
                        }
                  }
                  if(flag!=0)break;
            }

      }
      if(flag!=0)
      {
            printf("After swapping...\n");
            printf("arr1: %d %d %d %d %d\n",arr1[0],arr1[1],arr1[2],arr1[3],arr1[4]);
            printf("sum1: %d\n",s1);
            printf("arr2: %d %d %d %d %d\n",arr2[0],arr2[1],arr2[2],arr2[3],arr2[4]);
            printf("sum2: %d\n",s2);
      }
      else
      {
            printf("Swapping not possible\n");
      }
      return 0;
}
