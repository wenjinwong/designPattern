#include<iostream>


class shape {
	public:
		shape() {}
		virtual void boundingbox( 
				point& bottmleft, point& topright
				) const {
			;
		}

		virtual manipulator *createmanipulator() const { ; }
};


class textview {
	public:
		textview() { ; }
		void getorigin(coord &x, coord &y) const { ; }
		void getextent(coord &width, coord& height) const { ; }
		virtual book isempty() const { ; }
};


class textshape : public shape, private textview {
	public:
		textshape() { ; }

		virtual void boundingbox(point& bottomleft, point& topright
				) const { ; }
		virtual bool isempty() const { ; }
		virtual manipulator* createamnipulator() const { ; }
};

void textshape::boundingbox(point &bottomleft, point& topright) const {
	coord bottom, left , width, height;

	GetOrigin(bottom, left);
	getextent(width, height);

	bottomleft = point(bottom, left);
	topright = point(bottom + height, left + right);
}


bool Textshape::isempty () const {
	return textview::isempty();
}

manipulator *textshape::createmanipulator() const {
	return new textmanipulator(this);
}


class textShape : public shape {
	public:
		textshape(textview *);
		virtual coid boundingbox ...
		;
		virtual bool isempty() const ;
		virtual manipulator* createmanipulator() const ;
	private:
		textview* _text;
};


