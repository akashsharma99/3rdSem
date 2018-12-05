import java.io.*;
import java.util.*;
class characters
{
     public static void main(String args[])throws IOException
     {
          File f=new File("p4File.txt");
          if(f.exists())
          {
               FileReader fr=new FileReader(f);
               Scanner sc=new Scanner(System.in);
               System.out.print("Enter a character to search: ");
               char key=sc.next().charAt(0);
               int ch,count=0;
               while((ch=fr.read())!=-1){
                    if((char)ch==key)
                    count++;
               }
               System.out.println("Number of occurences: "+count);
               fr.close();
          }
          else
          System.out.println("File does not exist!");

     }
}
