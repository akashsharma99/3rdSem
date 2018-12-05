import java.util.*;
class addsub
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		while(true)
		{
			System.out.print("1.Add\n2.Sub\nSelect an option: ");
			int ch=sc.nextInt();
			System.out.print("Enter 1st number: ");
			int a=sc.nextInt();
			System.out.print("Enter 2nd number: ");
			int b=sc.nextInt();
			switch(ch)
			{
				case 1:System.out.println(a+" + "+b+" = "+(a+b));
				break;
				case 2:System.out.println(a+" - "+b+" = "+(a-b));
				break;
				default:System.out.println("Wrong choice!");
			}
			System.out.print("Do you want to continue? y or n: ");
			char c=sc.next().charAt(0);
			if(c=='n'||c=='N')
			{System.out.println("Thank you! bye.");break;}
		}
	}
}