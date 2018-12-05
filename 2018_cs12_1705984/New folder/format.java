import java.util.Scanner;
class Format
{
     String formatString(String a,String b)
     {
          int lt1=a.length();
          int lt2=b.length();
          return (lt1<=lt2)?a+b+a:b+a+b;
     }
}
class Test
{
     public static void main(String args[])
     {
          Scanner sc=new Scanner(System.in);
          System.out.println("Enter 1st String: ");
          String a=sc.nextLine();
          System.out.println("Enter 2nd String: ");
          String b=sc.nextLine();
          Format obj=new Format();
          System.out.println("New String: "+obj.formatString(a,b));

     }
}
