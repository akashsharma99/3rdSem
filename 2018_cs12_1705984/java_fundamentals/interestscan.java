import java.util.Scanner;
class interestscan
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter your gender, M or F: ");
		String gend=sc.next();
		System.out.print("Enter your age: ");
		int age=sc.nextInt();
		if(gend.equalsIgnoreCase("f"))
		{
			if(age>=1 && age<=58)
				System.out.println("Interest rate = 8.5%");
			else if(age>=59 && age<=70)
				System.out.println("Interest rate  = 7.5%");
			else
				System.out.println("Wrong age group!");
		}
		else if(gend.equalsIgnoreCase("m"))
		{
			if(age>=1 && age<=58)
				System.out.println("Interest rate = 8%");
			else if(age>=59 && age<=70)
				System.out.println("Interest rate  = 7%");
			else
				System.out.println("Wrong age group!");
		}
		else
			System.out.println("Wrong gender!");
	}
}