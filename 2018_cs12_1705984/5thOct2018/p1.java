class Animal
{
      void eat()
      {
            System.out.println("Animal eats!");
      }
      void sleep()
      {
            System.out.println("Animal sleeps too!");
      }
}
class Bird extends Animal
{
      void eat()
      {
            System.out.println("Bird eats worms!");
      }
      void sleep()
      {
            System.out.println("Bird sleeps inside a nest!");
      }
      void fly()
      {
            System.out.println("Birds can fly except a few weird ones.");
      }
}
class test1
{
      public static void main(String args[])
      {
            Animal an=new Animal();
            an.eat();
            an.sleep();
            Bird brd=new Bird();
            brd.eat();
            brd.sleep();
            brd.fly();
      }
}
