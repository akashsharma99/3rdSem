#include<stdio.h>
#include<stdlib.h>
int main()
{
      char *st=(char*)malloc(sizeof(char));
      printf("Enter a string: ");
      scanf("%[^\n]s",st);
      printf("%s",st);
      int lt=strlen(st);
      return 0;
}
