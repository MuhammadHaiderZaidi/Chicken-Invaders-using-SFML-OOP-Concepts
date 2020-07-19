#pragma once
#include "chickens.h"
class EggShipChicken :
	public Chickens
{
public:
	EggShipChicken(void);
	~EggShipChicken(void);

	void  movement();
	bool beamStrike(float,float);
};

class EggShipChickenEgg :
	public Egg
{
public:
	EggShipChickenEgg(void);
	~EggShipChickenEgg(void);

	void eggDropRight(float);
	void eggDropLeft(float);
};

