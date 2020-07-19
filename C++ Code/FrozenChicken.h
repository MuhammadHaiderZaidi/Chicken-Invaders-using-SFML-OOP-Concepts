#pragma once
#include<SFML\Graphics.hpp>

class FrozenChicken
{
public:
	FrozenChicken(void);
	~FrozenChicken(void);
	void movement();
	bool Collision(float,float);
	sf :: RectangleShape chicken;
	
private:
	float chickenX,chickenY;
	sf :: Texture chickentexture;
	float rotation;
	bool respawn;

};

