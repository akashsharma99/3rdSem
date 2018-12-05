import java.io.*;
class WriteChar
{
     public static void main(String args[])throws IOException
     {
          File f=new File("p3File.txt");
          if(f.exists())
          {
               FileWriter fr=new FileWriter(f);
               fr.write('A');
               fr.close();
          }
          else
          System.out.println("File does not exist!");
          
     }
}
