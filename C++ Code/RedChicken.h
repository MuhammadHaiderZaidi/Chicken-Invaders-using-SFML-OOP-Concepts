#pragma once
#include "chickens.h"
class RedChicken :
	public Chickens
{
private:

	sf::Vector2i imageCount;
	sf::Vector2i currentImage;

	float totalTime;
	float switchTime;

public:

	sf::IntRect uvRect;


public:
	RedChicken(float,float,sf::Vector2i imageCount, float switchTime);
	~RedChicken(void);
	void  movement();
	bool beamStrike(float,float);

	//Animation(sf::Vector2i imageCount, float switchTime);
	//~Animation();

	bool Update(int row, float deltaTime, bool oppose);

};

