interface Playable
{
     void play();
}
class Violin implements Playable
{
     public void play()
     {
          System.out.println("The violin is playing!");
     }
}
class Keyboard implements Playable
{
     public void play()
     {
          System.out.println("The keyboard is playing!");
     }
}
class Test
{
     public static void main(String[] args)
     {
          Violin v=new Violin();
          Keyboard k=new Keyboard();
          v.play();
          k.play();
          Playable var=v;
          var.play();
          var=k;
          var.play();
     }
}
