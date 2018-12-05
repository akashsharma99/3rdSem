import java.util.Scanner;
import java.util.Formatter;
class VideoStoreLauncher
{
      /*A launcher class to */
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
                        try{
                              double rate=sc.nextDouble();
                              while(!(rate>=1 && rate<=5))
                              {
                                    System.out.print("Please enter rating in the given range only: ");
                                    rate=sc.nextDouble();
                              }
                              store.receiveRating(mov,rate);
                        }
                        catch(Exception e){
                              System.out.println("Invalid input, Please try again!");
                        }
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
