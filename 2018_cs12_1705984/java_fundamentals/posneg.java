class posneg
{
	public static void main(String args[])
	{
		if(args.length==1)
		{
			int num=Integer.parseInt(args[0]);
			if(num==0)
				System.out.println("The number is zero!");
			else if(num<0)
				System.out.println("The number is negative!");
			else
				System.out.println("The number is positive!");
		}
		else
			System.out.println("Wrong argument!");
	}
}