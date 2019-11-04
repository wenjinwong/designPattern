class equipment {
	public:
		const char* name() { return _name; }
		virtual void add();
		virtual void remove();

		virtual void power();
		virtual currency netprice();
		...
	private:
		const char* _name;
};


class disk : public equipment{
};

class composite : public equipment {
	public:
		for_each();
	private:
		list<equipment*> _equipment;
		iter* createiterator();
};

class chassis : public composite {
};

int 
main()
{
	chassis ct = new chassis("pc");
	disk* d = new disk("disk");
	cabinet cab = new cabinet("cabinet");
	cab.->add(ct);
	cab->add(d);
	...
}
