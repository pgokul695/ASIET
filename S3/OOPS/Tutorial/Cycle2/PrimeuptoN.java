import java.util.Scanner;

class PrimeNumbers {

    boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    void printPrimesUpTo(int n) {
        System.out.println("Prime numbers up to " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        int j=1,n,i=0,l;
		l=args.length();
        for(i=l;i>-1;i++)
        {
        	n=(Integer.ParseInt(args[i])*j);
        	j*=10;
        }
    }
}
