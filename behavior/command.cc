#include<iostream>


class command{
	public:
		virtual ~command();

		virtual void execute() = 0;
	protected:
		command();
};

class opencommand : public command{
	public:
		opencommand(application*);

		virtual void execute() ;
	protected:
		virtual const char* askuser() ;
	private:
		application* _application;
		char *_response;
};

opencommand::opencommand(application *a) {
	_application = a;
}

coid opendcommand::execute() {
	const char* name = askuser() ;
	if(name != 0)
	{
		document *doc = new docment(name);
		_application->add(doc);
		doc->open();
	}
};


class pastcommand : public command {
	public:
		pastecommand(document*);

		virtual void execute();
	private:
		docment* _document;
};

void pastecommand::execute() {
	_document->paset();
}


template<class receiver>
class simplecommand : public command {
	public:
		typedef void (receiver::*action)();
		simplecommand(receiver *r, action a) : _receiver(r), _action(a) { }
		virtual void execute();

	private:
		action _action;
		recerver *_receiver;
};


template<class receiver>
void simplecommand<receiver>::execute() {
	(_receiver->*_action(a) )();
}

int 
test(void)
{
	myclass *receiver = new myclass;
	//...
	command *acommand = new simplecommand<myclass>(receiver, &myclass::action);
	//...
	acommand->execute();
}


class macrocommand : public command {
	public:
		macrocommand();
		virtual ~macrocommand();
		
		virtual void add(command*);
		virtual void remove(command*);

		virtual void execute();
	private:
		list<command*> *cmds;
};

void macrocommand::execute() {
	listiterator<command*>  i(_cmds);
	for(i.first(); i.isdone(); i.next()) {
		command *c = i.currentItem();
		c->execute();
	}
}

void macrocommand::add(command *c) {
	_cmds->append(c);
}

void macrocommand::remove(command* c) {
	_cmds->remove(c);
}

