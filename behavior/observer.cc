#include<iostream>
#include<list>

class subject;


class observer {
	public:
		virtual ~observer();
		virtual void update(subject *thechangedsubject) = 0;
	protected:
		observer();
};


class subject {
	public:
		virtual ~subject();

		virtual void attach(observer *);
		virtual void detach(observer *);
		virtual void notify();

	protected:
		subject();
	private:
		List<observer*> *_observers;
};

void subject::attach(observer *o) {
	_observers->push_back(o);
}

void subject::detach(observer *o) {
	_observers->remove(o);
}

void subject::notify() {
	ListIterator<observer*> i(_observers);
	for(i.first(); !i.isdone(); i.next() ) {
		i.currentItem()->update(this);
	}
}

class clockTimer : public subject {
	public : 
		clockTimer();

		virtual int getHour();
		virtual int getMinute();
		virtual getSecond();

		void Tick();
};


void clockTimer::tick() {
	// update internal time-keeping state
	//
	notify();
}

class widget {
};


class digitalclock : public widget, public observer {
	public:
		digitalclock(clockTimer *);
		virtual ~digitalclock();

		virtual void update(subject*);
		// overrides observer operation
		//
		
		virtual void draw();
		// overrides widget operation;
		// defines how to draw the digital clock
	private:
		clockTimer *_subject;
};


digitalclock::digitalclock(clockTimer *s) {
	_subject = s;
	_subject->attach(this);
}


digitalclock::~digitalclock() {
	_subject->detach(this);
}


void digitalclock::update(subject* thechangedsubject) {
	if(thechangedsubject == _subject) {
		draw();
	}
}


void digitalclock::draw() {
	// get the newe calues from the subject 
	
	int hour = _subject->getHour();
	int minute = _subject->getMinute();
	//etc /
	
	//draw the digital clock
}


