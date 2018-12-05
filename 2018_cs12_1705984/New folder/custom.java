import java.util.Scanner;
class InvalidCountryException extends Exception
{
      InvalidCountryException(String s)
      {
            super(s);
      }
}
class UserRegistration
{
      void registeruser(String name,String country)
      {
            try{
                  if(country.equalsIgnoreCase("india"))
                        System.out.println("User Registration Done Successfully!");
                  else
                        throw new InvalidCountryException("User outside India cannot be registered!");
            }
            catch(InvalidCountryException e)
            {
                  System.out.println(e.getMessage());
            }
      }
      public static void main(String args[])
      {
            Scanner sc=new Scanner(System.in);
            UserRegistration ob=new UserRegistration();
            System.out.print("Enter user name: ");
            String nm=sc.nextLine();
            System.out.print("Enter country name: ");
            String cont=sc.nextLine();
            ob.registeruser(nm,cont);            
      }
}
