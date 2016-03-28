#include <CGF/CGF.h>

using namespace cgf;

class Keybinds : public Game
{
	Keybind m_keybind;
	Keybind m_jumpKeybind;
	Keybind m_runKeybind;
	Keybind m_shootKeybind;
public:
	Keybinds() :
		Game("KeyBinding")
	{
	}

	void onStart(GameEvent *e)
	{
		// Get input manager
		InputManager *input = getInputManager();

		// Create a keybind which will call the function
		// KeyFunc1 when the '1' key is pressed.
		m_keybind = Keybind(CGF_KEY_1, bind(&Keybinds::keyFunc1, this, placeholders::_1));
		input->addKeybind(&m_keybind); // Add it to the list of keybinds

		// It is also posible to bind mouse buttons to functions
		m_shootKeybind = Keybind(CGF_MOUSE_BUTTON_LEFT, bind(&Keybinds::shoot, this, placeholders::_1));
		input->addKeybind(&m_shootKeybind);

		// Create an input context.
		// Input contexts map symbolic strings to keys.
		// For example: {{ "jump", SPACE }, {"run", LSHIFT }}
		InputContext *context = new InputContext(input);

		// Create a keybind by mapping the keyword 
		// "jump" to the SPACE key.
		m_jumpKeybind = Keybind(CGF_KEY_SPACE, bind(&Keybinds::jump, this, placeholders::_1));
		context->addKeybind("jump", &m_jumpKeybind); // Add keybind to input context

													 // Create run keybind which has no funtion mapped to it.
													 // We can stil use this keybind with context->getKeyState("run").
		m_runKeybind = Keybind(CGF_KEY_LSHIFT);
		context->addKeybind("run", &m_runKeybind);

		// Enable this context
		input->setContext(context);
	}

	void onEnd(GameEvent *e)
	{
		InputManager *input = getInputManager();
		input->removeKeybind(&m_keybind);
		input->getContext()->removeKeybind(&m_jumpKeybind);
	}

	void keyFunc1(KeyEvent *e)
	{
		switch(e->getType())
		{
			case EVENT_KEY_DOWN: LOG("1 pressed"); break;
			case EVENT_KEY_REPEAT: LOG("1 repeating"); break;
			case EVENT_KEY_UP:
				LOG("1 released");
				LOG("Button set to 2");
				m_keybind.setFunction(bind(&Keybinds::keyFunc2, this, placeholders::_1));
				m_keybind.setInputButton(CGF_KEY_2);
				break;
		}
	}

	void keyFunc2(KeyEvent *e)
	{
		switch(e->getType())
		{
			case EVENT_KEY_DOWN: LOG("2 pressed"); break;
			case EVENT_KEY_REPEAT: LOG("2 repeating"); break;
			case EVENT_KEY_UP:
				LOG("2 released");
				LOG("Button set to 1");
				m_keybind.setFunction(bind(&Keybinds::keyFunc1, this, placeholders::_1));
				m_keybind.setInputButton(CGF_KEY_1);
				break;
		}
	}

	void shoot(KeyEvent *e)
	{
		switch(e->getType())
		{
			case EVENT_KEY_DOWN: LOG("Shoot pressed"); break;
			case EVENT_KEY_REPEAT: LOG("Shoot repeating"); break; // EVENT_KEY_REPEAT is not called when pressing mouse buttons
			case EVENT_KEY_UP: LOG("Shoot released"); break;
		}
	}

	void jump(KeyEvent *e)
	{
		switch(e->getType())
		{
			case EVENT_KEY_DOWN: LOG("Jump pressed"); break;
			case EVENT_KEY_REPEAT: LOG("Jump repeating"); break;
			case EVENT_KEY_UP: LOG("Jump released"); break;
		}
	}

	void onKeyEvent(KeyEvent *e)
	{
		if(e->getKeycode() == CGF_KEY_C)
		{
			switch(e->getType())
			{
				case EVENT_KEY_DOWN: LOG("C pressed"); break;
				case EVENT_KEY_REPEAT: LOG("C repeating"); break;
				case EVENT_KEY_UP: LOG("C released"); break;
			}
		}
	}

	void onTick(TickEvent *e)
	{
		InputManager *input = getInputManager();
		if(input->getKeyState(CGF_KEY_A))
		{
			LOG("onTick(): A pressed");
		}

		if(input->getContext()->getKeyState("run"))
		{
			LOG("onTick(): Run");
		}
	}
};

/* Main entry point. This is where our program first starts executing. */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	/* To start our game we simply create our game object
	   and call run() */
	Keybinds game;
	return game.run();
}