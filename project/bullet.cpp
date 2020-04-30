#include"bullet.hpp"


Bullet::Bullet() {
	shape.setRadius(10);
	shape.setFillColor(sf::Color::Red);
}

void Bullet::Shoot(const sf::Vector2f & vect) {
//	shape.setPosition(vect);
	shape.move(10, 0);
}
