/*class hello
{

void func()
{
      byte a=(byte)10;
int b=-10;
boolean c=true;
boolean d=false;
System.out.println((byte)a<<4);
}
      static public void main(String args[])
      {
            //int i;
            //System.out.println(i);
            hello obj=new hello();
            obj.func();
      }
}
class Bike
{
      int speedlimit=90;
}
class Honda extends Bike{
      int speedlimit=150;
      public static void main(String args[]){
            Bike obj=new Bike();
            System.out.println(obj.speedlimit);
}
}
*/
class Animal {
Animal()
{
      System.out.println("Constructor of parent!");
}
}
class Dog extends Animal
{
      Dog()
      {
            System.out.println("Child class constructor");
      }
static void method(Animal a)
{

System.out.println("ok downcasting performed");
}
public static void main (String [] args)
{
Animal a=new Dog();
Dog.method(a);
}}
