#pragma once
#include "chickens.h"
class BossChicken :
	public Chickens
{
public:
	BossChicken(void);
	~BossChicken(void);
	void movement();
	bool beamStrike(float,float);
	bool DisplayHealth4();
	bool DisplayHealth3();
	bool DisplayHealth2();
	bool DisplayHealth1();

	sf:: RectangleShape Bosshealth1;
	sf:: RectangleShape Bosshealth2;
	sf:: RectangleShape Bosshealth3;
	sf:: RectangleShape Bosshealth4;
private:
	float moveX,moveY;
	int newMove;

	sf :: Texture Bosshealth1texture;
	sf :: Texture Bosshealth2texture;
	sf :: Texture Bosshealth3texture;
	sf :: Texture Bosshealth4texture;
};

