import java.util.Scanner;
class Box
{
	double width,height,depth;
	double volume()
	{
		return width*height*depth;
	}
	void boxDimensions(double a,double b,double c)
	{
		width=a;
		height=b;
		depth=c;
	}
	public static void main(String args[])
	{
		Box b1=new Box();
		b1.boxDimensions(23.3,45.5,12.7);
		System.out.println("Volume is: "+b1.volume());
	}
}