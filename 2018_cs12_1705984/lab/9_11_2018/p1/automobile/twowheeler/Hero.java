package automobile.twowheeler;
import automobile.*;
public class Hero extends Vehicle
{
     public String getModelName()
     {
          return("Model: Splendor");
     }
     public String getRegistrationNumber()
     {
          return("Reg: WB2059A7");
     }
     public String getOwnerName()
     {
          return("Owner: Akash Sharma");
     }
     public int getSpeed()
     {
          return(210);
     }
     public void radio()
     {
          System.out.println("Radio: Yes");
     }
}
