
import java.util.Scanner;

public class Arrays 
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		
		int[] userArray;
		int[] intArray = new int[10];
		char[] charArray = { 'H', 'e', 'l', 'l', 'o', '!' };
		System.out.println("Enter the size of the int array: ");
		userArray = new int[scan.nextInt()];
		userArray[0] = scan.nextInt();
		
		
		System.out.println(charArray.length);
		
		for(int i = 0; i < userArray.length; i++)
		{
			System.out.print(userArray[i] + " ");
		}
	}
}
