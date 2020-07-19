#include<iostream>
#include "Player.h"
#include "Chickens.h"
#include "BalloonChicken.h"
#include "BossChicken.h"
#include "RedChicken.h"
#include "FrozenChicken.h"
#include "SpaceshipChicken.h"
#include "GunChicken.h"
#include "EggShipChicken.h"


int main(){
	bool l1=false,l2=false,l3=false,l4=false,l5=false;
	
	sf::RenderWindow window(sf::VideoMode(1067,600), "LEVEL 4",sf::Style::Close | sf::Style::Titlebar);
	 sf::Texture background1;
     background1.loadFromFile("levelCleared.jpg");
     sf::Sprite levelCleared;
     levelCleared.setTexture(background1);

	 sf::Texture background2;
     background2.loadFromFile("gameOver.jpg");
     sf::Sprite gameOver;
     gameOver.setTexture(background2);

	 bool ballonMove=true;
	 
	 sf::Texture level;
     level.loadFromFile("levelselect.png");
     sf::Sprite levelsprite;
	 levelsprite.setTexture(level);

	  sf::Texture mainbackground;
     mainbackground.loadFromFile("mainBackground.png");
     sf::Sprite homescreen;
	 while(window.isOpen()){
		 sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
     homescreen.setTexture(mainbackground);
	
	 while(true){
		 window.clear();
		window.draw(homescreen);
	 window.display();
	  sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	 while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){};
		 window.clear();
		 window.draw(levelsprite);
		 window.display();
		 while(true){
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){ l1=true;break; }
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)){ l2=true;break; }
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)){ l3=true;break; }
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)){ l4=true;break; }
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)){ l5=true;break; }
		 }
//	LEVEL : 1
	 if(l1){
	 sf::Texture background;
     background.loadFromFile("background1.jpg");
     sf::Sprite sprite;
     sprite.setTexture(background);
	
	RedChicken redchicken1( 237.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken2( 337.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken3( 437.0,100.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken4( 537.0,100.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken5( 637.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken6( 737.0,200.0,sf ::Vector2i(3, 1), 0.05f);

	Egg	egg01(redchicken1.chickenX,redchicken1.chickenY,0.9,0.7);
	Egg	egg02(redchicken2.chickenX,redchicken2.chickenY,0.9,0.7);
	Egg	egg03(redchicken3.chickenX,redchicken3.chickenY,0.9,0.7);
	Egg	egg04(redchicken4.chickenX,redchicken4.chickenY,0.9,0.7);
	Egg	egg05(redchicken5.chickenX,redchicken5.chickenY,0.9,0.7);
	Egg	egg06(redchicken6.chickenX,redchicken6.chickenY,0.9,0.7);

	ballonMove=true;
	BalloonChicken balloonchicken1;
	Egg balloonchickenegg(balloonchicken1.chickenX,balloonchicken1.chickenY,0.9,0.4);

	Player player; 

	bool oppose = false;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while(window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {Chickens :: numOfChick=0;  break; }
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(sprite);

		player.movement();
		player.beamShoot();

		if(redchicken1.health>0.0){
			redchicken1.Update(0, deltaTime, oppose);
			redchicken1.chicken.setTextureRect(redchicken1.uvRect);

			egg01.eggDrop(redchicken1.chickenX,redchicken1.chickenY);
			egg01.egg_respwan=player.eggStike(egg01.eggX,egg01.eggY,redchicken1.damage);		
			redchicken1.movement();
			window.draw(egg01.egg);
			window.draw(redchicken1.chicken);

			if(redchicken1.health==1) redchicken1.health--,
				redchicken1.chickenX=-1,redchicken1.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken2.health>0.0){
			redchicken2.Update(0, deltaTime, oppose);
			redchicken2.chicken.setTextureRect(redchicken2.uvRect);
			
			egg02.eggDrop(redchicken2.chickenX,redchicken2.chickenY);
			egg02.egg_respwan=player.eggStike(egg02.eggX,egg02.eggY,redchicken2.damage);
			redchicken2.movement();
			window.draw(egg02.egg);
			window.draw(redchicken2.chicken);

			if(redchicken2.health==1) redchicken2.health--,
				redchicken2.chickenX=-1,redchicken2.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken3.health>0.0){
			redchicken3.Update(0, deltaTime, oppose);
			redchicken3.chicken.setTextureRect(redchicken3.uvRect);
			
			egg03.eggDrop(redchicken3.chickenX,redchicken3.chickenY);
			egg03.egg_respwan=player.eggStike(egg03.eggX,egg03.eggY,redchicken3.damage);
			redchicken3.movement();
			window.draw(egg03.egg);
			window.draw(redchicken3.chicken);

			if(redchicken3.health==1) redchicken3.health--,
				redchicken3.chickenX=-1,redchicken3.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken4.health>0.0){
			redchicken4.Update(0, deltaTime, oppose);
			redchicken4.chicken.setTextureRect(redchicken4.uvRect);
			
			egg04.eggDrop(redchicken4.chickenX,redchicken4.chickenY);
			egg04.egg_respwan=player.eggStike(egg04.eggX,egg04.eggY,redchicken4.damage);
			redchicken4.movement();
			window.draw(egg04.egg);
			window.draw(redchicken4.chicken);

			if(redchicken4.health==1) redchicken4.health--,
				redchicken4.chickenX=-1,redchicken4.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken5.health>0.0){
			redchicken5.Update(0, deltaTime, oppose);
			redchicken5.chicken.setTextureRect(redchicken5.uvRect);
		
			egg05.eggDrop(redchicken5.chickenX,redchicken5.chickenY);
			egg05.egg_respwan=player.eggStike(egg05.eggX,egg05.eggY,redchicken5.damage);
			redchicken5.movement();
			window.draw(egg05.egg);
			window.draw(redchicken5.chicken);

			if(redchicken5.health==1) redchicken5.health--,
				redchicken5.chickenX=-1,redchicken5.chickenY=-1,Chickens :: numOfChick--;
		}

		
		oppose = redchicken6.Update(0, deltaTime, oppose);

		if(redchicken6.health>0.0){
			
			redchicken6.chicken.setTextureRect(redchicken6.uvRect);
		
			egg06.eggDrop(redchicken6.chickenX,redchicken6.chickenY);
			egg06.egg_respwan=player.eggStike(egg06.eggX,egg06.eggY,redchicken6.damage);

			redchicken6.movement();
			window.draw(egg06.egg);
			window.draw(redchicken6.chicken);

			if(redchicken6.health==1) redchicken6.health--,
				redchicken6.chickenX=-1,redchicken6.chickenY=-1,Chickens :: numOfChick--;

		}

		if(player.health<2.0 && ballonMove && balloonchicken1.health>0.0 ){
			balloonchicken1.movement();
			balloonchickenegg.eggDrop(balloonchicken1.chickenX,balloonchicken1.chickenY);
			balloonchickenegg.egg_respwan=player.eggStike(balloonchickenegg.eggX,balloonchickenegg.eggY,balloonchicken1.damage);
			
			window.draw(balloonchickenegg.egg);
			window.draw(balloonchicken1.chicken);

			if(balloonchicken1.chickenY<-50.0) ballonMove=false,Chickens :: numOfChick--;
			else if(balloonchicken1.health==1.0){
				balloonchicken1.health--,balloonchicken1.chickenX=-1,balloonchicken1.chickenY=-1,Chickens :: numOfChick--;
				player.beamtexture.loadFromFile("beam1.png");
				player.beam.setTexture(&player.beamtexture);
			}
		}
		else if( ( Chickens :: numOfChick)==1 && balloonchicken1.health==5 && ballonMove==true) (Chickens :: numOfChick)--;


		if(	redchicken1.beamStrike(player.beamX,player.beamY) || redchicken2.beamStrike(player.beamX,player.beamY) ||
			redchicken3.beamStrike(player.beamX,player.beamY) || redchicken4.beamStrike(player.beamX,player.beamY) || 
			redchicken5.beamStrike(player.beamX,player.beamY) || redchicken6.beamStrike(player.beamX,player.beamY) ||
			balloonchicken1.beamStrike(player.beamX,player.beamY))
			player.beam_respawn=true;
		else player.beam_respawn=false;


		if(player.beamMove)
			window.draw(player.beam);
		window.draw(player.spacecraft);
		if(player.DisplayHealth3()) window.draw(player.health3);
		if(player.DisplayHealth2()) window.draw(player.health2);
		if(player.DisplayHealth1()) window.draw(player.health1);

		window.display();

		if(!(Chickens :: numOfChick)){
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			break;
		}
		if(player.health<=0.0){
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			Chickens :: numOfChick=0;
			break;
		}
	}
	l1=false;
	}

	 /*LEVEL : 2*/
	
	if(l2){
	 sf::Texture background3;
     background3.loadFromFile("background3.jpg");
     sf::Sprite sprite1;
     sprite1.setTexture(background3);

	 Player player1; 

	 SpaceshipChicken SpaceChicken1(233.5,100.0);
	 SpaceshipChicken SpaceChicken2(533.5,100.0);
	 SpaceshipChicken SpaceChicken3(833.5,100.0);

	 Egg egg1(SpaceChicken1.chickenX,SpaceChicken1.chickenY,1.2,0.6);
	 Egg egg2(SpaceChicken2.chickenX,SpaceChicken2.chickenY,1.2,0.6);
	 Egg egg3(SpaceChicken3.chickenX,SpaceChicken3.chickenY,1.2,0.6);

	 ballonMove=true;
	BalloonChicken balloonchicken2;
	Egg balloonchickenegg2(balloonchicken2.chickenX,balloonchicken2.chickenY,0.9,0.4);

	 while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {Chickens :: numOfChick=0;  break; }
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();		
		}

		window.clear();
		window.draw(sprite1);

		player1.movement();
		player1.beamShoot();

		if(SpaceChicken1.health>0.0){
			SpaceChicken1.movement();
			egg1.eggDrop(SpaceChicken1.chickenX,SpaceChicken1.chickenY);
			egg1.egg_respwan=player1.eggStike(egg1.eggX,egg1.eggY,SpaceChicken1.damage);
			
			window.draw(egg1.egg);
			window.draw(SpaceChicken1.chicken);
			if(SpaceChicken1.health==1) SpaceChicken1.health--,
				SpaceChicken1.chickenX=-1,SpaceChicken1.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken2.health>0.0){
			SpaceChicken2.movement();
			egg2.eggDrop(SpaceChicken2.chickenX,SpaceChicken2.chickenY);
			egg2.egg_respwan=player1.eggStike(egg2.eggX,egg2.eggY,SpaceChicken2.damage);
			
			window.draw(egg2.egg);
			window.draw(SpaceChicken2.chicken);
			if(SpaceChicken2.health==1) SpaceChicken2.health--,
				SpaceChicken2.chickenX=-1,SpaceChicken2.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken3.health>0.0){
			SpaceChicken3.movement();
			egg3.eggDrop(SpaceChicken3.chickenX,SpaceChicken3.chickenY);
			egg3.egg_respwan=player1.eggStike(egg3.eggX,egg3.eggY,SpaceChicken3.damage);
			
			window.draw(egg3.egg);
			window.draw(SpaceChicken3.chicken);
			if(SpaceChicken3.health==1) SpaceChicken3.health--,
				SpaceChicken3.chickenX=-1,SpaceChicken3.chickenY=-1,Chickens :: numOfChick--;
		}
		
		if(player1.health<2.0 && ballonMove && balloonchicken2.health>0.0 ){
			balloonchicken2.movement();
			balloonchickenegg2.eggDrop(balloonchicken2.chickenX,balloonchicken2.chickenY);
			balloonchickenegg2.egg_respwan=player1.eggStike(balloonchickenegg2.eggX,balloonchickenegg2.eggY,balloonchicken2.damage);
			
			window.draw(balloonchickenegg2.egg);
			window.draw(balloonchicken2.chicken);

			if(balloonchicken2.chickenY<-50.0) ballonMove=false,Chickens :: numOfChick--;
			else if(balloonchicken2.health==1.0){
				balloonchicken2.health--,balloonchicken2.chickenX=-1,balloonchicken2.chickenY=-1,Chickens :: numOfChick--;
				player1.beamtexture.loadFromFile("beam1.png");
				player1.beam.setTexture(&player1.beamtexture);
			}
		}
		else if( ( Chickens :: numOfChick)==1 && balloonchicken2.health==5 && ballonMove==true) (Chickens :: numOfChick)--;

		if( SpaceChicken1.beamStrike(player1.beamX,player1.beamY) || SpaceChicken2.beamStrike(player1.beamX,player1.beamY) ||
			SpaceChicken3.beamStrike(player1.beamX,player1.beamY) ||
			balloonchicken2.beamStrike(player1.beamX,player1.beamY))
			player1.beam_respawn=true;
		else player1.beam_respawn=false;

		if(player1.beamMove)
			window.draw(player1.beam);
		window.draw(player1.spacecraft);
		if(player1.DisplayHealth3()) window.draw(player1.health3);
		if(player1.DisplayHealth2()) window.draw(player1.health2);
		if(player1.DisplayHealth1()) window.draw(player1.health1);

		if(!(Chickens :: numOfChick)){
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			break;
		}
		if(player1.health<=0.0){
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			Chickens :: numOfChick=0;
			break;
		}
		window.display();

	 }
	 l2=false;
	 }



	 /*LEVEL : 3*/
	 
	 if(l3){
	sf::Texture background4;
	background4.loadFromFile("background2.jpg");
    sf::Sprite sprite2;
    sprite2.setTexture(background4);
	
	Player player2; 


	RedChicken redchicken7( 200.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken8( 867.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	EggShipChicken EggShipChicken1;


	EggShipChickenEgg egg4;
	EggShipChickenEgg egg5;
	EggShipChickenEgg egg6;
	Egg	egg07(redchicken7.chickenX,redchicken7.chickenY,0.9,0.7);
	Egg	egg08(redchicken8.chickenX,redchicken8.chickenY,0.9,0.7);

	bool oppose = false;
	float deltaTime = 0.0f;
	sf:: Clock clock;
	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {Chickens :: numOfChick=0;  break; }
		deltaTime = clock.restart().asSeconds();
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();		
		}

		window.clear();
		window.draw(sprite2);

		player2.movement();
		player2.beamShoot();

		if(EggShipChicken1.health>0)
		{
			EggShipChicken1.movement();
			egg4.eggDrop(EggShipChicken1.chickenX,EggShipChicken1.chickenY);
			egg4.egg_respwan=player2.eggStike(egg4.eggX,egg4.eggY,EggShipChicken1.damage);
			egg5.eggDropLeft(EggShipChicken1.chickenY);
			egg5.egg_respwan=player2.eggStike(egg5.eggX,egg5.eggY,EggShipChicken1.damage);
			egg6.eggDropRight(EggShipChicken1.chickenY);
			egg6.egg_respwan=player2.eggStike(egg6.eggX,egg6.eggY,EggShipChicken1.damage);

			window.draw(EggShipChicken1.chicken);
			window.draw(egg4.egg);
			window.draw(egg5.egg);
			window.draw(egg6.egg);

			if(EggShipChicken1.health==1) EggShipChicken1.health--,
				EggShipChicken1.chickenX=-1,EggShipChicken1.chickenY=-1,Chickens :: numOfChick--;
		}
	
		if(redchicken7.health>0.0){
			redchicken7.Update(0, deltaTime, oppose);
			redchicken7.chicken.setTextureRect(redchicken7.uvRect);
		
			egg07.eggDrop(redchicken7.chickenX,redchicken7.chickenY);
			egg07.egg_respwan=player2.eggStike(egg07.eggX,egg07.eggY,redchicken7.damage);
			redchicken7.movement();
			window.draw(egg07.egg);
			window.draw(redchicken7.chicken);

			if(redchicken7.health==1) redchicken7.health--,
				redchicken7.chickenX=-1,redchicken7.chickenY=-1,Chickens :: numOfChick--;
		}


		oppose = redchicken8.Update(0, deltaTime, oppose);

		if(redchicken8.health>0.0){
			
			redchicken8.chicken.setTextureRect(redchicken8.uvRect);
		
			egg08.eggDrop(redchicken8.chickenX,redchicken8.chickenY);
			egg08.egg_respwan=player2.eggStike(egg08.eggX,egg08.eggY,redchicken8.damage);

			redchicken8.movement();
			window.draw(egg08.egg);
			window.draw(redchicken8.chicken);

			if(redchicken8.health==1) redchicken8.health--,
				redchicken8.chickenX=-1,redchicken8.chickenY=-1,Chickens :: numOfChick--;

		}


		if( EggShipChicken1.beamStrike(player2.beamX,player2.beamY) || redchicken7.beamStrike(player2.beamX,player2.beamY) || redchicken8.beamStrike(player2.beamX,player2.beamY))
			player2.beam_respawn=true;
		else player2.beam_respawn=false;




		if(player2.beamMove)
			window.draw(player2.beam);
		window.draw(player2.spacecraft);
		if(player2.DisplayHealth3()) window.draw(player2.health3);
		if(player2.DisplayHealth2()) window.draw(player2.health2);
		if(player2.DisplayHealth1()) window.draw(player2.health1);
		if(!(Chickens :: numOfChick)){
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			break;
		}
		if(player2.health<=0.0){
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			Chickens :: numOfChick=0;
			break;
		}
		window.display();


	}
	l3=false;
	}

	if(l4){
	/* LEVEL : 4*/
	l4:
	 sf::Texture background5;
     background5.loadFromFile("background5.jpg");
     sf::Sprite sprite3;
     sprite3.setTexture(background5);

	Player player3; 
	GunChicken GunChicken1;
	SpaceshipChicken SpaceChicken4(70.0,200.0);
	SpaceshipChicken SpaceChicken5(997.0,200.0);
	Egg egg7(GunChicken1.chickenX-26,GunChicken1.chickenY,1,0.7);
	Egg egg8(GunChicken1.chickenX,GunChicken1.chickenY,1,0.8);
	Egg egg9(GunChicken1.chickenX+26,GunChicken1.chickenY,1,0.75);
	Egg egg10(SpaceChicken4.chickenX,SpaceChicken4.chickenY,1.2,0.6);
	Egg egg11(SpaceChicken5.chickenX,SpaceChicken5.chickenY,1.2,0.6);

	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {Chickens :: numOfChick=0;  break; }
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();		
		}

		window.clear();
		window.draw(sprite3);

		player3.movement();
		player3.beamShoot();


		

		if(GunChicken1.health>0.0){
			GunChicken1.movement();
			egg7.eggDrop(GunChicken1.chickenX-26,GunChicken1.chickenY);
			egg7.egg_respwan=player3.eggStike(egg7.eggX,egg7.eggY,GunChicken1.damage);
			egg8.eggDrop(GunChicken1.chickenX,GunChicken1.chickenY);
			egg8.egg_respwan=player3.eggStike(egg8.eggX,egg8.eggY,GunChicken1.damage);
			egg9.eggDrop(GunChicken1.chickenX+26,GunChicken1.chickenY);
			egg9.egg_respwan=player3.eggStike(egg9.eggX,egg9.eggY,GunChicken1.damage);
			window.draw(GunChicken1.chicken);
			window.draw(egg7.egg);
			window.draw(egg8.egg);
			window.draw(egg9.egg);

			if(GunChicken1.health==1) GunChicken1.health--,
				GunChicken1.chickenX=-1,GunChicken1.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken4.health>0.0){
			SpaceChicken4.movement();
			egg10.eggDrop(SpaceChicken4.chickenX,SpaceChicken4.chickenY);
			egg10.egg_respwan=player3.eggStike(egg10.eggX,egg10.eggY,SpaceChicken4.damage);
			
			window.draw(egg10.egg);
			window.draw(SpaceChicken4.chicken);

			if(SpaceChicken4.health==1) SpaceChicken4.health--,
				SpaceChicken4.chickenX=-1,SpaceChicken4.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken5.health>0.0){
			SpaceChicken5.movement();
			egg11.eggDrop(SpaceChicken5.chickenX,SpaceChicken5.chickenY);
			egg11.egg_respwan=player3.eggStike(egg11.eggX,egg11.eggY,SpaceChicken5.damage);

			window.draw(egg11.egg);
			window.draw(SpaceChicken5.chicken);

			if(SpaceChicken5.health==1) SpaceChicken5.health--,
				SpaceChicken5.chickenX=-1,SpaceChicken5.chickenY=-1,Chickens :: numOfChick--;
		}
		
		if(GunChicken1.beamStrike(player3.beamX,player3.beamY) || SpaceChicken4.beamStrike(player3.beamX,player3.beamY) || SpaceChicken5.beamStrike(player3.beamX,player3.beamY))
			player3.beam_respawn=true;
		else player3.beam_respawn=false;

		if(player3.beamMove)
			window.draw(player3.beam);
		window.draw(player3.spacecraft);
		if(player3.DisplayHealth3()) window.draw(player3.health3);
		if(player3.DisplayHealth2()) window.draw(player3.health2);
		if(player3.DisplayHealth1()) window.draw(player3.health1);

		if(!(Chickens :: numOfChick)){
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			break;
		}
		if(player3.health<=0.0){
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			Chickens :: numOfChick=0;
			break;
		}
		
		window.display();
	}
	l4=false;
	}

	 //LEVEL : 5
	if(l5){

	sf::Texture background6;
     background6.loadFromFile("background4.jpg");
     sf::Sprite sprite4;
     sprite4.setTexture(background6);

	Player player4;
	FrozenChicken FrozenChicken1;
	BossChicken BossChicken1;
	Egg egg12(BossChicken1.chickenX,BossChicken1.chickenY,1.7,0.8);

	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {Chickens :: numOfChick=0;  break; }
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();		
		}

		window.clear();
		window.draw(sprite4);

		player4.movement();
		player4.beamShoot();

		if(BossChicken1.health>0.0)
		{
			BossChicken1.movement();
			egg12.eggDrop(BossChicken1.chickenX,BossChicken1.chickenY);
			egg12.egg_respwan=player4.eggStike(egg12.eggX,egg12.eggY,BossChicken1.damage);
			player4.beam_respawn=BossChicken1.beamStrike(player4.beamX,player4.beamY);

			window.draw(egg12.egg);
			window.draw(BossChicken1.chicken);
			if(BossChicken1.health==1) Chickens ::numOfChick--;
			
		}

		FrozenChicken1.movement();
		if(FrozenChicken1.Collision(player4.spaceraftX,player4.spaceraftY)) player4.health-=1;
			
		if(player4.beamMove)
			window.draw(player4.beam);
		window.draw(player4.spacecraft);
		window.draw(FrozenChicken1.chicken);

		if(BossChicken1.DisplayHealth4()) window.draw(BossChicken1.Bosshealth4);
		if(BossChicken1.DisplayHealth3()) window.draw(BossChicken1.Bosshealth3);
		if(BossChicken1.DisplayHealth2()) window.draw(BossChicken1.Bosshealth2);
		if(BossChicken1.DisplayHealth1()) window.draw(BossChicken1.Bosshealth1);

		if(player4.DisplayHealth3()) window.draw(player4.health3);
		if(player4.DisplayHealth2()) window.draw(player4.health2);
		if(player4.DisplayHealth1()) window.draw(player4.health1);

	if(!(Chickens :: numOfChick)){
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			break;
		}
		if(player4.health<=0.0){
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){};
			Chickens ::numOfChick=0;
			break;
		}

		window.display();
	}
	l5=false;
	}
	}
	}
	return 0;
}