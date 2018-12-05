abstract class GeneralBank
{
      abstract void getSavingInterestRate();
      abstract void getFixedInterestRate();
}
class ICICI extends GeneralBank
{
      void getFixedInterestRate()
      {
            System.out.println("Fixed Interest Rate: 4%");
      }
      void getSavingInterestRate()
      {
            System.out.println("Savings Interest Rate: 8.5%");
      }
}
class HDFC extends GeneralBank
{
      void getFixedInterestRate()
      {
            System.out.println("Fixed Interest Rate: 6%");
      }
      void getSavingInterestRate()
      {
            System.out.println("Savings Interest Rate: 9%");
      }
}
class test5
{
      public static void main(String args[])
      {
            HDFC hbnk=new HDFC();
            System.out.println("Using HDFC reference with HDFC class");
            hbnk.getFixedInterestRate();
            hbnk.getSavingInterestRate();
            ICICI ibnk=new ICICI();
            System.out.println("Using ICICI reference with ICICI class");
            ibnk.getFixedInterestRate();
            ibnk.getSavingInterestRate();
            GeneralBank bnk=new HDFC();
            System.out.println("Using HDFC reference with GeneralBank class");
            bnk.getFixedInterestRate();
            bnk.getSavingInterestRate();
            bnk=new ICICI();
            System.out.println("Using ICICI reference with GeneralBank class");
            bnk.getFixedInterestRate();
            bnk.getSavingInterestRate();
      }
}
