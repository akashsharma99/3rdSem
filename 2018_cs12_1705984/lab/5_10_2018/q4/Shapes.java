class NameShape
{
     void draw()
     {
          System.out.println("Drawing a shape!");
     }
     void erase()
     {
          System.out.println("Erasing a shape!");
     }
}
class Circle extends NameShape
{
     void draw()
     {
          System.out.println("Drawing a circle!");
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
          System.out.println("Drawing a square!");
     }
     void erase()
     {
          System.out.println("Erasing the square!");
     }
}
class Triangle extends NameShape
{
     void draw()
     {
          System.out.println("Drawing a triangle!");
     }
     void erase()
     {
          System.out.println("Erasing the triangle!");
     }
}
public class Shapes
{
     public static void main(String args[])
     {
          NameShape shape;
          shape=new Triangle();
          shape.draw();
          shape.erase();
          shape=new Circle();
          shape.draw();
          shape.erase();
          shape=new Square();
          shape.draw();
          shape.erase();
     }
}
