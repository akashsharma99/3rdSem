import java.io.*;
class FirstChar
{
     public static void main(String args[])throws IOException
     {
          File f=new File("p2File.txt");
          if(f.exists())
          {
               FileReader fr=new FileReader(f);
               int ch;
               if((ch=fr.read())!=-1)
                    System.out.println("The first character in the file is: "+(char)ch);
               else
                    System.out.println("File is empty!");
               fr.close();
          }
          else
          System.out.println("File does not exist!");
          
     }
}
