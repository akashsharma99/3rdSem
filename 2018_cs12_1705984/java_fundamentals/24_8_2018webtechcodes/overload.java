class overloading
{
	public static void main(String args[])
	{
		overloading obj=new overloading();
		obj.subtract();
		obj.subtract(2);
		obj.subtract(5,3);
	}
	void subtract()
	{
		System.out.println("No numbers given to subtract!");
	}
	void subtract(int x)
	{
		System.out.println("We need two numbers to perform subtraction!");
	}
	void subtract(int a,int b)
	{
		System.out.println(a+" - "+b+" = "+(a-b));
	}
}