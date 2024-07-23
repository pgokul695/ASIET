import java.util.*;
import java.lang.*;
class sqrt
{
    public static void main(String[] args) 
    {
        Scanner s =new Scanner(System.in);
        int a,b;
        System.out.println("Enter an integer");
        a=s.nextInt();
        double sqrt= Math.sqrt(a);
        System.out.println("The Square root is"+sqrt);
        System.out.println("Enter the power");
        b=s.nextInt();
        double pow=Math.pow(a,b);
        System.out.println("The power is"+pow);
        
        s.close();

    }

    
}
