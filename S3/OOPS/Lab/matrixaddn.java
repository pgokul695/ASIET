import java.util.*;
class matrixaddn
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int a[][] =new int[50][50];
		int b[][] =new int[50][50];
		int sum[][] =new int[50][50];
		int r,c,i,j;
		System.out.println("Enter the number of Columns of the matrix");
		c= s.nextInt();
		System.out.println("Enter the number of Rows of the matrix");
		r= s.nextInt();
		System.out.println("Enter the First matrix");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				a[i][j]=s.nextInt();
			}
		}
		System.out.println("Enter the Second matrix");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				b[i][j]=s.nextInt();
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				sum[i][j]=a[i][j]+b[i][j];
			}
		}
		System.out.println("The sum is");
		System.out.println("");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				System.out.print("\t"+sum[i][j]);
			}
			System.out.println("");
		}
		s.close();
	}
}
		
		


