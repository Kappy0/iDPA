package 
{
	import flash.display.Sprite;
	import flash.display.Shape;
	import flash.display.DisplayObjectContainer;
	import flash.events.Event;
	import flash.text.TextField;
	import flash.text.TextFieldType;
	import flash.events.MouseEvent;
	import flash.display.SimpleButton;
	
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
			
			var dataLabel:TextField = new TextField();
			dataLabel.type = TextFieldType.INPUT;
			dataLabel.border = true;
			dataLabel.height = 16;
			addChild(dataLabel);
			
			pushButton();
			popButton();
			
			var myStack:Stack = new Stack();
			
			myStack.push("item 1");
			trace(myStack.pop());
			
			//Push Button
			function pushButton():void
			{
				var upTextField:TextField = new TextField();
				upTextField.name = "textField";
				upTextField.y = 50;
				upTextField.x = 35;
				upTextField.mouseEnabled = false;
				
				var overTextField:TextField = new TextField();
				overTextField.name = "textField";
				overTextField.y = 50;
				overTextField.x = 35;
				overTextField.mouseEnabled = false;
				
				var downTextField:TextField = new TextField();
				downTextField.name = "textField";
				downTextField.y = 50;
				downTextField.x = 35;
				downTextField.mouseEnabled = false;
				
				//{ region up
				var upRectangleShape:Shape = new Shape();
				upRectangleShape.graphics.beginFill(0xFF0000);
				upRectangleShape.graphics.drawRect(0, 50, 100, 25);
				upRectangleShape.graphics.endFill();

				var pushUp:Sprite = new Sprite();
				pushUp.addChild(upRectangleShape);
				pushUp.addChild(upTextField);
				//} endregion
				
				//{ region over
				var overRectangleShape:Shape = new Shape();
				overRectangleShape.graphics.beginFill(0xFFCC00);
				overRectangleShape.graphics.drawRect(0, 50, 100, 25);
				overRectangleShape.graphics.endFill();

				var pushOver:Sprite = new Sprite();
				 pushOver.addChild(overRectangleShape);
				 pushOver.addChild(overTextField);
				//} endregion
				
				//{ region down
				var downRectangleShape:Shape = new Shape();
				downRectangleShape.graphics.beginFill(0x000000);
				downRectangleShape.graphics.drawRect(0, 50, 100, 25);
				downRectangleShape.graphics.endFill();

				var pushDown:Sprite = new Sprite();
				pushDown.addChild(downRectangleShape);
				pushDown.addChild(downTextField);
				//} endregion

				var pushButton:SimpleButton = new SimpleButton();
				pushButton.upState = pushUp;
				pushButton.overState = pushOver;
				pushButton.downState = pushDown;
				pushButton.useHandCursor = true;
				pushButton.hitTestState = pushUp;
				
				addChild(pushButton);
				
				// local simpleButtonSprite object
				var sbs:DisplayObjectContainer = DisplayObjectContainer(pushButton.upState);
				//local textField object
				var tf:TextField = TextField(sbs.getChildByName("textField"));  
				tf.text = "Push";
				
								// local simpleButtonSprite object
				var dsbs:DisplayObjectContainer = DisplayObjectContainer(pushButton.downState);
				//local textField object
				var dtf:TextField = TextField(dsbs.getChildByName("textField"));  
				dtf.text = "Push";
				
				var osbs:DisplayObjectContainer = DisplayObjectContainer(pushButton.overState);
				//local textField object
				var otf:TextField = TextField(osbs.getChildByName("textField"));  
				otf.text = "Push";
				
				pushButton.addEventListener(MouseEvent.CLICK, pushItem);
				function pushItem(e:MouseEvent):void
				{
					myStack.push(dataLabel.text);
					dataLabel.text = "";
				}
			}	
			
			//Pop Button
			function popButton():void
			{
				var upTextField:TextField = new TextField();
				upTextField.name = "textField";
				upTextField.y = 50;
				upTextField.x = 135;
				upTextField.mouseEnabled = false;
				
				var overTextField:TextField = new TextField();
				overTextField.name = "textField";
				overTextField.y = 50;
				overTextField.x = 135;
				overTextField.mouseEnabled = false;
				
				var downTextField:TextField = new TextField();
				downTextField.name = "textField";
				downTextField.y = 50;
				downTextField.x = 135;
				downTextField.mouseEnabled = false;
				
				//{ region up
				var upRectangleShape:Shape = new Shape();
				upRectangleShape.graphics.beginFill(0xFFAB00);
				upRectangleShape.graphics.drawRect(100, 50, 100, 25);
				upRectangleShape.graphics.endFill();

				var popUp:Sprite = new Sprite();
				popUp.addChild(upRectangleShape);
				popUp.addChild(upTextField);
				//} endregion
				
				//{ region over
				var overRectangleShape:Shape = new Shape();
				overRectangleShape.graphics.beginFill(0xFFCC00);
				overRectangleShape.graphics.drawRect(100, 50, 100, 25);
				overRectangleShape.graphics.endFill();

				var popOver:Sprite = new Sprite();
				 popOver.addChild(overRectangleShape);
				 popOver.addChild(overTextField);
				//} endregion
				
				//{ region down
				var downRectangleShape:Shape = new Shape();
				downRectangleShape.graphics.beginFill(0x000000);
				downRectangleShape.graphics.drawRect(100, 50, 100, 25);
				downRectangleShape.graphics.endFill();

				var popDown:Sprite = new Sprite();
				popDown.addChild(downRectangleShape);
				popDown.addChild(downTextField);
				//} endregion

				var popButton:SimpleButton = new SimpleButton();
				popButton.upState = popUp;
				popButton.overState = popOver;
				popButton.downState = popDown;
				popButton.useHandCursor = true;
				popButton.hitTestState = popUp;
				
				addChild(popButton);
				
				// local simpleButtonSprite object
				var sbs:DisplayObjectContainer = DisplayObjectContainer(popButton.upState);
				//local textField object
				var tf:TextField = TextField(sbs.getChildByName("textField"));  
				tf.text = "Pop";
				
								// local simpleButtonSprite object
				var dsbs:DisplayObjectContainer = DisplayObjectContainer(popButton.downState);
				//local textField object
				var dtf:TextField = TextField(dsbs.getChildByName("textField"));  
				dtf.text = "Pop";
				
				var osbs:DisplayObjectContainer = DisplayObjectContainer(popButton.overState);
				//local textField object
				var otf:TextField = TextField(osbs.getChildByName("textField"));  
				otf.text = "Pop";
				
				popButton.addEventListener(MouseEvent.CLICK, popItem);
				function popItem(e:MouseEvent):*
				{
					dataLabel.text = myStack.pop();
				}
			}	
		}	
	}	
}