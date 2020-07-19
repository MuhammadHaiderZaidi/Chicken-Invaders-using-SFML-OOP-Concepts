#pragma once
#include<SFML\Graphics.hpp>
class Player
{
public:
	Player();
	~Player(void);
	void movement();
	void beamShoot();
	bool eggStike(float,float,float);
	bool DisplayHealth3();
	bool DisplayHealth2();
	bool DisplayHealth1();

public:

	float health;
	float spaceraftX,spaceraftY;
	bool beamMove;
	float beamX,beamY;
	bool beam_respawn;


	sf:: RectangleShape health1;
	sf:: RectangleShape health2;
	sf:: RectangleShape health3;
	sf:: RectangleShape beam;
	sf:: RectangleShape spacecraft;
	sf :: Texture beamtexture;

private:
	
	sf :: Texture spacecrafttexture;
	sf :: Texture health1texture;
	sf :: Texture health2texture;
	sf :: Texture health3texture;
};
