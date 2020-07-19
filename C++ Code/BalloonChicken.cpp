#include "BalloonChicken.h"


BalloonChicken::BalloonChicken(void):Chickens(0.2)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(91.0,150.0));

	chicken=chickenTemp;
	chicken.setOrigin(44.5f,110.0f);
	chicken.setPosition(1067.0,600.0);
	chickentexture.loadFromFile("BalloonChicken.png");

	chicken.setTexture(&chickentexture);

	chickenX=1067.0,chickenY=600.0;
	health=5;
}

void BalloonChicken :: movement()
{

		chicken.move(-0.24,-0.12),chickenX-=0.24,chickenY-=0.12;

}

bool BalloonChicken :: beamStrike(float X,float Y){
	if (Y<=chickenY )
		if(X>=chickenX-44.5 && X<=chickenX+44.5){
			health--;
			return true;
		}
	return false;

}

BalloonChicken::~BalloonChicken(void)
{
}
