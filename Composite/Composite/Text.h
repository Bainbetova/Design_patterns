// Text.h
#include <iostream>
using namespace std;

// ����� ��� ������ � ��������� �������
class Text {
protected:
	// �����
	string text;
	// ������ ������
	int len;
	// ���������
	int x, y;
	// ������
	int w, h;
public:
	// ����������� �� ���������
	Text() : x(0), y(0), w(0), h(0) {}
	// ����������� ����������
	Text(string T) {
		setText(T);
	}
	// ������������� �����
	void setText(string T) {
		text = T;
	}
	// ���������� �����
	string getText() {
		return text;
	}
	// ������������� ���������
	void SetLocation(int X, int Y) {
		x = X;
		y = Y;
	}
	// ���������� ���������
	int GetX() {
		return x;
	}
	// ���������� ���������
	int GetY() {
		return y;
	}
	// ���������� ������ ������
	int GetW() {
		return text.length();
	}
	// ���������� ������ ������
	int GetH() {
		return 1;
	}
	// ������� �����
	void OutText() {
		cout << text.c_str() << endl;
	}
};