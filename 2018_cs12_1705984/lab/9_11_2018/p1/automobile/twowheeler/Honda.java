package automobile.twowheeler;
import automobile.*;
public class Honda extends Vehicle
{
     public String getModelName()
     {
          return("Model: R15");
     }
     public String getRegistrationNumber()
     {
          return("Reg: OR2999A7");
     }
     public String getOwnerName()
     {
          return("Owner: Chirubhai Ambani");
     }
     public int getSpeed()
     {
          return(300);
     }
     public void CDplayer()
     {
          System.out.println("CD player: No");
     }
}
