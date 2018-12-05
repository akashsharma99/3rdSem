import java.util.Scanner;
import java.util.Formatter;
class Video
{
      String title;
      int checked;
      double avgUserRating;
      int rt;
      Video(String t)
      {
            title=t;
            checked=0;
            avgUserRating=0;
            rt=0;
      }
      boolean checking()
      {
            if(checked==1)
                  return false;
            else
                  checked=1;
            return true;
      }
      void returned()
      {
            checked=0;
            return;
      }
      void rating(double rate)
      {
            if(rt==0)
            {
                  avgUserRating=rate;
                  rt++;return;
            }
            avgUserRating=((avgUserRating*rt)+rate)/(rt+1);
            rt++;
            return;
      }
}

class VideoStore
{
      Video invent[]=new Video[10];
      int top;
      VideoStore()
      {
            top=-1;
      }
      boolean addVideo(String t)
      {
            if(top==9)
            {
                  System.out.println("Inventory Full !");
                  return false;
            }
            top++;
            for(int i=0;i<top;i++)
            {
                  if(invent[i].title.equalsIgnoreCase(t))
                  {
                        System.out.println("Video already exists !");
                        return false;
                  }
            }
            invent[top]=new Video(t);
            return true;
      }
      boolean checkOut(String t)
      {
            for(int i=0;i<=top;i++)
            {
                  if(invent[i].title.equalsIgnoreCase(t))
                  {
                        if(invent[i].checking())
                        {
                              return true;
                        }
                        System.out.println("Video already checked out");
                        return false;
                  }
            }
            System.out.println("Sorry video not in inventory!");
            return false;
      }
      boolean returnVideo(String t)
      {
            for(int i=0;i<=top;i++)
            {
                  if(invent[i].title.equalsIgnoreCase(t))
                  {
                        invent[i].returned();
                        return true;
                  }
            }
            System.out.println("Sorry this video was not borrowed from here !");
            return false;
      }
      boolean receiveRating(String t,double rate)
      {
            for(int i=0;i<=top;i++)
            {
                  if(invent[i].title.equalsIgnoreCase(t))
                  {
                        invent[i].rating(rate);
                        return true;
                  }
            }
            System.out.println("Video not found in inventory");
            return false;
      }
      void listInventory()
      {
            if(top==-1)
            {
                  System.out.println("Invetory Empty!");
            }
            else
            {
                  String a="TITLE";
                  String b="RATING";
                  String c="STATUS";
                  System.out.format("%-40s%-10s%-10s",a,b,c);
                  System.out.println("\n---------------------------------------------------------------------");
                  for(int i=0;i<=top;i++)
                  {
                        String ch="\tAvailable";
                        if(invent[i].checked==1)
                        ch="\tRented";
                        System.out.format("%-40s%.2f%-11s",invent[i].title,invent[i].avgUserRating,ch);
                        System.out.println();
                        //System.out.println((i+1)+". "+invent[i].title+" rating:"+invent[i].avgUserRating+" status:"+ch);
                  }
            }
            return;
      }
}


class VideoStoreLauncher
{
      public static void main(String args[])
      {
            System.out.println("Welcome to Blockbuster Video Store !\n");
            int ch=-1;
            VideoStore store=new VideoStore();
            Scanner sc=new Scanner(System.in);
            while(ch!=0)
            {
                  System.out.println("1. Add video to inventory");
                  System.out.println("2. Rent a video");
                  System.out.println("3. Return a video");
                  System.out.println("4. Rate a video");
                  System.out.println("5. Display Inventory");
                  System.out.print("Choose a service or press 0 to exit store: ");
                  ch=sc.nextInt();
                  String mov=sc.nextLine();
                  switch(ch)
                  {
                        case 1:
                        System.out.print("Enter movie name: ");
                        mov=sc.nextLine();
                        store.addVideo(mov);
                        break;

                        case 2:
                        System.out.print("Enter movie name: ");
                        mov=sc.nextLine();
                        if(store.checkOut(mov))
                              System.out.println("Thanks for renting \""+mov+"\"");
                        break;

                        case 3:
                        System.out.print("Enter movie name: ");
                        mov=sc.nextLine();
                        if(store.returnVideo(mov))
                              System.out.println("Thank you for using our service hope you enjoyed the movie.");
                        break;

                        case 4:
                        System.out.print("Enter movie name: ");
                        mov=sc.nextLine();
                        System.out.print("Give a rating from 1 to 5, where 5 is best: ");
                        double rate=sc.nextDouble();
                        while(!(rate>=1 && rate<=5))
                        {
                              System.out.print("Please enter rating in the given range only: ");
                              rate=sc.nextDouble();
                        }
                        store.receiveRating(mov,rate);
                        mov=sc.nextLine();
                        break;

                        case 5:
                        System.out.println("********************************************************************");
                        store.listInventory();
                        System.out.println("********************************************************************");
                        break;

                        case 0:
                        System.out.println("Bye have a nice day!");
                        break;

                        default:System.out.println("Invalid input");
                  }
            }
      }
}
