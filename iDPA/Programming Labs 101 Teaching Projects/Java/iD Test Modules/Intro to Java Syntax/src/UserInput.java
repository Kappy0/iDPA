import java.util.Scanner;

public class UserInput 
{
	public static void main(String args[])
	{
		//Create input device
		Scanner scan = new Scanner(System.in);
		
		//Create input parameters
		int n;
		System.out.print("Enter n: ");
		n = scan.nextInt();
		
		double d;
		System.out.print("Enter d: ");
		d = scan.nextDouble();
		
		boolean b;
		System.out.print("Enter b: ");
		b = scan.nextBoolean();
		
		String s;
		System.out.print("Enter s: ");
		s = scan.next();
		
		String line = scan.nextLine();
		
		//Print them to the screen once all inputs are in
		System.out.println("The value of n is: " + n);
		System.out.println("The value of d is: " + d);
		System.out.println("The value of b is: " + b);
		System.out.println("The value of line is: " + line);
		System.out.println("The value of s is: " + s);
	}
}
