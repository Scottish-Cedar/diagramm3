#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

sf::VertexArray spots(int i)
{
		sf::VertexArray spot(sf::Points, 1);
		spot[0].position = sf::Vector2f(7*i*i-43*i+205.f, 5*i*i-26*i+208.f);
		spot[0].color = sf::Color::Red;
		return spot;
}

int main()
{
	int i = 0;
	int j = 0;
	cin >> i;
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	
	/*sf::VertexArray spot(sf::Points, 1);
	spot[0].position = sf::Vector2f(10.f, 10.f);
	spot[0].color = sf::Color::Red;*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		while (j <= i)
		{
			j++;
			window.draw(spots(j));
			window.display();
			
		}
		
	}
	return 0;
}