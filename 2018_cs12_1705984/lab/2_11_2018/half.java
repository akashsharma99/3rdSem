import java.util.Scanner;
class Half
{
     String getHalf(String st)
     {
          int lt=st.length();
          if(lt<2)
               return "ERROR";
          String temp=st.substring(0,lt/2);
          return temp;
     }
}
class Test
{
     public static void main(String args[])
     {
          Scanner sc=new Scanner(System.in);
          System.out.println("Enter a String: ");
          String s=sc.nextLine();
          Half obj=new Half();
          System.out.println("1st half is: "+obj.getHalf(s));
     }
}
