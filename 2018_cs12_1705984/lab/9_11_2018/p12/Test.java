
import automobile.twowheeler.*;
public class Test
{
     public static void main(String args[])
     {
          Hero hero=new Hero();
          Honda honda=new Honda();
          System.out.println(hero.getModelName());
          System.out.println(hero.getRegistrationNumber());
          System.out.println(hero.getOwnerName());
          System.out.println("Speed: "+hero.getSpeed());
          hero.radio();
          System.out.println(honda.getModelName());
          System.out.println(honda.getRegistrationNumber());
          System.out.println(honda.getOwnerName());
          System.out.println("Speed: "+honda.getSpeed());
          honda.CDplayer();
     }
}
