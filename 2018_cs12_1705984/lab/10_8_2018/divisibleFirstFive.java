import java.util.*;
class divisibleFirstFive
{
	public static void main(String args[])
	{
		int c=1;
		System.out.println("First 5 numbers divisible by 2,3 and 5 are:");
		for(int i=15;;i=i+5)
		{
			if(c==6)
				break;
			
			if(i%3==0 && i%2==0){
				System.out.println(i);
				c++;
			}
			
				
		}
	}
}		