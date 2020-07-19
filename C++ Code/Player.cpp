#include "Player.h"

Player::Player()
{
	sf:: RectangleShape spacecraftTemp( sf::Vector2f(80.0f,100.0f));
	sf:: RectangleShape beamTemp( sf::Vector2f(50.0f,50.0f));
	sf:: RectangleShape health3Temp(sf :: Vector2f(100.0f,33.3f));
	sf:: RectangleShape health2Temp(sf :: Vector2f(66.6f,33.3f));
	sf:: RectangleShape health1Temp(sf :: Vector2f(33.3f,33.3f));

	health1=health1Temp,health2=health2Temp,health3=health3Temp;
	spacecraft=spacecraftTemp,beam=beamTemp;
	spacecraft.setOrigin(40.0f,0.0f);
	spacecraft.setPosition(450.0f,470.0f);
	beam.setOrigin(25.0f,25.0f);
	health3.setPosition(10,10);
	health2.setPosition(10,10);
	health1.setPosition(10,10);


	beamtexture.loadFromFile("beam4.png");
	spacecrafttexture.loadFromFile("spacecraft3.png");
	health1texture.loadFromFile("health1.png");
	health2texture.loadFromFile("health2.png");
	health3texture.loadFromFile("health3.png");

	spacecraft.setTexture(&spacecrafttexture);
	beam.setTexture(&beamtexture);
	health1.setTexture(&health1texture);
	health2.setTexture(&health2texture);
	health3.setTexture(&health3texture);

	spaceraftX=450.0,spaceraftY=470.0;
	health=3.0,beamMove=false;
}


void  Player :: movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && spaceraftX<1017.0)
		spacecraft.move(0.4f,0.0f),spaceraftX+=0.4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && spaceraftX>50.0)
		spacecraft.move(-0.4f,0.0f),spaceraftX-=0.4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && spaceraftY<500.0)
		spacecraft.move(0.0f,0.2f),spaceraftY+=0.2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && spaceraftY>0.0)
		spacecraft.move(0.0f,-0.4f),spaceraftY-=0.4;
}

void  Player :: beamShoot()
{
	if(beamY<=0.0 || beam_respawn)
		beamMove=false,beam_respawn=false,beamX=0.0,beamY=0.0;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !beamMove ){
			beam.setPosition(spaceraftX,spaceraftY);
			beamY=spaceraftY,beamX=spaceraftX;
			beamMove = true;
		}
	
	if(beamMove) 
		beam.move(0.0f,-2.0f),beamY-=2.0;

}

bool Player:: eggStike(float X,float Y,float damage){
	if (spaceraftY<=Y && (spaceraftY+100.0)>=Y)
		if((spaceraftX-40)<=X && (spaceraftX+40)>=X){
			health-=damage;

			return true;
		}
	return false;
}
 
bool Player :: DisplayHealth3()
{
	if(health>2.0) return true;
	else return false;
}

bool Player :: DisplayHealth2()
{
	if(health>1.0 && health<=2.0) return true;
	else return false;
}

bool Player :: DisplayHealth1()
{
	if(health<=1.0 && health>=0) return true;
	else return false;
}

Player::~Player(void)
{
}
