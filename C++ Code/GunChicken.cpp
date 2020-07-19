#include "GunChicken.h"

GunChicken::GunChicken(void):Chickens(266.75,0.2)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(123.0f,200.0f));

	chicken=chickenTemp;
	chicken.setOrigin(61.5f,190.0f);
	chicken.setPosition(266.75,200.0);
	chickentexture.loadFromFile("GunChicken.png");

	chicken.setTexture(&chickentexture);

	chickenX=266.75,chickenY=200.0;
	health=40,chickenDir=true,eggDropCount=0;
}

void GunChicken::movement(){

	
	
	if(eggDropCount>=1000){
		if(chickenDir){
			chicken.move(0.6,0.0), chickenX+=0.6 , chicken.setRotation(-10);
			if(chickenX>=Origin+533.4) chickenDir=false,chicken.setRotation(0),eggDropCount=0;
		
		}
		else{
			chicken.move(-0.6,0.0), chickenX-=0.6 ,chicken.setRotation(10);
			if(chickenX<=Origin) chickenDir=true,chicken.setRotation(0),eggDropCount=0;
		}
	}
	eggDropCount++;
	
}

bool GunChicken :: beamStrike(float X,float Y){
	if (Y<=chickenY )
		if(X>=chickenX-61.5 && X<=chickenX+61.5){
			health-=1;
			return true;
		}
	return false;

}


GunChicken::~GunChicken(void)
{
}
