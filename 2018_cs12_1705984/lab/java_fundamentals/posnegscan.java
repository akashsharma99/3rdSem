import java.util.*;
class posnegscan
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a number: ");
		int num=sc.nextInt();
		if(num==0)
			System.out.println("The number is zero!");
		else if(num<0)
			System.out.println("The number is negative!");
		else
			System.out.println("The number is positive!");
	}
}