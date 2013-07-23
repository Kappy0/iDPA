import java.util.Scanner;

public class ControlStatements 
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int y = 1;
		int z = 0;
		int k = 0;
		int[] forEachArray = {1, 2, 3, 4, 5};
		
		boolean condition;
		System.out.print("Is condition true or false? ");
		condition = scan.nextBoolean();
		
		int x;
		System.out.print("Enter x: ");
		x = scan.nextInt();

		//If-Else statements
		if(condition)
		{
			System.out.println("Condition is: " + condition);
		}
		else
		{
			System.out.println("Condition is: " + condition);
		}
	
		//Nested if-else
		if(x <= 5)
		{
			System.out.println("x is less than or equal to 5");
		}
		else if (x > 5 && x <= 10)
		{
			System.out.println("x is greater than 5 and less than or equal to 10");
		}
		else 
		{
			System.out.println("x satisfies neither of the two preceding statements");
		}
		
		//For loop
		for(int i = 0; i <= 10; i++)
		{
			System.out.print(i + " ");
		}
		
		System.out.println();
		
		//While loop
		while(k <= 5)
		{
			System.out.print(k + " ");
			k++;
		}
		
		System.out.println();
		
		//Do-While loop
		do
		{
			y++;
		} 
		while (y <= 7);
		
		System.out.println("y is: " + y);
		
		//For each loop
		for(int j : forEachArray)
		{
			z += j;
		}

		System.out.println("z is: " + z);
	}
}
