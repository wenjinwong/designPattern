#include<iostream>




int 
main(void)
{
	;
}


class booleanexp {
	public:
		booleanexp();
		virtual ~booleanexp();

		virtual bool evalute(context&) = 0;
		virtual booleanexp* replace(const char *, booleanexp &) = 0;
		virtual booleanexp* copy() const = 0;
};


class context {
	public:
		bool lookup(const char *) const;
		voir assign(varibleexp *, bool);
};

class varibleexp : public booleanexp {
	public:
		varibleexp(const char *);
		virtual ~varibleexp();

		virtaul bool evalute(context &);
		virtual booleanexp* replace(const char *, booleanexp &);
		virtual booleanexp* copy() const ;
	private:
		char *_name;
};

varibleexp::varibleexp(const char *name) {
	_name = strdup(name);
}

bool varibleexp::evalute(context& acontext) {
	return acontext.lookup(_name);
}

booleanexp *varibleexp::copy() const {
	return new varibleexp(_name);
}

booleanexp* varibleexp::replace(const char *name, booleanexp &exp) {
	if(strcmp(name, _name) == 0) {
		return exp.copy();
	}else {
		return new varibleexp(_name);
	}
}


class andexp : public booleanexp {
	public:
		andexp(booleanexp*, booleanexp *);
		virtual ~andexp();

		virtual bool evalute(context&);
		virtual booleanexp* replace(const char *, booleanexp&);
		virtual booleanexp* copy() const ;
	private:
		booleanexp *_operand1;
		booleanexp *_operand2;
};

andexp::andexp(bool *op1, booleanexp *op2) {
	_operand1 = op1;
	_operand2 = op2;
}


bool andexp::evalute(context& acontext) {
	return _operand1->evalute(acontext) && _operand2->evalute(acontext);
}

booleanexp* andexp::copy() const {
	return new andexp(_operand1->copy(), _operand2->copy());
}

booleanexp* andexp::replace(const char* name, booleanexp& exp) {
	return new andexp(_operand1->replace(name, exp),
			_operand2->replace(name, exp) );
}

(true and x) or (y and (not x))

booleanexp *expression;

context context;
variableexp *x = new variableexp("x");
variableexp *y = new variableexp("y");

expression = new orexp(new andexp(new constant(true), x), new andexp(y, new notexp(x)) );

context.assign(a. false);
context.assign(y, true);

bool result = expression->evalute(context);



