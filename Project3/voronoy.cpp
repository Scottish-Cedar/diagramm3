#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

const int N = 10;
vector<pair<int, int>> vsp(N);
vector<int> valg(N);

int main()
{
	int j1 = 0;
	//int j2 = 0;
	int i = 0;
	while (i < N)
	{
		vsp[i] = make_pair(7 * i*i - 43 * i + 205, 5 * i*i - 26 * i + 208);
		cout << vsp[i].first << ' ' << vsp[i].second << endl;
		i++;
	}
	i = 0;
	while (i < N)
	{
		valg[i] = vsp[i].first;
		i++;
	}
	sort(valg.begin(), valg.end());
	i = 0;
	while (i < N)
	{
		cout << valg[i] << endl;
		i++;
	}
	i = 0;
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear();
		
		sf::VertexArray line(sf::Lines, 2 * N);
		i = 0;
	while (i < N )
	{
		line[j1].position = sf::Vector2f(valg[i], 0);
		line[j1 + 1].position = sf::Vector2f(valg[i], 499);
		line[j1].color = sf::Color::Cyan;
		line[j1 + 1].color = sf::Color::Cyan;
		window.draw(line);
		//system("pause");
		line[j1].color = sf::Color::Black;
		line[j1 + 1].color = sf::Color::Black;
		window.draw(line);
		if (j1!=18)
		j1 += 2;
		i++;
	}
	sf::VertexArray spot(sf::Points, N);
	i = 0;
	while (i < N)
	{
		spot[i].position = sf::Vector2f(vsp[i].first, vsp[i].second);
		spot[i].color = sf::Color::Red;
		i++;
	}
	window.draw(spot);
	window.display();
	}
	return 0;
}