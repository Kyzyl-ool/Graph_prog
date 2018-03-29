#include <SFML/Graphics.hpp>

void sfInitWindow(unsigned int width, unsigned int height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Works!");
	
	sf::Image kitty;
	kitty.loadFromFile("images/kitty.png");
	
	sf::Texture kitty_texture;
	kitty_texture.loadFromImage(kitty);
	
	sf::Sprite kitty_sprite;
	kitty_sprite.setTexture(kitty_texture);
	kitty_sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
	kitty_sprite.setPosition(50, 50);
	
	 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {kitty_sprite.move(-0.1, 0);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {kitty_sprite.move(0.1, 0);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {kitty_sprite.move(0, 0.1);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {kitty_sprite.move(0, -0.1);}
		
		window.clear();
		window.draw(kitty_sprite);
		window.display();
	}
}
