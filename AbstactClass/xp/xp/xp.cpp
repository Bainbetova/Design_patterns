// xp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

// интерфейсы
template <class T, int N>
class Collection {
	T a[N];
public:
	int count;
	Collection() {
		count = 0;
	}
	void add(T t) {
		a[count++] = t;
	}
	T operator [](int index) {
		return a[index];
	}
};

class Button {
public:
	Button() {}

	virtual void draw() { }
};

class Label {
public:
	Label() {}

	virtual void draw() { }
};

class Menu {
public:
	Menu() {}

	virtual void draw() { }
};

class Window {
	Menu *m;
public:

	Window() {}

	virtual void addMenu(Menu *menu) {}

	virtual void addButton(Button *button) {}

	virtual void addLabel(Label *label) {}

	virtual void draw() {}
};

class ButtonXP : public Button {

public:
	ButtonXP() {}

	void draw() {
		cout << "buttonxp\n";
	}
};

class LabelXP : public Label {

public:
	LabelXP() {}

	void draw() {
		cout << "labelxp\n";
	}
};

class MenuXP : public Menu {
public:
	MenuXP() {}

	void draw() {
		cout << "menuxp\n";
	}
};

class WindowXP : public Window {
	Collection<ButtonXP*, 10> bt;
	Collection<LabelXP*, 10> lbl;
	Collection<MenuXP*, 10> mn;
public:
	WindowXP() {}

	void addMenu(MenuXP *menuxp) {
		mn.add(menuxp);
	}

	void addButton(ButtonXP *buttonxp) {
		bt.add(buttonxp);
	}

	void addLabel(LabelXP *labelxp) {
		lbl.add(labelxp);
	}

	void draw() {
		cout << "windowxp\n";
		for (int i = 0; i < bt.count; i++) {
			bt[i]->draw();
		}
		for (int i = 0; i < lbl.count; i++) {
			lbl[i]->draw();
		}
		for (int i = 0; i < mn.count; i++) {
			mn[i]->draw();
		}
	}
};

class ApplicationXP {
	WindowXP *windows[10];
	int cnt;
public:
	ApplicationXP() : cnt(0) {}

	void add(WindowXP *windowxp) {
		windows[cnt] = windowxp;
		cnt++;
	}

	void draw() {
		cout << "applicationxp\n";
		for (int i = 0; i < cnt; i++) {
			windows[i]->draw();
		}
		printf("\n");
	}

	WindowXP *get(int index) {
		return windows[index];
	}
};

class ButtonPM : public Button {

public:
	ButtonPM() {}

	void draw() {
		cout << "buttonpm\n";
	}
};

class LabelPM : public Label {

public:
	LabelPM() {}

	void draw() {
		cout << "labelpm\n";
	}
};

class MenuPM : public Menu {

public:
	MenuPM() {}

	void draw() {
		cout << "menupm\n";
	}
};

class WindowPM : public Window {
	Collection<ButtonPM*, 10> bt;
	Collection<LabelPM*, 10> lbl;
	Collection<MenuPM*, 10> mn;
public:
	WindowPM() {}

	void addMenu(MenuPM *menupm) {
		mn.add(menupm);
	}

	void addButton(ButtonPM *buttonpm) {
		bt.add(buttonpm);
	}

	void addLabel(LabelPM *labelpm) {
		lbl.add(labelpm);
	}

	void draw() {
		cout << "windowpm\n";
		for (int i = 0; i < bt.count; i++) {
			bt[i]->draw();
		}
		for (int i = 0; i < lbl.count; i++) {
			lbl[i]->draw();
		}
		for (int i = 0; i < mn.count; i++) {
			mn[i]->draw();
		}
	}
};

class ApplicationPM {
	WindowPM *windows[10];
	int cnt;
public:
	ApplicationPM() : cnt(0) {}

	void add(WindowPM *windowpm) {
		windows[cnt] = windowpm;
		cnt++;
	}

	void draw() {
		cout << "applicationpm\n";
		for (int i = 0; i < cnt; i++) {
			windows[i]->draw();
		}
		printf("\n");
	}

	WindowPM *get(int index) {
		return windows[index];
	}
};


class Creater {
public:
	Creater() {}
	virtual Window *create_window() = 0;
	virtual Menu *create_menu() = 0;
	virtual Button *create_button() = 0;
	virtual Label *create_label() = 0;
};

class CreaterXP : public Creater {
public:
	Window * create_window() { return new WindowXP(); }
	Menu * create_menu() { return new MenuXP(); };
	Button * create_button() { return new ButtonXP(); };
	Label * create_label() { return new LabelXP(); };
};

class CreaterPM : public Creater {
public:
	Window * create_window() { return new WindowPM(); }
	Menu * create_menu() { return new MenuPM(); };
	Button * create_button() { return new ButtonPM(); };
	Label * create_label() { return new LabelPM(); };
};

class Application {
	/*  Elements<Creater*, 10> cr;
	Elements<Window*, 10> win;
	Elements<Menu*, 10> m;*/
	Creater * cr;
	Window *win[10];
	Menu *m[10];
	int cnt_win;
public:
	Application(Creater *c) {
		cr = c;
		cnt_win = 0;
	}

	Window * addWindow() {
		Window * w = cr->create_window();
		win[cnt_win] = w;
		cnt_win++;
		return w;
	}

	Window *getWindow(int index) {
		return win[index];
	}

	Menu *createMenu() {
		return cr->create_menu();
	}

	Button *createButton() {
		return cr->create_button();
	}

	Label *createLabel() {
		return cr->create_label();
	}

	void draw() {
		cout << "application\n";
		for (int i = 0; i < cnt_win; i++) {
			win[i]->draw();
		}
		printf("\n");
	}
};



int main() {
	CreaterXP * cxp = new CreaterXP();
	Application *app = new Application(cxp);
	Window * w = app->addWindow();
	w->addMenu(app->createMenu());
	w->addButton(app->createButton());
	app->draw();
	return 0;
}