import java.util.Scanner;
class ArrayClass
{
     Scanner sc=new Scanner(System.in);
     int arr[];
     void createArray()
     {
          System.out.println("Enter size of array: ");
          int s=sc.nextInt();
          arr=new int[s];
          System.out.println("Input elements: ");
          for(int i=0;i<s;i++)
          {
               arr[i]=sc.nextInt();
          }
     }
     void displayElement()
     {
          System.out.println("Enter index of element to display: ");
          int i=sc.nextInt();
          System.out.println("element at index ["+i+"]"+" is : "+arr[i]);
     }
}
class Test
{
     public static void main(String args[])
     {
          try{
               ArrayClass obj=new ArrayClass();
               obj.createArray();
               obj.displayElement();
          }
          catch(Exception e)
          {
               System.out.println(e);
          }
     }
}
