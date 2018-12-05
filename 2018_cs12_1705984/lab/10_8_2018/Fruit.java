import java.util.Scanner;
class Fruit
{
	String name,taste,size;
	void eat()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter name of fruit: ");
		name=sc.nextLine();
		System.out.print("Enter taste of fruit: ");
		taste=sc.nextLine();
		System.out.print("Enter size of fruit: ");
		size=sc.nextLine();
	}
	void display()
	{
		System.out.println("name: "+name);
		System.out.println("taste: "+taste);
		System.out.println("size: "+size);
	}
	public static void main(String args[])
	{
		Fruit obj=new Fruit();
		obj.eat();
		obj.display();
	}
}