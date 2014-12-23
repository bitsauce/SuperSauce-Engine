#include "config.h"
#include "graphics/graphicsContext.h"
#include "graphics/blendState.h"
#include "graphics/animation.h"
#include "graphics/spritebatch.h"
#include "graphics/font.h"
#include "graphics/rendertarget.h"
#include "graphics/pixmap.h"
#include "graphics/shader.h"
#include "graphics/shape.h"
#include "graphics/sprite.h"
#include "graphics/texture.h"
#include "graphics/textureatlas.h"
#include "graphics/textureregion.h"
#include "graphics/vertex.h"
#include "graphics/vertexbuffer.h"
#include "graphics/viewport.h"

#ifndef X2D_GRAPHICS_H
#define X2D_GRAPHICS_H

/*********************************************************************
**	Graphics class [static]											**
**********************************************************************/

namespace xd
{

XDAPI extern uint QUAD_INDICES[6];
XDAPI extern Vector4 QUAD_VERTICES[4];
XDAPI extern Vector2 QUAD_TEXCOORD[4];

class XDAPI Graphics
{
	friend class XEngine;
	friend class XWindow;

public:

	enum Feature
	{
		VertexBufferObjects,
		FrameBufferObjects
	};

	// Refresh rate
	static void setRefreshRate(const int hz);
	static int getRefreshRate();
	
	// Vsync
	static void enableVsync();
	static void disableVsync();

	// Wireframe
	static void enableWireframe();
	static void disableWireframe();

	// Time step & fps
	static float getTimeStep();
	static float getFPS();

	// Swap buffers
	static void swapBuffers();

	// Rendering
	static bool isSupported(Feature feature);

protected:
	// Init
	static void init();

	// Rendering context
	static void createContext();
	static void destroyContext();

	static HGLRC s_context;

	static float s_framesPerSecond;
	static int s_refreshRate;
	static float s_timeStep;

	static GraphicsContext s_graphicsContext;
};

}

#endif // X2D_GRAPHICS_H