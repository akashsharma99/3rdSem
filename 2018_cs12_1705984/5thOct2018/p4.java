class NameShape
{
      void draw()
      {
            System.out.println("Drawing the shape!");
      }
      void erase()
      {
            System.out.println("Erasing the shape!");
      }
}
class Triangle extends NameShape
{
      void draw()
      {
            System.out.println("Drawing the triangle!");
      }
      void erase()
      {
            System.out.println("Erasing the triangle!");
      }
}
class Circle extends NameShape
{
      void draw()
      {
            System.out.println("Drawing the circle!");
      }
      void erase()
      {
            System.out.println("Erasing the circle!");
      }
}
class Square extends NameShape
{
      void draw()
      {
            System.out.println("Drawing the square!");
      }
      void erase()
      {
            System.out.println("Erasing the square!");
      }
}
class test4
{
      public static void main(String args[])
      {
            NameShape shape=new NameShape();
            shape=new Triangle();
            shape.draw();shape.erase();
            shape=new Square();
            shape.draw();shape.erase();
            shape=new Circle();
            shape.draw();shape.erase();
      }
}
