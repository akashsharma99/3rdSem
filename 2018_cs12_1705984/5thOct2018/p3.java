class Fruit
{
      String name,taste,size;
      void eat()
      {
            name="Fruit";
            taste="Tasteless";
            size="non-existent";
      }
}
class Apple extends Fruit
{
      void eat()
      {
            name="Apple";
            taste="Bland";
            size="medium";
      }
}
class Orange extends Fruit
{
      void eat()
      {
            name="Orange";
            taste="Sour";
            size="medium";
      }
}
class test3
{
      public static void main(String args[])
      {
            Apple app=new Apple();
            app.eat();
            System.out.println("Name: "+app.name);
            System.out.println("Taste: "+app.taste);
            System.out.println("Size: "+app.size);
            Orange orr=new Orange();
            orr.eat();
            System.out.println("Name: "+orr.name);
            System.out.println("Taste: "+orr.taste);
            System.out.println("Size: "+orr.size);
      }
}
