class shiftinteger
{
	public static void main(String args[])
	{
		if(args.length==1)
			System.out.println(Integer.parseInt(args[0])<<2);
		else
			System.out.println("Invalid argument!");
	}
}