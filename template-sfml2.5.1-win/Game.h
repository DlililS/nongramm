#pragma once
#include <SFML/Graphics.hpp>

const int SIZE = 5;						// ������ �������� ���� � �������
const int ARRAY_SIZE = SIZE * SIZE;		// ������ �������
const int FIELD_SIZE = 500;				// ������ �������� ���� � ��������
const int CELL_SIZE = 80;				// ������ ������ � ��������

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3, Paint = 4 };

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	int elements[ARRAY_SIZE];
	int c = 0;
	int elem1 = 0;
	int elem2 = 0;
	int element1 = 1;
	int element2 = 1;
	int elementost1 = element1;
	int elementost2 = element2;
	int empty_index;
	bool solved;
	sf::Font font;
public:
	Game();
	void Init();
	bool Check(Direction direction);
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//virtual void Paint(sf::RenderTarget& target, sf::RenderStates states) const;
};