import java.io.*;
import java.util.*;
class WordsCount
{
     public static void main(String args[])throws IOException
     {
          File f=new File("p4File.txt");
          File f2=new File("p4copy.txt");
          if(f.exists())
          {
               Scanner fr1=new Scanner(f);
               int count=0;
               while(fr1.hasNext()){
                     String t=fr1.next();
                    count++;
               }
               String words[]=new String[count];
               fr1=new Scanner(f);
               int k=0;
//creating the array
               while(fr1.hasNext()){
                     words[k++]=fr1.next();
               }
//checking the array contents
               for(int i=0;i<k;i++)
                  System.out.print(words[i]);
                  System.out.println();
//finding freuency part
               //PrintWriter fout=new PrintWriter(new FileWriter(f2));
               FileWriter fout=new FileWriter(f2);
               for(int i=0;i<k;i++)
               {
                     String t=words[i];
                     count=0;
                     if(t.equalsIgnoreCase(".....")==false)
                     {
                        for(int j=i;j<k;j++)
                        {
                              if(words[j].equalsIgnoreCase(t))
                              {
                                    count++;
                                    words[j]=".....";
                              }
                        }
                        //fout.println(t+"\t\t:\t"+count);
                        fout.write(t+"\t\t:\t"+count+"\n");
                     }
               }
               fout.close();
          }
          else
          System.out.println("File does not exist!");

     }
}
