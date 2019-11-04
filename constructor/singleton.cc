#include<iostream>


class singleton {
	public:
		static singleton *instance() {
			if(!_instance) {
				_instance = new singleton;
			}
			return _instance;
		}
	protected:
		singleton()  {}
	private:
		static singleton *_instance;
};


singleton *singleton::_instance = 0;


// if not exist, then create it.








int 
main() 
{
	std::cout << singleton::instance();
}



