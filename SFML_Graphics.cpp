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
	kitty_sprite.setPosition(20, 50);
	
	 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(kitty_sprite);
		window.display();
	}
}
