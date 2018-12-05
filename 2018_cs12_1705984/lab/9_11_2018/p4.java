import java.io.*;
class Words
{
     public static void main(String args[])throws IOException
     {
          File f=new File("p4File.txt");
          if(f.exists())
          {
               FileReader fr=new FileReader(f);
               int ch,count=0;
               while((ch=fr.read())!=-1){
                    if(ch==32 || (char)ch=='\n')
                    count++;
               }
               System.out.println("Number of words: "+count);
               fr.close();
          }
          else
          System.out.println("File does not exist!");

     }
}
