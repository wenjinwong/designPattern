#include<iostream>


class visualComponent {
	public:
		void draw() {}
		visualComponent() {}
		virtual void resize() { }
};


class decorator : public visualComponent {
	public:
		decorator(visualComponent *v) { }

		virtual void draw() {_component->draw(); }
		virtual void resize() { _component->resize() ; }

		//...
	private:
		visualComponent *_component;
};


class borderdecorator : public decorator {
public:
	borderdecorator(visualComponent *v, int borderwidth) { }

virtual void draw() ;
private:
	void drawborder(int);
	private:
	int width;
};

void borderdecorator::draw() {
	decorator::draw();
	draw(width);
}


int 
test() {
	window *w = new window;
	textview t = new textview;
	window->setcontent(new borderdecorator(textview), 1) );
