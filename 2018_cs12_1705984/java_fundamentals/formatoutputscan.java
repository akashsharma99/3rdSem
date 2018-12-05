import java.util.Scanner;
class formatoutputscan
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter 2 lines of string: ");
		String s1=sc.nextLine();
		String s2=sc.nextLine();
		System.out.println(s1+" Welcome "+s2);
	}
}