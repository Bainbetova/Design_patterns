// Text.h
#include <iostream>
using namespace std;

// Класс для работы с текстовой строкой
class Text {
protected:
	// текст
	string text;
	// размер текста
	int len;
	// положение
	int x, y;
	// размер
	int w, h;
public:
	// конструктор по умолчанию
	Text() : x(0), y(0), w(0), h(0) {}
	// конструктор приведения
	Text(string T) {
		setText(T);
	}
	// устанавливает текст
	void setText(string T) {
		text = T;
	}
	// возвращает текст
	string getText() {
		return text;
	}
	// устанавливает положение
	void SetLocation(int X, int Y) {
		x = X;
		y = Y;
	}
	// возвращает положение
	int GetX() {
		return x;
	}
	// возвращает положение
	int GetY() {
		return y;
	}
	// возвращает ширину текста
	int GetW() {
		return text.length();
	}
	// возвращает высоту текста
	int GetH() {
		return 1;
	}
	// выводит текст
	void OutText() {
		cout << text.c_str() << endl;
	}
};