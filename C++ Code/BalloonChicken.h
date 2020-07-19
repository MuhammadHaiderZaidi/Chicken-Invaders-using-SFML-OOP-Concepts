#pragma once
#include "chickens.h"
class BalloonChicken :
	public Chickens
{
public:
	BalloonChicken(void);
	~BalloonChicken(void);
	void movement();
	bool beamStrike(float,float);
};

