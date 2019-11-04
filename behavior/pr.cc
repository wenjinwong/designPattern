#include<iostream>


class typea{
	public:
		typea() { std::cout << "a" <<std::endl;
		}
		typea* clone() { return new  typea(*this); }
};

class deriveda :public typea {
	public:
		deriveda() { std::cout << "da" << std::endl; }
		deriveda* clone() { return new  deriveda(*this); }
};


class base{
	public:
		typea *a;
};


int 
main() {
	typea *a = new deriveda;
	deriveda* da = a->clone();
}
