class checkargs
{
	public static void main(String args[])
	{
		if(args.length==0)
			System.out.println("No values received as argument!");
		else
		{
			int lt=args.length;
			for(int i=0;i<lt;i++)
			{
				if(i==lt-1)
					System.out.println(args[i]);
				else
					System.out.print(args[i]+",");
			}
		}
	}
}