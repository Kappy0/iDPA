public class Dog 
	{
		private String name;
		private int age;
		
		public Dog(String Name, int Age) 
		{
			name = Name;
			age = Age;
		}
		
		public void setAge(int newAge)
		{
			age = newAge;
		}
		
		public int getAge()
		{
			return age;
		}
		
		public String getName()
		{
			return name;
		}
	}