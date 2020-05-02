#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"bullet.hpp"
enum Dir {stop, up, down, left, right};

class Player {
	private:
		float health;
		float speed;
		int direction;
	
	//added private variables for player attack
	std::vector<Bullet> PlayerBullets; //vector of bullets

	sf::Clock ReloadTimer; 				//reload timer to track time since last shot
	float ReloadTime;					//Reload time to stop bullet spam
	int MaxBullets;                     //Max ammo                              
	float BulletSpeed;
			
		
	public:
		//sprite acts as body, handles collision logic
		bool hit;
		sf::Texture tex;
		sf::Sprite playersprt;
		Player();
		std::vector<Bullet> BulletVec;
		void Move();
		void SetDirection(sf::Keyboard::Key x);
		void Attack();
		void IsHit();	

	//added getter for bullet vector
		std::vector<Bullet> &getBullets();
};
