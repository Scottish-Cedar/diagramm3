#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

sf::VertexArray spots(int i, int j)
{
		sf::VertexArray spot(sf::Points, 1);
		spot[0].position = sf::Vector2f(i,j);
		spot[0].color = sf::Color::Red;
		return spot;
}

const int N = 10;
vector<pair<int, int>> v1(N);


int main()
{
	
	int i = 0;
	while (i < N)
	{
		v1[i] = make_pair(7 * i*i - 43 * i + 205, 5 * i*i - 26 * i + 208);
		cout << v1[i].first <<' '<< v1[i].second<<endl;
		i++;
	}
	i = 0;
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		while (i < N)
		{
			window.draw(spots(v1[i].first, v1[i].second));
			window.display();
			i++;
		}
		
	}
	return 0;
}