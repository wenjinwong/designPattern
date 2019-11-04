class a{
	public:
		void f() { }
};

class b{ public: void  f() {} };

class c : public a, public b { };

int 
main()
{
	c cc;
	cc.f();
}
