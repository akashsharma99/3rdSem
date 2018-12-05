import java.util.Scanner;
class CopyCopy
{
     String copychar(String st)
     {
          Scanner sc=new Scanner(System.in);
          System.out.print("Enter number of times to copy: ");
          int n=sc.nextInt();
          n=n-1;
          if(st.length()<2)
               return "...";
          else
          {
               for(int i=1;i<=n;i++)
               {
                    char c1=st.charAt(0);
                    char c2=st.charAt(1);
                    st=c1+""+c2+st;
               }
          }
          return st;
     }
}
class Test
{
     public static void main(String args[])
     {
          Scanner sc=new Scanner(System.in);
          System.out.println("Enter a String with more than 1 characters: ");
          String s=sc.nextLine();
          CopyCopy obj=new CopyCopy();
          System.out.println("Modified String: "+obj.copychar(s));
     }
}
