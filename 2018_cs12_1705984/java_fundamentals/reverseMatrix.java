class reverseMatrix
{
	public static void main(String args[])
	{
		int a[][]=new int[2][2];
		int c=0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
				a[i][j]=Integer.parseInt(args[c++]);
		}
		System.out.println("Original matrix is:");
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++){
				System.out.print(a[i][j]+"  ");
			}
			System.out.println();
		}
		//reversing matrix;
		int t;
		for(int i=0,m=1;i<2/2;i++,m--)
		{
	f		for(int j=0,n=1;j<2;j++,n--){
				t=a[m][n];
				//System.out.println(m+"_"+n+" with "+i+"_"+j);
				a[m][n]=a[i][j];
				a[i][j]=t;
			}
		}
		System.out.println("New reversed array is: ");
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++){
				System.out.print(a[i][j]+"  ");
			}
			System.out.println();
		}

	}
}
