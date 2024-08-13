import java.util.*;
class employee
{
	int age;
	long phone;
	String name,address;
	double salary;
}
class officer extends employee
{
	String special;
}
class manager extends employee
{
	String dep;
}
class print
{
	public static void main(String[] args)
	{
		String temp;
		Scanner s=new Scanner(System.in);
		officer a=new officer();
		manager b=new manager();
		System.out.println("Enter the Officers details");
		System.out.println("Enter The Name:");
		a.name=s.nextLine();
		System.out.println("Enter the Age:");
		a.age=s.nextInt();
		System.out.println("Enter the adress:" );
		temp=s.nextLine();
		a.address=s.nextLine();
		System.out.println("Enter the phone number:");
		a.phone=s.nextLong();
		System.out.println("Enter the salary:");
		a.salary=s.nextDouble();
		System.out.println("Enter the Specialization:");
		temp=s.nextLine();
		a.special=s.nextLine();
		System.out.println("Enter the Managers details");
		System.out.println("Enter The Name:");
		b.name=s.nextLine();
		System.out.println("Enter the Age:");
		b.age=s.nextInt();
		System.out.println("Enter the adress:" );
		temp=s.nextLine();
		b.address=s.nextLine();
		System.out.println("Enter the phone number:");
		b.phone=s.nextLong();
		System.out.println("Enter the salary:");
		b.salary=s.nextDouble();
		System.out.println("Enter the Department:");
		temp=s.nextLine();
		b.dep=s.nextLine();	
		System.out.println("The details of officer is");
		System.out.println("Name:\t"+a.name+"\nage:\t"+a.age+"\naddress\t"+a.address+"\nphone number:\t"+a.phone+"\nsalary\t"+a.salary+"\nspecialization\t"+a.special);
		System.out.println("The details of Manager is");
		System.out.println("Name:\t"+b.name+"\nage:\t"+b.age+"\naddress\t"+b.address+"\nphone number:\t"+b.phone+"\nsalary\t"+b.salary+"\nDepartment\t"+b.dep);
		
	}
}
