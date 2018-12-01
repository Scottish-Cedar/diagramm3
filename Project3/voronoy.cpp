#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;

const int N = 10;
const int H = 500;
clock_t t2 = 0, t1 = 0;
vector<pair<int, int>> vsp(N);
vector <pair<int, int>> v3(1000);

bool func(int x, int y, int x0, int y0, int x1)
{
	if ((x1 - x)*(x1 - x) == (y0 - y)*(y0 - y)*(x0 - x)*(x0 - x))
	{
		return true;
	}
	else return false;
}

int main()
{
	t1 = clock();
	t2 = t1;
	int j1 = 0;
	int i = 0;
	while (i < N)
	{
		vsp[i] = make_pair(7 * i*i - 43 * i + 205, 5 * i*i - 26 * i + 208);
		cout << vsp[i].first << ' ' << vsp[i].second << endl;
		i++;
	}
	sort(vsp.begin(), vsp.end());
	i = 0;
	while (i < N)
	{
		cout << vsp[i].first << ' ' << vsp[i].second << endl;
		i++;
	}
	i = 0;
	sf::VertexArray line(sf::Lines, 2 * N);
	while (i < N)
	{
		line[j1].position = sf::Vector2f(vsp[i].first, 0);
		line[j1 + 1].position = sf::Vector2f(vsp[i].first, 499);
		line[j1].color = sf::Color::Transparent;
		line[j1 + 1].color = sf::Color::Transparent;
		i++;
		j1 += 2;
	}
	j1 = 0;
	i = 8;
	vector <pair<int, int>>  coord(H);
	int p = 0;
	int y = 0;
	int x = 0;
	int x1 = vsp[i+1].first;
	cout << x1 << endl;
	int x0 = vsp[i].first;
	cout << x0 << endl;
	int y0 = vsp[i].second;
	cout << y0 << endl;
	while (y < H)
	{
		while (x < x1)
		{
			if (func(x, y, x0, y0, x1))
			{
				cout << "nice!" << endl;
				cout << "x=" << x << " " << "y=" << y << endl;
				coord[p].first = x;
				coord[p].second = y;
				p++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	
	sf::RenderWindow window(sf::VideoMode(H, H), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		sf::VertexArray spot(sf::Points, N);
		i = 0;
		while (i < N)
		{
			spot[i].position = sf::Vector2f(vsp[i].first, vsp[i].second);
			spot[i].color = sf::Color::Red;
			i++;
		}
		window.draw(spot);

		sf::VertexArray parab(sf::Points, p);
		i = 0;
		while (i < p)
		{
			parab[i].position = sf::Vector2f(coord[i].first, coord[i].second);
			parab[i].color = sf::Color::Magenta;
			i++;
		}
		window.draw(parab);

		sf::VertexArray line(sf::Lines, 2);
		line[0].position = sf::Vector2f(vsp[j1].first, 0);
		line[1].position = sf::Vector2f(vsp[j1].first, H-1);
		line[0].color = sf::Color::Cyan;
		line[1].color = sf::Color::Cyan;
		window.draw(line);
		t2 = clock();
		if (t2 - t1 > 200) {
			t1 = t2;
			if (j1 < 9)
			{
				j1 += 1;
			}
			else
			{
				j1 = 0;
			}
		}
		window.display();
	}
	return 0;
}