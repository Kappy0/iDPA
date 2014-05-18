import java.util.Scanner;


public class Cat 
{
	private int count;
	Scanner scan = new Scanner(System.in);
	
	public Cat(int Count) 
	{
		count = Count;
	}
	
	public void setMeowCount()
	{
		count = scan.nextInt();
	}
	
	public int getMeowCount()
	{
		return count;
	}
	
	public void meow()
	{
		for(int i = 0; i < count; i++)
		{
			System.out.println("Meow!");
		}
	}
}
