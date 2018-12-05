import java.util.Scanner;
class Patient
{
	String name;
	double weight,height;
	void getDetails()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter patient name: ");
		name=sc.nextLine();
		System.out.println("Enter height(in inches): ");
		height=sc.nextDouble();
		System.out.println("Enter weight(in pounds): ");
		weight=sc.nextDouble();
	}
	double BMI()
	{
		return (weight/(height*height))*703;
	}
}
class Patients
{
	public static void main(String args[])
	{
		Patient p1=new Patient();
		p1.getDetails();
		System.out.println("The BMI is: "+p1.BMI());
	}
}