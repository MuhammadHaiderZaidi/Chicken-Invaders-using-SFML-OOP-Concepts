#pragma once
#include "chickens.h"
class SpaceshipChicken :
	public Chickens
{
public:
	SpaceshipChicken(float,float);
	~SpaceshipChicken(void);
	void movement();
	bool beamStrike(float,float);
};

