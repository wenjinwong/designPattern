#include<iostream>


class composition {
	public:
		composition(compositor *);
		void repair();

	private:
		compositor* _compositor;
		component* _component;
		int _componentCount;
		int _lineWidth;
		int *_lineBreaks;			// the position of linebreaks in
									//component

		int _lineCount;
};


class compositor {
	public:
		virtual int compose(
				coord natural[], coord stretch[], coord shrink[],
				int componentCount, int lineWidth, int breaks[]) = 0;
	protected:
		compositor();
};


void composition :: repair() {
	coord* naturl;
	coord* strechability;
	coord* sharinkability;
	int componentCount;
	int *breaks;

	//prepare the arrays with the desired component sizes
	//...
	
	//determine where the breaks are:
	int breakCounts;
	breakCounts = _compositor->compose(naturl, strechability,
			sharinkability, componentCount, _lineWidth, breaks);

	// lay out components according to breaks
	// ...

};


class simplecompositor : public compositor { 
	public:
		simplecompositor();

		virtual int compost(...);
		//

};

classs texcompositor : public compositor { 
	public:
		texcompositor() ;

		virtual int compose (...);
};



compositon *quick = new composition(new simplecompositor);
composition* iconic = new composition(new texcompositor);


