#include "Game.h"
#include <iostream>
Game::Game()
{
	// ���������� ����� ��� ��������� ���������
	font.loadFromFile("resources/sansation.ttf");
	Init();
}

void Game::Init()
{
	// ��������� ������ ������
	for (int i = 0; i < ARRAY_SIZE; i++) elements[i] = i + 1;
	// ������ ������ ������ � ������ ������ �������
	empty_index = ARRAY_SIZE;
	elements[empty_index] = 0;	// ������ ������ ����� �������� = 0
	solved = false;
}
bool Game::Check(Direction direction)
{
		elementost1 = element1;
		elementost2 = element2;
		//if (elementost1 == element1 && elementost2 == element2) {
			c++;
			if (c % 2 == 0) {
				return false;
			}
			if (c % 2 != 0) {
				return true;
			}
		//}
}
	
	/*sf::RenderWindow window(sf::VideoMode(600, 600), "15");
	window.setFramerateLimit(60);
	sf::Event event;
	while (window.pollEvent(event)) {
		// �������� ����������� �����������
		for (unsigned int i = 0; i < ARRAY_SIZE; i++)
		{
			if (elements[i] > 0 && elements[i] != i + 1) return false;
		}
		return true;
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) return true;
		else
			return false;
	}*/

void Game::Move(Direction direction)
{

	//sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
		//shape.setOutlineThickness(2.f);
		// ��������� ������ � ������� ������ ������
	// �������� �� ����������� ����������� � ���������� ������� ������������ ������
	int move_index = -1;
	if (direction == Direction::Left && element1 > 1) element1 = element1 - 8;
	if (direction == Direction::Right && element1 < 27) element1 = element1 + 8;
	if (direction == Direction::Up && element2 > 1) element2 = element2 - 8;
	if (direction == Direction::Down && element2 < 27) element2 = element2 + 8;
	if (direction == Direction::Paint) solved = Check(direction);
	//elementost1 = element1;
	//elementost2 = element2;
	// ����������� ������ �� ����� ������
}
/*void Game::Paint(sf::RenderTarget& target, sf::RenderStates states) const {
	if (solved)
	{
		sf::Color color = sf::Color(200, 100, 200);
		//shape.setOutlineColor(color);
		sf::RectangleShape shost(sf::Vector2f(CELL_SIZE, CELL_SIZE));
		//cout << solved;
		//sf::Vector2f position(i / CELL_SIZE + 10.f, i / CELL_SIZE + 10.f);
		//shape.setPosition(position);
		sf::Vector2f position(elementost1 * 10.f, elementost2 * 10.f);
		shost.setPosition(position);
		shost.setOutlineColor(color);
		target.draw(shost, states);
		//shape.setOutlineColor(sf::Color::Cyan);
		// �������� ����������� �������� ������ ������

	//text.setFillColor(sf::Color::Cyan);
	}
}*/
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);
	sf::Color color2 = sf::Color(100, 150, 100);
	// ������ ����� �������� ����
	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	// �������������� ����� ��� ��������� ���� ������
	shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	// �������������� ��������� ��������� ��� ��������� ������� ������
	sf::Text text("", font, 52);
	sf::RectangleShape sh(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	//sf::RectangleShape shost(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		//sf::RectangleShape pl(sf::Vector2f(SIZE, SIZE));
		sf::Vector2f position(i / CELL_SIZE + element1 * 10.f, i / CELL_SIZE + element2 * 10.f);
		sh.setPosition(position);
		//sh.setOutlineColor(sf::Color::Cyan);
		//sf::RectangleShape shost(sf::Vector2f(CELL_SIZE, CELL_SIZE));
		target.draw(sh, states);
		if (solved)
		{
			sf::RectangleShape shost(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			//sf::Vector2f position(i / CELL_SIZE + 10.f, i / CELL_SIZE + 10.f);
			//shape.setPosition(position);
			sf::Vector2f position(elementost1*10.f, elementost2*10.f);
			shost.setPosition(position);
			shost.setOutlineColor(color);
			target.draw(shost, states);
			shape.setOutlineColor(sf::Color::Cyan);
			// �������� ����������� �������� ������ ������

		//text.setFillColor(sf::Color::Cyan);
		}
		//target.draw(shost, states);
		//if (solved ) {
			//shost.setOutlineColor(color);
			//shape.setOutlineColor(sf::Color::Transparent);
		//}
		//else if (elements[i] == i + 1)
		//{
			// ������ ������ �� ����� ������ �������� ������
			//text.setFillColor(sf::Color::Green);
		//}

		// ������ ��� ������, ����� ������
		if (elements[i] > 0){
			sf::Vector2f position(i % SIZE * CELL_SIZE + 10.f, i / SIZE * CELL_SIZE + 10.f);
		    shape.setPosition(position);
			// ������� ������ �������� �������
		// ���������� ������� ������ ��� ���������
		    text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
		    target.draw(shape, states);
		    target.draw(text, states);
		}

	}
}