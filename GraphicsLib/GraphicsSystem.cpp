/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "GraphicsSystem.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>



GraphicsSystem::GraphicsSystem()
{
	mScale = 1.0;
	mBuffer.mBitmap = al_get_backbuffer(mDisplay);
}

GraphicsSystem::~GraphicsSystem()
{
	//cleanGraphicsSystem();
}

int GraphicsSystem::initGraphicsSystem()
{
	//initalize variables
	if (!al_init())
	{
		cout << "error initting Allegro\n";
		return 1;
	}
	if (!al_init_image_addon())
	{
		cout << "error - Image Add-on not initted\n";
		return 1;
	}
	if (!al_init_font_addon())
	{
		cout << "error - Font Add-on not initted\n";
		return 1;
	}
	if (!al_init_ttf_addon())
	{
		cout << "error - TTF Add-on not initted\n";
		return 1;
	}
	if (!al_init_primitives_addon())
	{
		cout << "error - primitives Add-on not initted\n";
		return 1;
	}
	if (!al_install_audio())
	{
		cout << "error - Audio Add-on not initted\n";
		return 1;
	}
	if (!al_init_acodec_addon())
	{
		cout << "error - Audio Codec Add-on not initted\n";
		return 1;
	}
	if (!al_reserve_samples(1))
	{
		cout << "error - samples not reserved\n";
		return 1;
	}
	
}

void GraphicsSystem::cleanGraphicsSystem()
{
	//clean the pointers
	al_destroy_display(mDisplay);
}

void GraphicsSystem::setHeight(int myHeight)
{
	mHeight = myHeight;
}

void GraphicsSystem::setWidth(int myWidth)
{
	mWidth = myWidth;
}

int GraphicsSystem::getHeight()
{
	return mHeight;
}

int GraphicsSystem::getWidth()
{
	return mWidth;
}

void GraphicsSystem::display(int height, int width)
{
	//breaks
	mDisplay = al_create_display(width, height);
	//assert(display);
}

void GraphicsSystem::drawSprite(int locationX, int locationY, GraphicsBuffer& sprite, float widthScale, float heightScale)
{
	//draw to current backbuffer
	int width = sprite.getWidth();
	int height = sprite.getHeight(); //i need to set these to something
	//messed the the sY and sX values to make it more in the center
	al_draw_scaled_bitmap(sprite.mBitmap, 150, 150, width, height, locationX, locationY, width*widthScale, height*heightScale, 0);
	
}



void GraphicsSystem::drawSprite(GraphicsBuffer& myBuffer, int locationX, int locationY, GraphicsBuffer& mySprite, float scale)
{
	ALLEGRO_BITMAP* originalTarget = al_get_target_bitmap();
	al_set_target_bitmap(myBuffer.mBitmap);
	al_draw_scaled_bitmap(mySprite.mBitmap, 0, 0, mySprite.getWidth(), mySprite.getHeight(), locationX, locationY, mySprite.getWidth() * scale, mySprite.getHeight() * scale, 0);
	al_set_target_bitmap(originalTarget);

}

void GraphicsSystem::drawSprite(int locationX, int locationY, GraphicsBuffer & mySprite)
{
	al_draw_bitmap(mySprite.mBitmap, locationX, locationY, 0);
}

void GraphicsSystem::writeText(int locationX, int locationY, Font& myFont, Color& myColor, string myMessage)
{
	al_draw_text(myFont.mFont, myColor.mColor, locationX, locationY, ALLEGRO_ALIGN_CENTER, myMessage.c_str());
}

void GraphicsSystem::writeText(GraphicsBuffer& myBuffer, int locationX, int locationY, Font& myFont, Color& myColor, string myMessage)
{
 	al_draw_text(myFont.getFont(), al_map_rgb(0, 0, 0), locationX, locationY, ALLEGRO_ALIGN_CENTER, myMessage.c_str());
	
}

void GraphicsSystem::saveBuffer(string filename, GraphicsBuffer& myBuffer)
{
	al_save_bitmap(filename.c_str(), al_get_target_bitmap());
	
}

void GraphicsSystem::drawActualSprite(Sprite& sprite, int locationX, int locationY)
{
	al_draw_bitmap_region(sprite.getGraphicsBuffer()->mBitmap, sprite.getLocationOfSpriteX(), sprite.getLocationOfSpriteY(), sprite.getWidthOfSprite(), sprite.getHeightOfSprite(), locationX, locationY, 0);
}

void GraphicsSystem::drawColorBuffer(int r, int g, int b)
{
	al_clear_to_color(al_map_rgb(r, g, b));
}

void GraphicsSystem::flipDisplay()
{
	al_flip_display();
}

GraphicsBuffer GraphicsSystem::getBackBuffer()
{
	return mBuffer;
}

void GraphicsSystem::wait()
{
	al_rest(SLEEP_TIME);
}
