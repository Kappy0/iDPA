
public class ClassesAndMethods 
{

	public static void main(String args[])
	{
		Dog rascal = new Dog("Rascal", 0);
		rascal.setAge(1);
		
		System.out.println(rascal.getAge());
		
		System.out.println("--------------------");
		
		Cat ginger = new Cat(2);
		ginger.meow();
		
		System.out.println("--------------------");
		
		System.out.print("Enter the new meow count: ");
		ginger.setMeowCount();
		ginger.meow();
	}
}
