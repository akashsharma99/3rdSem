import java.util.Scanner;
class stringtwicescan
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a string");
		String st=sc.nextLine();
		System.out.println(st+st);
	}
}