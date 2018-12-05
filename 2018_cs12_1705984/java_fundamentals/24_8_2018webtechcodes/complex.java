import java.util.*;
class complex
{
	double real,imag;
	complex()
	{
		real=0.0;
		imag=0.0;
	}
	complex(double r,double i)
	{
		real=r;
		imag=i;
	}
	complex add(complex p)
	{
		complex obj=new complex();
		obj.real=real+p.real;
		obj.imag=imag+p.imag;
		return obj;
	}
	complex subtract(complex p)
	{
		complex obj=new complex();
		obj.real=real-p.real;
		obj.imag=imag-p.imag;
		return obj;
	}
	void show()
	{
		if(imag<0)
			System.out.println(real+"-i"+(imag*-1));
		else
			System.out.println(real+"+i"+imag);
	}
}
class complexDemo
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		double r,i;
		System.out.println("Enter real and imaginary part of 1st complex number: ");
		r=sc.nextDouble();
		i=sc.nextDouble();
		complex num1=new complex(r,i);
		System.out.println("Enter real and imaginary part of 2nd complex number: ");
		r=sc.nextDouble();
		i=sc.nextDouble();
		complex num2=new complex(r,i);
		
		System.out.print("Sum of the numbers is: ");
		num1.add(num2).show();
		
		System.out.print("Difference of the numbers is: ");
		num1.subtract(num2).show();
	}
}