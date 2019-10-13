// Composite.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point() {
		x = 0;
		y = 0;
	}
};

class Figure {
	Point origin;
	Point extent;
public:
	Figure() {}

	virtual void move(int a, int b) {
		origin.x = a;
		origin.y = b;
	}

	void size(int a, int b) {
		extent.x = a;
		extent.y = b;
	}

	virtual void draw() {
		cout << "(" << origin.x << ", " << origin.y << ") - " << "(" << extent.x << ", " << extent.y << ") - ";
	}
};

class Circle : public Figure {
public:

	Circle() {}
	void draw() {
		Figure::draw();
		cout << "circle\n";
	}
};

class Square : public Figure {
public:

	Square() {}
	void draw() {
		Figure::draw();
		cout << "square\n";
	}
};

class Paint : public Figure {
	Figure *figures[6];
	int count;
public:
	Paint() : count(0) {}

	// добавлениe новой фигуры 
	void add(Figure *f) {
		figures[count] = f;
		count++;
	}
	// добавление составного объекта
	void add(Figure *f[], int size) {
		for (int i = 0; i < size; i++) {
			figures[count] = f[i];
			count++;
		}
	}
	// рисование всех фигур 
	void draw() {
		for (int i = 0; i < count; i++) {
			figures[i]->draw();
		}
	}
	// получение фигуры 
	Figure* get(int index) {
		return figures[index];
	}
};

class PaintCol {
	Figure *collection[6];
	int cnt;
public:
	PaintCol() : cnt(0) {}

	// добавлениe новой фигуры 
	void add(Figure *f) {
		collection[cnt] = f;
		cnt++;
	}
	// рисование всех фигур 
	void draw() {
		for (int i = 0; i < cnt; i++) {
			collection[i]->draw();
		}
		printf("\n");
	}
	// получение фигуры 
	Figure* get(int index) {
		return collection[index];
	}
};
// класс - переходник
class FigureText : public Figure, public Text {
public:
	FigureText() : Figure(), Text() {	}

	void draw() {
		cout << "(" << x << ", " << y << ") - (" << GetW() << ", " << GetH() << ")";
		Text::OutText();
	}

	void move(int a, int b) {
		Text::SetLocation(a, b);
	}

};

int main()
{
	Paint * app = new Paint();
	/*app->add(new Paint());
	app->add(new Circle());
	app->add(new Circle());
	app->draw();*/
	app->add(new Circle);
	app->get(0)->move(1, 1);
	app->get(0)->size(2, 4);

	PaintCol * pc = new PaintCol();
	pc->add(new Circle);
	pc->add(new Square);
	pc->get(0)->move(1, 1);
	pc->get(0)->size(2, 4);
	pc->draw();

	app->draw();

	//app->add(new Circle());
	/*app->add(new Square());
	app->get(0)->move(1, 1);
	app->get(0)->size(2, 4);*/
	//app->get(1)->move(2, 2);
	//app->get(1)->size(4, 8);
	/*Figure * mas[2] = { new Circle,new Circle };
	app->add(mas, 2);

	Figure *f = new FigureText();
	Text *t = dynamic_cast<Text *>(f);

	t->setText("hello");

	f->draw();
	app->add(f);
	app->get(2)->move(7, 7);*/


	return 0;
}