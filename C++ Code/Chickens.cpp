#include "Chickens.h"




Chickens :: Chickens(float X,float damage):Origin(X),damage(damage)
{
	numOfChick++;
}

Chickens :: Chickens(float damage):Origin(0),damage(damage)
{
	numOfChick++;
}

int Chickens:: numOfChick=0;


Chickens::~Chickens(void)
{
}


Egg :: Egg(float X,float Y,float size,float speed):eggX(X),eggY(Y),speed(speed){
	
	sf:: RectangleShape eggTemp( sf::Vector2f(18.0*size,25.0f*size));
	egg=eggTemp;
	egg.setOrigin(9.0,12.5);
	egg.setPosition(X,Y);
	eggtexture.loadFromFile("egg.png");
	egg.setTexture(&eggtexture);
}
void Egg:: eggDrop(float X, float Y){
	if (eggY>=600.0 || egg_respwan )
		egg.setPosition(X,Y),eggX=X,eggY=Y,egg_respwan=false;
	
	egg.move(0.0,speed),eggY+=speed;
}
 
Egg ::~Egg()
{
}
