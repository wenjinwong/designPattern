#include<iostream>

#define CAP 128
template<class Item>
class List {
	list(long size = CAP);

	long Count() const;
	Item& Get(long index) const;
	//...
};


template<class Item>
class Iterator {
	public:
		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isdone() const = 0;
		virtual Item currentItem() const = 0;
	protected:
		Iterator();
};

template<class Item>
class ListIterator : public Iterator<Item> {
	public:
		ListIterator(const List<Item> *alist);
		virtual void fitst();
		virtual void next();
		virtual bool isdone() const;
		virtual Item currentItem() const;
	private:
		const List<Item> *_list;
		long _current;
};


template<class Item>
ListIterator<Item>::ListIterator(const List<Item> *alist) : _list(alist), _current(0) { }

template<class Item>
void ListIterator::fitst() { 
	_current = 0;
}

template<class Item>
void ListIterator<Item>::next() {
	_current++;
}

template<class Item>
bool ListIterator<Item>::IsDone() const {
	return _current >= _list->Count();
}


template<class Item>
bool ListIterator<Item>::currentItem() const {
	if(IsDone()) {
		throw IteratorOutOfBounds;
	}
	return _list->Get(_current);
}



