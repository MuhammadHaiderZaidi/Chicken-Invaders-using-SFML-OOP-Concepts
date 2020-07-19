#include "FrozenChicken.h"
#include "Player.h"

FrozenChicken::FrozenChicken(void)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(80.0,90.0));

	chicken=chickenTemp;
	chicken.setOrigin(40.5f,45.0f);
	chickentexture.loadFromFile("FrozenChick.png");

	chicken.setTexture(&chickentexture);

	chickenY=650.0,rotation=360.0;
}
void FrozenChicken::movement()
{
	if(chickenY>=650.0){
		chickenX=(rand() % (1070)),chickenY=-50.0;
		chicken.setPosition(chickenX,chickenY);
	}
	chicken.move(-0.7,0.9),chickenX-=0.7,chickenY+=0.9;
	chicken.setRotation(rotation--);
	if(rotation<=0.0) rotation=360.0;
}

bool FrozenChicken :: Collision(float X,float Y){
	if (Y<= chickenY && (Y+100.0)>= chickenY){
		if((X-40)<= chickenX && (X+40)>= chickenX){
			chickenX=(rand() % (1070)),chickenY=-50.0;
			chicken.setPosition(chickenX,chickenY);
			return true;
		}
		else return false;
	}
	else return false;
}

FrozenChicken::~FrozenChicken(void)
{
}
