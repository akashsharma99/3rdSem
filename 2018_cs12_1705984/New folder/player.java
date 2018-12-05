interface Playable
{
      void play();
}
class Violin implements Playable
{
      public void play()
      {
            System.out.println("The Violin is playing!");
      }
}
class Keyboard implements Playable
{
      public void play()
      {
            System.out.println("The Keyboard is playing!");
      }
}
class Test
{
      public static void main(String args[])
      {
            Playable v=new Violin();
            Playable k=new Keyboard();
            v.play();
            k.play();
      }
}
