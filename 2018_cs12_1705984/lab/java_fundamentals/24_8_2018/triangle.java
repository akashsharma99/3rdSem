import java.util.Scanner;
class TriangleDemo
{
	public static void main(String args[])
	{
		Triangle obj=new Triangle();
		obj.setDim();
		if(obj.isTriangle())
		{
			obj.show();
		}
		else
			System.out.println("The given values cannot form a triangle!");
	}
}
class Triangle
{
	double a,b,c;
	void setDim()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter length of three sides of the triangle: ");
		a=sc.nextDouble();
		b=sc.nextDouble();
		c=sc.nextDouble();
	}
	boolean isTriangle()
	{
		if(a+b<=c || a+c<=b || b+c<=a || a<=0 ||b<=0||c<=0)
			return false;
		else
			return true;
	}
	double findArea()
	{
		double s=(a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
	double findPerimeter()
	{
		return a+b+c;
	}
	void show()
	{
		System.out.println("Area of triangle is: "+findArea());
		System.out.println("Perimeter of the triangle is: "+findPerimeter());
	}
}