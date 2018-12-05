class animal
{
	void eat()
	{
		System.out.println("This animal like to eat humans! ^_^");
	}
	void sleep()
	{
		System.out.println("This animal sleeps 10 hours a day!");
	}
	public static void main(String args[])
	{
		animal devil=new animal();
		devil.eat();
		devil.sleep();
	}
}