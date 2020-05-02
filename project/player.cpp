#include"player.hpp"
#include<iostream>

Player::Player() {
	tex.loadFromFile("okayu.png");
	playersprt.setTexture(tex);
	playersprt.setColor(sf::Color(255, 255, 255, 255));
	playersprt.setPosition(0, 300);
//	BulletVec.resize(100);
	health = 100;
	direction = stop;
	hit = 0;
	speed = 5;
	//attack definitions
	ReloadTime = 0.05f;
	MaxBullets = 3;
	BulletSpeed = 50;
	BulletTexture.loadFromFile("Images/PlayerBullet.png");
}

void Player::Move() {
	switch (this->direction) {
		case left:
			playersprt.move(-speed, 0);
			break;
		case right:
			playersprt.move(speed, 0);
			break;
		case up:
			playersprt.move(0, -speed);
			break;
		case down:
			playersprt.move(0, speed);
			break;
		case stop:
			playersprt.move(0, 0);
			break;
	}
}

void Player::SetDirection(sf::Keyboard::Key x) {
	switch(x) {
		case sf::Keyboard::Left:
			direction = left;
			break;
		case sf::Keyboard::Right:
			direction = right;
			break;
		case sf::Keyboard::Down:
			direction = down;
			break;
		case sf::Keyboard::Up:
			direction = up;
			break;
		case sf::Keyboard::Space:
			Attack();
			break;
		case sf::Keyboard::S:
			direction = stop;
			break;
	}
}

//REWRITE THIS TO BE PUT IN MAIN PROGRAM
//iterates through vector of bullets, checks if active, and moves it if so
//Spacebar should make the vector push an active bullet 

std::vector<Bullet> &Player::getBullets() { return PlayerBullets; } //bullet getter
void Player::Attack() {											
	if (ReloadTimer.getElapsedTime().asSeconds() > ReloadTime && PlayerBullets.size() < MaxBullets ) { //check for available ammo and if ready to fire
			sf::Vector2f Nose(getGlobalBounds().left + getGlobalBounds().width / 2, getGlobalBounds().top); //define nose of ship
			PlayerBullets.push_back(Bullet(BulletTexture, sf::Vector2f(0, -BulletSpeed)));	//adds bullet to stack
			int last = PlayerBullets.size() - 1;											//sets new bullet to last
			PlayerBullets[last].getSprite().setPosition(Nose.x - PlayerBullets[last].getSprite().getGlobalBounds().width / 2, Nose.y); //places bullet at nose
		
	}
	ReloadTimer.restart(); //reloads ammo
}

void Player::IsHit() {
	health = health - 10;
	hit = 0;
}
