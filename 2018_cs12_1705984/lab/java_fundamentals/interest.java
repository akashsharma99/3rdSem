
class interest
{
	public static void main(String args[])
	{
		if(args.length==2)
		{
			int age=Integer.parseInt(args[0]);
			String gend=args[1];
			if(gend.equals("F"))
			{
				if(age>=1 && age<=58)
					System.out.println("Interest rate = 8.5%");
				else if(age>=59 && age<=70)
					System.out.println("Interest rate  = 7.5%");
				else
					System.out.println("Wrong age group!");
			}
			else if(gend.equals("M"))
			{
				if(age>=1 && age<=58)
					System.out.println("Interest rate = 8%");
				else if(age>=59 && age<=70)
					System.out.println("Interest rate  = 7%");
				else
					System.out.println("Wrong age group!");
			}
			else
				System.out.println("Wrong gender!");
		}
		else
			System.out.println("Invalid number of arguments!");
	}
}