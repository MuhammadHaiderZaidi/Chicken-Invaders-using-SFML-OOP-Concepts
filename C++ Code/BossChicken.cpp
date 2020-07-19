#include "BossChicken.h"


BossChicken::BossChicken(void):Chickens(1)
{
	sf:: RectangleShape chickenTemp( sf::Vector2f(199.0,160.0));
	sf:: RectangleShape Bosshealth4Temp(sf :: Vector2f(407.0f,26.0f));
	sf:: RectangleShape Bosshealth3Temp(sf :: Vector2f(407.0f,26.0f));
	sf:: RectangleShape Bosshealth2Temp(sf :: Vector2f(407.0f,26.0f));
	sf:: RectangleShape Bosshealth1Temp(sf :: Vector2f(407.0f,26.0f));

	Bosshealth1=Bosshealth1Temp,Bosshealth2=Bosshealth2Temp,Bosshealth3=Bosshealth3Temp,Bosshealth4=Bosshealth4Temp;
	chicken=chickenTemp;
	chicken.setOrigin(99.5f,130.0f);
	chicken.setPosition(533.5,200.0);
	Bosshealth4.setPosition(330,540);
	Bosshealth3.setPosition(330,540);
	Bosshealth2.setPosition(330,540);
	Bosshealth1.setPosition(330,540);
	
	chickentexture.loadFromFile("UFOChicken.png");
	Bosshealth1texture.loadFromFile("bossHealthBar1.png");
	Bosshealth2texture.loadFromFile("bossHealthBar2.png");
	Bosshealth3texture.loadFromFile("bossHealthBar3.png");
	Bosshealth4texture.loadFromFile("bossHealthBar4.png");

	chicken.setTexture(&chickentexture);
	Bosshealth1.setTexture(&Bosshealth1texture);
	Bosshealth2.setTexture(&Bosshealth2texture);
	Bosshealth3.setTexture(&Bosshealth3texture);
	Bosshealth4.setTexture(&Bosshealth4texture);

	chickenX=533.5,chickenY=200.0;
	health=55,moveX=-0.6,moveY=0.0,newMove=0;
}

bool BossChicken :: beamStrike(float X,float Y){
	if (Y<=chickenY && Y>=chickenY-130.0 )
		if(X>=chickenX-99.5 && X<=chickenX+99.5){
			health--;
			return true;
		}
	return false;

}

void BossChicken :: movement()
{
	if(chickenX<=99.5){
		if(newMove==2) moveX=0.4,moveY=0.0;
		else moveX=0.3,moveY=-0.3;
		newMove=(rand() % (2))+1;
	}
	if(chickenX>=967.5){
		if(newMove==2) moveX=-0.4,moveY=0.0;
		else moveX=-0.3,moveY=-0.4;
		newMove=(rand() % (2))+1;
	}
	if(chickenY>560.0){
		if(newMove==2) moveX=0.0,moveY=-0.4;
		else moveX=0.4,moveY=-0.3;
		newMove=(rand() % (2))+1;
	}
	if(chickenY< 130.0){
		if(newMove==2) moveX=0.0,moveY=0.4;
		else moveX=-0.4,moveY=0.3;
		newMove=(rand() % (2))+1;
	}

	chicken.move(moveX,moveY),chickenX+=moveX,chickenY+=moveY;
	
}

bool BossChicken :: DisplayHealth4()
{
	if(health>42) return true;
	else return false;
}

bool BossChicken :: DisplayHealth3()
{
	if(health>28 && health<=42) return true;
	else return false;
}

bool BossChicken :: DisplayHealth2()
{
	if(health>14 && health<=28) return true;
	else return false;
}

bool BossChicken :: DisplayHealth1()
{
	if(health<=14 && health>=0) return true;
	else return false;
}

BossChicken::~BossChicken(void)
{
}
