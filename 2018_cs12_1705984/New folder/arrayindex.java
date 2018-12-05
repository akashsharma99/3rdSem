import java.util.Scanner;
class ArrayIndex
{
      void hello()
      {
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter size of array: ");
            int s=sc.nextInt();
            int arr[]=new int[s];
            System.out.println("Enter array elements:");
            for(int i=0;i<s;i++)
                  arr[i]=sc.nextInt();
            System.out.print("Enter an index: ");
            int k=sc.nextInt();
            System.out.println("The element at "+k+" is : "+arr[k]);
      }
}
class Test
{
      public static void main(String args[])
      {
            try
            {
                  ArrayIndex ob=new ArrayIndex();
                  ob.hello();
            }
            catch(ArrayIndexOutOfBoundsException e)
            {
                  System.out.println(e);
            }
      }
}
