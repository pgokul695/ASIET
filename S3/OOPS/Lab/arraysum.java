import java.util.*;
class arraysum
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int a[] =new int[50];
		int sum =0;
		int r,i;
		System.out.println("Enter the number of elements in the array");
		r= s.nextInt();
		System.out.println("Enter the array");
		for(i=0;i<r;i++)
		{
			a[i]=s.nextInt();
		}
		for(i=0;i<r;i++)
		{
			sum=sum+a[i];
		}
		System.out.println("The sum is"+sum);
		s.close();
	}
}
		
		


