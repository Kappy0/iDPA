package 
{
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.text.TextField;

	/**
	 * ...
	 * @author Kappy
	 */
	[Frame(factoryClass="Preloader")]
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
			trace("Project is running fine!");
			
			var txt:TextField = new TextField();
			txt.text = "Hello world!";
			addChild(txt);
			
			for (var i:Number = 0; i <= 101; i += 2)
			{
				trace(i);
			}
		}
	}
}