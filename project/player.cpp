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
void Player::Attack() {
	std::cout << "DEBUG: entering shoot function" << std::endl;
	//only moves for brief period of time, figure out how to keep running shoot function
	
	
	return;
}

void Player::IsHit() {
	health = health - 10;
	hit = 0;
}
