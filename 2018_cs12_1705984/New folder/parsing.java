import java.util.Scanner;
class Strnum
{
      void numnum()
      {
            Scanner sc=new Scanner(System.in);
            int n=Integer.parseInt(sc.nextLine());
            System.out.println("Square is: "+(n*n));
      }
}
class Test
{
      public static void main(String args[])
      {
            try
            {
                  System.out.print("Enter a number: ");
                  Strnum obj=new Strnum();
                  obj.numnum();
            }
            catch(NumberFormatException e)
            {
                  System.out.println("Entered number is not a valid format of integer.");
            }
      }
}
