package 
{
	import flash.display.SimpleButton;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.text.TextField;
	import flash.text.TextFieldType;
	
	/**
	 * ...
	 * @author Kappy
	 */
	public class Main extends Sprite 
	{
		
		public function Main():void 
		{
			if (stage) init();
			else addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event = null):void 
		{
			removeEventListener(Event.ADDED_TO_STAGE, init);
			// entry point
			var a:Node = new Node();
			var b:Node = new Node();
			var c:Node = new Node();
			
			a.data = "Node A";
			a.next = b;
			b.data = "Node B";
			b.next = c;
			c.data = "Node C";
			c.next = null;
			
			var dataLabel:TextField = new TextField();
			dataLabel.type = TextFieldType.DYNAMIC;
			addChild(dataLabel);
			
			var nextButton:SimpleButton = new SimpleButton();
			nextButton.y = 100;
			drawButton();
			
			var curNode:Node = a;
			
			nextButton.addEventListener(MouseEvent.CLICK, seeNext);
			
			function seeNext(e:MouseEvent):void
			{
				if (curNode != null)
				{
					dataLabel.text = curNode.data;
					curNode = curNode.next;
				}
				else
				{
					dataLabel.text = "Reached the end of the list.";
				}
			}
			
			function drawButton():void
			{
				var down:Sprite = new Sprite();
				down.graphics.lineStyle(1, 0x000000);
				down.graphics.beginFill(0xFFCC00);
				down.graphics.drawRect(10, 10, 100, 30);
				
				var up:Sprite = new Sprite();
				up.graphics.lineStyle(1, 0x000000);
				up.graphics.beginFill(0x0099FF);
				up.graphics.drawRect(10, 10, 100, 30);
						
				var over:Sprite = new Sprite();
				over.graphics.lineStyle(1, 0x000000);
				over.graphics.beginFill(0x9966FF);
				over.graphics.drawRect(10, 10, 100, 30);
						
				nextButton.upState = up;
				nextButton.overState = over;
				nextButton.downState = down;
				nextButton.useHandCursor = true;
				nextButton.hitTestState = up;
						
				addChild(nextButton);
			}
		}
		
	}
	
}