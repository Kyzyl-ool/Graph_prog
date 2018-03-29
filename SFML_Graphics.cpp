#include <SFML/Graphics.hpp>

void sfInitWindow(unsigned int width, unsigned int height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);
 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		window.draw(shape);
		window.display();
	}
}
