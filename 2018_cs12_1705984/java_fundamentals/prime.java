import java.util.Scanner;
class prime
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a number: ");
		int num;
		if(!(sc.hasNextInt()))
			System.out.println("Please enter an integer number! ");
		else
		{
			num=sc.nextInt();
			switch(num)
			{
				case 0:System.out.println("0 is neither prime nor composite!");
					break;
				case 1:System.out.println("1 is neither prime nor composite!");
					break;
				default:int flag=0;
						for(int i=2;i<=num/2;i++)
						{
							if(num%i==0){flag=1;break;}
						}
						if(flag==0)
							System.out.println(num+" is a prime number");
						else
							System.out.println(num+" is not a prime number");
			}
		}
	}
}
