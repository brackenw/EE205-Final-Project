#include<SFML/Graphics.hpp>

class Bullet {
	private:
		bool active;

	public:
		sf::CircleShape shape;
		Bullet();
		void Shoot(const sf::Vector2f & vect);
		void MakeActive();	
};
