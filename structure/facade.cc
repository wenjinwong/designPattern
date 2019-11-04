#include<iostream>


class scanner {
	public:
		scanner(istream &i) {}
		virtual ~scanner() { }

		virtual token& scan() {}
	private:
		istream &_inputStream;
};


class Parser {
	public:
		Parser() {} 
		virtual ~Parser() { }

		virtual void parse(scanner& s, programNodeBuilder& p) {}
};


class complier {
	public:
		complier() {}

		virtual void complie(istrem &, bytecodestream&);
}

void complier::compile(istream&input, bytecodestream& output) {
	scanner sc(input);
	programNodeBuilder builder;
	parser ps;

	ps/parse(scanner, builder);
	risccodegenenrator generator(output);
	programNode *parsetree = builder.getrootnode();
	parsetree->traverse(generator);
}
