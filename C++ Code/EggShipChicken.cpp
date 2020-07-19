#include "EggShipChicken.h"


EggShipChicken::EggShipChicken(void):Chickens(300.0,0.3)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(110.0f,140.0f));

	chicken=chickenTemp;
	chicken.setOrigin(55.0f,130.0f);
	chicken.setPosition(533.5,300);
	chickentexture.loadFromFile("EggShipChicken.png");

	chicken.setTexture(&chickentexture);

	chickenX=533.5,chickenY=300;
	health=40,chickenDir=true;

}

void EggShipChicken::movement(){

	if(chickenDir){
		chicken.move(0.0,0.1), chickenY+=0.1;
		if(chickenY>=Origin+30) chickenDir=false;
	
	}
	else{
		chicken.move(0.0,-0.1), chickenY-=0.1;
		if(chickenY<=Origin) chickenDir=true;
	}
}

bool EggShipChicken :: beamStrike(float X,float Y){
	if (Y<=chickenY )
		if(X>=chickenX-55.0 && X<=chickenX+55.0){
			health-=1;
			return true;
		}
	return false;

}


EggShipChicken::~EggShipChicken(void)
{
}


EggShipChickenEgg::EggShipChickenEgg(void):Egg(533.5,300,1.3,0.5)
{

}
void EggShipChickenEgg::eggDropRight(float Y)
{
	if (eggY>=600.0 || egg_respwan )
			egg.setPosition(573.0,Y),eggX=573.0,eggY=Y,egg_respwan=false,egg.setRotation(-45);
	
		egg.move(0.5,0.5),eggY+=0.5,eggX+=0.5;
}
void EggShipChickenEgg::eggDropLeft(float Y)
{
		if (eggY>=600.0 || egg_respwan )
			egg.setPosition(493.0,Y),eggX=493.0,eggY=Y,egg_respwan=false,egg.setRotation(45);
	
		egg.move(-0.5,0.5),eggY+=0.5,eggX-=0.5;
}

EggShipChickenEgg::~EggShipChickenEgg(void)
{
}