#pragma once

#include "Entity.h"

class EntityLiving : public Entity{

protected:
	
	int health;

	//The velocity of the entity
	int velX, velY;

public:
	static const int DEFAULT_HEALTH = 100;
	static const int DEFAULT_VELOCITY = 10;

	EntityLiving() : Entity(){
		this->health = DEFAULT_HEALTH;
	}

	EntityLiving(std::string texturePath, SDL_Renderer* renderer, Settings* settings, int localX = DEFAULT_POS, int localY = DEFAULT_POS, 
				 int width = DEFAULT_SIZE, int height = DEFAULT_SIZE, int health = DEFAULT_HEALTH) :
		Entity(texturePath, renderer, settings, localX, localY, width, height){
		
		this->health = health;

	}

	~EntityLiving() {
		Entity::free();
	}

	void move() {
		
		//if you dont move, you dont have to do anything within this if statement
		if (velX != 0) {

			//move left or right
			posX += velX;
			hitbox.x += velX;

			//check for collision with borders  //getScreenWidth returns a pointer, so dereference before comparing
			if ((posX < 0) || (posX + width > *(settings->getScreenWidth())) || isColliding()) {
				//Move back
				posX -= velX;
				hitbox.x -= velX;
			}

		}

		//if you dont move, you dont have to do anything within this if statement
		if (velY != 0) {

			//Move up or down
			posY += velY;
			hitbox.y += velY;

			//check for collision with borders 	//same here for height
			if ((posY < 0) || (posY + height > *(settings->getScreenHeight())) || isColliding()) {
				//Move back
				posY -= velY;
				hitbox.y -= velY;
			}

		}
	}



};

