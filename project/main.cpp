#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"player.hpp"
#include"enemy.hpp"
int main() {
	//create window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Bullet Hell");
	window.setFramerateLimit(60);
	//background images
	sf::Texture ground;
	sf::Sprite bg;
	sf::Sprite bg2;
	float bgspeed = -6;

	ground.loadFromFile("ground.png");
	bg.setTexture(ground);
	bg2.setTexture(ground);
	bg.setScale(1, 1);
	bg2.setScale(1, 1);
	bg.setPosition(0,0);
	bg2.setPosition(768,0);
	
	//initialize health bar
	int healthx = 600;
	int healthy = 35;
	sf::RectangleShape healthBar;
	healthBar.setSize(sf::Vector2f(healthx, healthy));	

	//player
	Player player;
	Enemy boss;
	//Start main game loop
	while(window.isOpen()) {
	//while game window is active check for kb or mouse action
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type)
			{
				case sf::Event::Closed: 
					window.close();
					break;
				case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						{
							player.SetDirection(event.key.code);
							player.Move();
							window.draw(player.playersprt);
						}
			
			}
		}
	//moves the background and repeats it
		bg.move(bgspeed, 0);
		bg2.move(bgspeed,0);
		if (bg.getPosition().x < -768) {
			bg.setPosition(768, 0);
		}
		if(bg2.getPosition().x < -768) {
			bg2.setPosition(768, 0);
		}
		boss.Move();
		if (player.hit) {
			healthx = healthx - 60;
			player.IsHit();
			healthBar.setSize(sf::Vector2f(healthx, healthy));	
		}
	//clears window
		window.clear();
	
	//refreshes display of everything
		window.draw(bg);
		window.draw(bg2);
		window.draw(healthBar);
		window.draw(player.playersprt);
		window.draw(boss.enemysprt);
		window.display();
	}
}
