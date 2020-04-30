#include"enemy.hpp"
using namespace std;
Enemy::Enemy() {
	enemytex.loadFromFile("hypers.png");
	enemysprt.setTexture(enemytex);
	enemysprt.setColor(sf::Color(255, 255, 255, 255));
	enemysprt.setScale(0.25, 0.25);
	speed = -6;
	enemysprt.setPosition(1200, 300);
	enemypos = enemysprt.getPosition();
	health = 50;
	dead = 0;
}

void Enemy::Attack() {

}
//test for bullet collision in main program, call if true
void Enemy::IsHit() {
	health = health - 10;
	if (health = 0);
		this->IsDead();
	
}

void Enemy::IsDead() {

}

void Enemy::Move() {
	enemypos.y = enemypos.y + speed;
	enemysprt.setPosition(enemypos.x, enemypos.y);
	if(enemypos.y < 0){
		cout << "entering reverse function" << endl;
		speed = -speed;
	}
	else if(enemypos.y > 700)
		speed = -speed;

}

int Enemy::GetHealth() {return health;}
