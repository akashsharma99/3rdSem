
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
                        if(invent[i].returned())
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
