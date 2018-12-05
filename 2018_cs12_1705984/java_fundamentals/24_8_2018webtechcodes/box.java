import java.util.Scanner;
class box
{
	int length,width,height;
	box(int lt,int wd,int ht)
	{
		length=lt;
		width=wd;
		height=ht;
	}
	void volume()
	{
		
		System.out.println("The volume is: "+length*width*height);
	}
}
class demo
{
	public static void main(String args[])
	{
		int l,w,h;
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter length: ");
		l=sc.nextInt();
		System.out.print("Enter width: ");
		w=sc.nextInt();
		System.out.print("Enter height: ");
		h=sc.nextInt();
		box obj=new box(l,w,h);
		obj.volume();
	}
}