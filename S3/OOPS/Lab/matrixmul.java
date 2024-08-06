import java.util.*;
class matrixpro
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int a[][] =new int[50][50];
		int b[][] =new int[50][50];
		int sum[][] =new int[50][50];
		int r,c,i,j,c2,r2;
		System.out.println("Enter the number of Columns of the First matrix");
		c= s.nextInt();
		System.out.println("Enter the number of Rows of the First matrix");
		r= s.nextInt();
		System.out.println("Enter the number of Columns of the Second matrix");
		c2= s.nextInt();
		System.out.println("Enter the number of Rows of the Second matrix");
		r2= s.nextInt();
		if (r!=c2)
		{	System.out.println("The Matrices cant be Multiplied");
			System.exit(0);
		}
		System.out.println("Enter the First matrix");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				a[i][j]=s.nextInt();
			}
		}
		System.out.println("Enter the Second matrix");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				b[i][j]=s.nextInt();
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c2;j++)
			{
				sum[i][j]=0;
				for(int k=0;k<c2;k++)
				{
					sum[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		System.out.println("The product is");
		System.out.println("");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c2;j++)
			{
				System.out.print("\t"+sum[i][j]);
			}
			System.out.println("");
		}
		s.close();
	}
}
		
