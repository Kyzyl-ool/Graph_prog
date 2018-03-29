#include <SFML/Graphics.hpp>
#include <iostream>

void sfInitWindow(unsigned int width, unsigned int height)
{
	float Current_frame = 0;
	sf::Clock clocks;
	
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Works!");
	
	sf::Image kitty;
	kitty.loadFromFile("images/hero.png");
	
	sf::Texture kitty_texture;
	kitty_texture.loadFromImage(kitty);
	
	sf::Sprite kitty_sprite;
	kitty_sprite.setTexture(kitty_texture);
	kitty_sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
	kitty_sprite.setPosition(50, 50);
	kitty_sprite.setScale(2, 2);
	
	 
	while (window.isOpen())
	{
		float time = clocks.getElapsedTime().asMicroseconds();
		clocks.restart();
		time /= 300;
		//~ std::cout << time << std::endl;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		
		#define dt 0.0025
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty_sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 96, 96, 96));
			kitty_sprite.move(-0.1*time, 0); 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{	
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty_sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 192, 96, 96));
			kitty_sprite.move(0.1*time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty_sprite.move(0, 0.1*time);
			kitty_sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 0, 96, 96));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty_sprite.move(0, -0.1*time);
			kitty_sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 288, 96, 384));
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {kitty_sprite.setColor(sf::Color::Red);}
		else kitty_sprite.setColor(sf::Color::White);
		
		window.clear();
		window.draw(kitty_sprite);
		window.display();
	}
}
