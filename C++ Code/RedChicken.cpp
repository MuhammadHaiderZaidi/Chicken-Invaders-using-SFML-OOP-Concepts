#include "RedChicken.h"


RedChicken::RedChicken(float X,float Y,sf::Vector2i imageCount, float switchTime):Chickens(X,0.3)
{
	/*sf:: RectangleShape chickenTemp( sf::Vector2f(107.0f,90.0f));*/



	sf::RectangleShape chickenTemp(sf::Vector2f(100.0f, 100.0f));
	chicken=chickenTemp;
	chicken.setOrigin(50.0f,80.0f);
	chicken.setPosition(X,Y);
	chickentexture.loadFromFile("tameez_ki_burned.png");
	chicken.setTexture(&chickentexture);

	chickenX=X,chickenY=Y;
	health=5,chickenDir=true;

	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 2;

	uvRect.width = chickentexture.getSize().x / (float)imageCount.x;
	uvRect.height = chickentexture.getSize().y / (float)imageCount.y;
}

void RedChicken:: movement()
{
	if(chickenDir){
		chicken.move(0.15,0.0), chickenX+=0.15;
		if(chickenX>=Origin+70) chickenDir=false;
	
	}
	else{
		chicken.move(-0.15,0.0), chickenX-=0.15;
		if(chickenX<=Origin) chickenDir=true;
	}

}

bool RedChicken :: beamStrike(float X, float Y)
{
	if (Y<=chickenY )
		if(X>=chickenX-50.0 && X<=chickenX+50.0){
			health-=1;
			return true;
		}
	return false;
}

bool RedChicken::Update(int row, float deltaTime, bool oppose)
{
	currentImage.y = row;
	totalTime += deltaTime;

	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;

	if (oppose) {
		if (totalTime >= switchTime) {
			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x == 2) {
				return (!oppose);
			}
		}

	}
	else {
		if (totalTime >= switchTime) {
			totalTime -= switchTime;
			currentImage.x--;
			
			if (currentImage.x == 0) {
				return (!oppose);
			}
		}
	}
	return oppose;
}


RedChicken::~RedChicken(void)
{
}
