class elem {
	public:
		int value;
};

class factory{
	public:
		elem *createElem() { return new elem; }
};
