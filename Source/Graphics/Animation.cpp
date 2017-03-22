//       ____  ____     ____                        _____             _            
// __  _|___ \|  _ \   / ___| __ _ _ __ ___   ___  | ____|_ __   __ _(_)_ __   ___ 
// \ \/ / __) | | | | | |  _ / _  |  _   _ \ / _ \ |  _| |  _ \ / _  | |  _ \ / _ \
//  >  < / __/| |_| | | |_| | (_| | | | | | |  __/ | |___| | | | (_| | | | | |  __/
// /_/\_\_____|____/   \____|\__ _|_| |_| |_|\___| |_____|_| |_|\__, |_|_| |_|\___|
//                                                              |___/     
//				Originally written by Marcus Loo Vergara (aka. Bitsauce)
//									2011-2015 (C)

#include <Sauce/Common.h>
#include <Sauce/graphics.h>

BEGIN_SAUCE_NAMESPACE

SpriteAnimation::SpriteAnimation(const int nRows, const int nColumns)
{
	// Create texture regions
	for(int y = 0; y < nRows; y++)
	{
		for(int x = 0; x < nColumns; x++)
		{
			m_textureRegions.push_back(
				TextureRegion(
					Vector2F(float(x)/nColumns, float(y)/nRows),
					Vector2F(float(x+1)/nColumns, float(y+1)/nRows))
				);
		}
	}
}

SpriteAnimation::~SpriteAnimation()
{
	m_textureRegions.clear();
}

TextureRegion SpriteAnimation::getKeyFrame(uint frameIndex)
{
	return frameIndex < m_textureRegions.size() ? m_textureRegions[frameIndex] : TextureRegion();
}

END_SAUCE_NAMESPACE