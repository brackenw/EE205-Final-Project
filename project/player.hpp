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

};
