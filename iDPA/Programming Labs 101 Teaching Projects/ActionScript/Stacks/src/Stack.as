package  
{
	/**
	 * ...
	 * @author Kappy
	 */
	public class Stack 
	{
		private var first: Node;
		
		public function push(data:*):void
		{
			var oldFirst:Node = first;
			first = new Node();
			first.data = data;
			first.next = oldFirst;
		}
		
		public function pop():*
		{			
			var data:* = first.data;
			trace(data);
			first = first.next;
			return data;
		}	
	}
}