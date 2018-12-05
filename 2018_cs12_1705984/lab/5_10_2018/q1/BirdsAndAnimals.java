class Animal
{
     void eat()
     {
          System.out.println("I dont know which animal I am. *crying");
     }
     void sleep()
     {
          System.out.println("Tell me which animal I am and I will go to sleep.");
     }
}
class Bird extends Animal
{
     void eat()
     {
          System.out.println("We birds love to eat them wiggly woggly worms at dawn!");
     }
     void sleep()
     {
          System.out.println("Aah! there's no place like a tree for a good night's sleep.");
     }
     void fly()
     {
          System.out.println("I am a bird with wings and I know how to fly!");
     }
     public static void main(String args[])
     {
          Animal ref1=new Animal();
          ref1.eat();
          ref1.sleep();
          Bird ref2=new Bird();
          ref2.eat();
          ref2.sleep();
          ref2.fly();
     }
}
