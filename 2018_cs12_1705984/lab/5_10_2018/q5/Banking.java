abstract class Bank
{
     abstract void getSavingInterestRate();
     abstract void getFixedInterestRate();
}
class ICICI extends Bank
{
     void getSavingInterestRate()
     {
          System.out.println("4%");
     }
     void getFixedInterestRate()
     {
          System.out.println("8.5%");
     }
}
class HDFC extends Bank
{
     void getSavingInterestRate()
     {
          System.out.println("Saving Interest Rate: 6%");
     }
     void getFixedInterestRate()
     {
          System.out.println("Fixed Interest Rate: 9%");
     }
}
public class Banking
{
     public static void main(String args[])
     {
          Bank bank;
          bank=new ICICI();
          bank.getSavingInterestRate();
          bank.getFixedInterestRate();
          bank=new HDFC();
          bank.getSavingInterestRate();
          bank.getFixedInterestRate();
     }
}
