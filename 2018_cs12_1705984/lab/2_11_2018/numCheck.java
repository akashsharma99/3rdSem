import java.util.Scanner;
class NumCheck
{
     int input()
     {
          System.out.println("Enter a Number: ");
          Scanner sc=new Scanner(System.in);
          int n=Integer.parseInt(sc.nextLine());
          return n;
     }
}
class Test
{
     public static void main(String args[])
     {
          try
          {
               NumCheck obj=new NumCheck();
               int n=obj.input();
               System.out.println("Square of number: "+n*n);
          }
          catch(NumberFormatException e)
          {
               System.out.println("Entered input is not a valid format of Integer.");
          }
     }
}
