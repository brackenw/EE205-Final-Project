#include<SFML/Graphics.hpp>
#include<iostream>
class Enemy {
	private:
		sf::Texture enemytex;
		int health;
		sf::Vector2f enemypos;
		int speed;	
	//added private variables for player attack
	std::vector<Bullet> PlayerBullets; //vector of bullets
	//added variables for enemy attack
		int BulletSpeed;
		int MaxBullets;
		float attackTime;
		sf::Clock ReloadTimer; 	
	
	public:
		sf::Sprite enemysprt;
		bool dead;
		Enemy();
		void Attack();
		void IsHit();
		void IsDead();
		void Move();
		
		int GetHealth();
	
	//getter for enemy bullet vector
		std::vector<Bullet> &getBullets();
};
