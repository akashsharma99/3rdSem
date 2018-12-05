import java.util.*;
class InvalidCountryException extends Exception
{
     InvalidCountryException(String s)
     {
          super(s);
     }
}
class UserRegistration
{
     public static void main(String args[])
     {
          Scanner sc=new Scanner(System.in);
          System.out.print("Enter username: ");
          String us=sc.nextLine();
          System.out.print("Enter country: ");
          String cont=sc.nextLine();
          UserRegistration ob=new UserRegistration();
          ob.registerUser(us,cont);
     }
     void registerUser(String user,String loc)
     {
          try{
               if(!(loc.equalsIgnoreCase("India")))
               {
                    throw new InvalidCountryException("User Outside India cannot be registered!");
               }
               System.out.println("User Registration done successfully!");
          }
          catch(InvalidCountryException e)
          {
               System.out.println(e.getMessage());
          }
     }
}
