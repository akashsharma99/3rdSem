class Outer
{
      public void someOterMethod()
      {
            //new Inner();
      }
      public class Inner{}
            public static void main(String args[])
            {
                  Outer ot=new Outer();
                  //new Inner();
                  new Outer.Inner();
            }
}
