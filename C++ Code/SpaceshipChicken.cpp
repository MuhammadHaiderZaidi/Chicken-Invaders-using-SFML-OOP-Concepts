#include "SpaceshipChicken.h"

SpaceshipChicken::SpaceshipChicken(float X,float Y):Chickens(Y,0.4)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(100.0f,95.0f));

	chicken=chickenTemp;
	chicken.setOrigin(50.0f,80.0f);
	chicken.setPosition(X,Y);
	chickentexture.loadFromFile("SpaceshipChicken.png");

	chicken.setTexture(&chickentexture);

	chickenX=X,chickenY=Y;
	health=20,chickenDir=true;

}

void SpaceshipChicken::movement(){

	if(chickenDir){
		chicken.move(0.0,0.1), chickenY+=0.1;
		if(chickenY>=Origin+30) chickenDir=false;
	
	}
	else{
		chicken.move(0.0,-0.1), chickenY-=0.1;
		if(chickenY<=Origin) chickenDir=true;
	}


}

bool SpaceshipChicken :: beamStrike(float X,float Y){
	if (Y<=chickenY )
		if(X>=chickenX-50.0 && X<=chickenX+50.0){
			health-=1;
			return true;
		}
	return false;

}

SpaceshipChicken::~SpaceshipChicken(void)
{
}
