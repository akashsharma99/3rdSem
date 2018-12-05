import java.util.Scanner;
class shiftintegerscan
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a decimal number: ");
		int num=sc.nextInt();
		System.out.println(num<<2);
	}
}