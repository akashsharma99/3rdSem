class Bike
{
      int speed=80;
      int hello()
      {
            return 80;
      }
}
class Honda extends Bike
{
      int speed=25;
      int hello()
      {
            return 25;
      }
      public static void main(String args[])
      {
            Bike obj=new Bike();
            System.out.println(obj.hello());
      }
}
