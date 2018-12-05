import java.util.Scanner;
class SixSeven
{
	int sum(int a[],int size)
	{
		int m=-1,n=-1,sum=0,x;
		for(int i=0;i<size;i++)
		{
			if(a[i]==6)
			{
				m=i;
				x=i+1;
				while(x<size)
				{	
					if(a[x]==7)
					{
						n=x;
						break;
					}
					x++;
				}				
			}
			if(n!=-1)break;
		}
		if(m==-1 || n==-1 || m==n)
			return -1;
		x=m+1;
		while(x<n){
			sum=sum+a[x];x++;
		}
		return sum;
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("enter size of array: ");
		int n=sc.nextInt();
		int a[]=new int[n];
		System.out.println("enter the array elements: ");
		for(int i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
		}
		SixSeven obj=new SixSeven();
		System.out.println("The sum between 6 to 7 is: "+obj.sum(a,n));
	}
}