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
	//added enemy attack definitions 
	BulletSpeed = 50;
	bulletTexture.loadFromFile("Images/EnemyBullet.png");
	MaxBullets = 3;

	attackTime = .1f;
	
}

std::vector<Bullet> &Enemy::getBullets() { return EnemyBullets; }

void Enemy::Attack() {
if (ReloadTimer.getElapsedTime().asSeconds() > attackTime && EnemyBullets.size() < MaxBullets ) { 
	Bullet Enemy::Bullet(sf::Vector2f EnemyPosition, sf::Vector2f Player) {
	float x, y, xVel, yVel, mag;
	x = std::abs(player.getPosition().x - boss.getPosition.x);
	y = std::abs(player.getPosition().y - boss.getPosition.y);
	mag = sqrt(x*x+y*y);
	xVel = (x / mag) *  BulletSpeed;
	yVel = (y / mag) *  BulletSpeed;
	return Bullet(bulletTexture, sf::Vector2f(xVel, yVel));
}
	ReloadTimer.restart(); //reloads ammo
}

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
