#include<iostream>

class windowimp {
};


class xwindowimp :public  windowimp{
}:

class macwindowimp :public  windowimp{
}:


class window{
	private:
		windowimp *imp;
	public:
		windowjmp* getwindowimp() {
			if((imp == 0) {
				imp = windowfactory::instance()->makewindowimp();
			}
			return imp;
		}

};


class windowfactory{
public:
	windowimp *instance() { }
	};

class xwindow : public window {
	public:
};



