import java.util.Scanner;
class Fruit
{
     String name,taste,size;
     void eat()
     {
          name="Duh!";
          taste="Swoosh!";
     }
}
class Apple extends Fruit
{
     Scanner sc=new Scanner(System.in);
     void eat()
     {
          name="Apple";
          System.out.print("Enter taste of Apple: ");
          taste=sc.nextLine();
          System.out.print("Enter size of Apple: ");
          size=sc.nextLine();
          System.out.println("Taste of Apple: "+taste);
          System.out.println("Size of Apple: "+size);
     }
}
class Orange extends Fruit
{
     void eat()
     {
          Scanner sc=new Scanner(System.in);
          name="Orange";
          System.out.print("Enter taste of Orange: ");
          taste=sc.nextLine();
          System.out.print("Enter size of Orange: ");
          size=sc.nextLine();
          
          System.out.println("Taste of Orange: "+taste);
          System.out.println("Size of Orange: "+size);
     }
}
public class BonApetite
{
     public static void main(String args[])
     {
          Orange objO=new Orange();
          Apple objA=new Apple();
          objA.eat();
          objO.eat();
     }
}
