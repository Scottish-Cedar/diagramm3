/*#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::CircleShape shape(200.f);
	shape.setFillColor(sf::Color(123,945,191));
	shape.setOutlineThickness(-198.f);
	shape.setOutlineColor(sf::Color::Yellow);
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
	cout<<"git works";
	return 0;
}*/