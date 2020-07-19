#pragma once
#include "chickens.h"
class GunChicken :
	public Chickens
{
public:
	GunChicken(void);
	~GunChicken(void);
	void movement();
	bool beamStrike(float,float);
private:
	int eggDropCount;
};


//Egg egg1(GunChicken1.chickenX-26,GunChicken1.chickenY,1,0.7);
//Egg egg2(GunChicken1.chickenX,GunChicken1.chickenY,1,0.8);
//Egg egg3(GunChicken1.chickenX+26,GunChicken1.chickenY,1,0.75);

//egg1.eggDrop(GunChicken1.chickenX-26,GunChicken1.chickenY);
//egg1.egg_respwan=player1.eggStike(egg1.eggX,egg1.eggY,GunChicken1.damage);
//egg2.eggDrop(GunChicken1.chickenX,GunChicken1.chickenY);
//egg2.egg_respwan=player1.eggStike(egg2.eggX,egg2.eggY,GunChicken1.damage);
//egg3.eggDrop(GunChicken1.chickenX+26,GunChicken1.chickenY);
//egg3.egg_respwan=player1.eggStike(egg3.eggX,egg3.eggY,GunChicken1.damage);

