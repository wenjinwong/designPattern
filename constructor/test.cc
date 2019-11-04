#include<iostream>


class test{
	public:
		virtual void say() const { std::cout << "test" << std::endl; }
};


class test1 : public test{
	public:
		void say() const { std::cout << "test 1" << std::endl; }
};


class factory{
	public:
		test *t;
		test make() { return *t; }
};

int
main()
{
	factory f;
	f.t = new test1();
	f.t->say();

	test1 tmp = f.make();
	tmp.say();
}
