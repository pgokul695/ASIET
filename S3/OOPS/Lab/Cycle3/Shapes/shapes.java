import java.util.*;
abstract class Shape
{
	void numberOfSides()
	{
	}
}
class Rectangle extends Shape
{
	void numberOfSides()
	{
		System.out.println("The number sides of a Rectangle is 4");
	}	
}
class Triangle extends Shape
{
	void numberOfSides()
	{
		System.out.println("The number of sides of a Trinagle is 3");
	}	
}
class Hexagon extends Shape
{
	void numberOfSides()
	{
		System.out.println("The number of sides of Hecagon is 6");
	}	
}
class main
{
	public static void main(String[] args)
	{
		Rectangle R=new Rectangle();
		Triangle T=new Triangle();
		Hexagon H=new Hexagon();
		R.numberOfSides();
		T.numberOfSides();
		H.numberOfSides();
	}
}
