#include <CGF/CGF.h>

using namespace cgf;

class TextureAtlasGame : public Game
{
	TextureAtlas *textureAtlas;
public:
	TextureAtlasGame() :
		Game("TextureAtlas")
	{
	}

	void onStart(GameEvent*)
	{
		// Here we load Image0, Image1, ..., until Image[i] is not a file.
		vector<Pixmap> pixmaps;
		int i = 0;
		while(util::fileExists("Image" + util::intToStr(i) + ".png"))
		{
			pixmaps.push_back(Pixmap("Image" + util::intToStr(i) + ".png"));
			i++;
		}

		// Create a texture atlas using these images
		textureAtlas = new TextureAtlas(pixmaps);

		// Save the atlas to Atlas.png (just to show how the altas it looks like)
		textureAtlas->getTexture()->exportToFile("Atlas.png");
	}

	void onEnd(GameEvent*)
	{
	}

	void onTick(TickEvent*)
	{
	}

	void onDraw(DrawEvent *e)
	{
		// Here we draw Image0 using the texture atlas
		GraphicsContext *graphicsContext = e->getGraphicsContext();
		graphicsContext->setTexture(textureAtlas->getTexture());
		graphicsContext->drawRectangle(100, 100, 190, 177, Color(255), textureAtlas->get(0));
		graphicsContext->setTexture(0);
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	TextureAtlasGame game;
	return game.run();
}