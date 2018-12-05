import java.util.*;
class Rpstr
{
     String concatStr(String a,String b)
     {
          return a+b;
     }
     void removeRpt()
     {
          Scanner sc=new Scanner(System.in);
          System.out.print("Enter 1st String: ");
          String st1=sc.nextLine();
          System.out.print("Enter 2nd String: ");
          String st2=sc.nextLine();
          String newStr=concatStr(st1,st2);
          System.out.println("Concatenated String: "+newStr);
          String temp="";
          for(int i=0;i<newStr.length();i++)
          {
               int flag=0;
               char ch=newStr.charAt(i);
               for(int j=i+1;j<newStr.length();j++)
               {
                    if(ch==newStr.charAt(j))
                    {
                         flag=1;break;
                    }
               }
               if(flag==0)
                    temp=temp+ch;
          }
          newStr=temp;
          System.out.println("The modified String is: "+newStr);
     }
}
class Test
{
     public static void main(String args[])
     {
          Rpstr obj=new Rpstr();
          obj.removeRpt();
     }
}
