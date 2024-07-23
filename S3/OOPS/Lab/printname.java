import java.util.*;
class name
{
    public static void main(String[] args) 
    {
        Scanner s =new Scanner(System.in);
        int roll;
        String name,cla;
        System.out.println("Enter Your details");
        System.out.println("Name");
        name=s.nextLine();
        System.out.println("roll number");
        roll=s.nextInt();
        System.out.println("class");
        cla=s.nextLine();
        System.out.println("Your Details");
        System.out.println("Name"+name);
        System.out.println("roll number:"+roll);
        System.out.println("class"+cla);
        s.close();

    }

    
}
