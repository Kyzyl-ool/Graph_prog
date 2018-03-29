#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>

typedef enum directions
{
	left,
	right,
	down,
	up
} direction;

class Player
{
private:
	
	
public:
	float x, y, w, h, dx, dy, speed;
	direction dir;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	
	
	Player(sf::String filename, float x, float y, float w, float h);
	~Player();
	
	void update();
};

Player::Player(sf::String filename, float x, float y, float w, float h):
x(x),
y(y),
w(w),
h(h)
{
	File = filename;
	image.loadFromFile("images/" + File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
}

Player::~Player()
{
	
}

void Player::update()
{
	switch (dir)
	{
		case left: dx = -speed; dy = 0; break;	//влево
		case right: dx = speed; dy = 0; break;	//вправо
		case up: dx = 0; dy = -speed; break;	//вверх
		case down: dx = 0; dy = speed; break;	//вниз
		default: assert(!"FATAL ERROR");
	}
	
	x += dx;
	y += dy;
	
	sprite.setPosition(x, y);
}

void sfInitWindow(unsigned int width, unsigned int height)
{
	float Current_frame = 0;
	sf::Clock clocks;
	Player kitty("hero.png", 50, 50, 2, 2);
	
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML Works!");
	
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
			kitty.dir = left;
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty.sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 96, 96, 96));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{	
			kitty.dir = right;
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty.sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 192, 96, 96));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			kitty.dir = down;
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty.sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 0, 96, 96));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			kitty.dir = up;
			Current_frame += time*dt;
			if (Current_frame > 3) Current_frame -= 3;
			kitty.sprite.setTextureRect(sf::IntRect(96*int(Current_frame), 288, 96, 384));
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {kitty.sprite.setColor(sf::Color::Red);}
		else kitty.sprite.setColor(sf::Color::White);
		
		window.clear();
		kitty.update();
		window.draw(kitty.sprite);
		window.display();
	}
}
