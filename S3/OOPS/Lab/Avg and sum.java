import java.util.*;
class avg
{
    public static void main(String[] args) 
    {
        Scanner s =new Scanner(System.in);
        int a,b;
        System.out.println("Enter Two integers");
        a=s.nextInt();
        b=s.nextInt();
       	int sum=a+b;
        System.out.println("The sum is"+sum);
        float avg=sum/2;
        System.out.println("The average is"+avg);
        s.close();
        

    }

    
}
