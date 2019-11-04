#include<iostream>


class TcpConnection {
	public:
		TcpConnection();

		void ActiveOpen();
		void PassiveOpen();
		void close();

		void send();
		void Acknowledge();
		void Synchronize();

		void ProcessOctet(TcpSocketStream *);
	private:
		friend class TcpState;
		void ChangeState(TcpState *);
	private:
		TcpState *_state;
};


class TcpState {
	public :
		virtual void Transmit(TcpConnection *, TCPOcterStream*);
		virtual void ActiveOpen(TcpConnection *);
		virtual void PassiveOpen(TcpConnection*);
		virtual void close(TcpConnection*);
		virtual void Synchronize(TcpConnection*);
		virtual void Acknowledge(TcpConnection*);
		virtual void send(TcpConnection*);
	protected:
		void ChangeState(TcpConnection*, TcpState*);
};

TcpConnection::TcpConnection() {
	_state = TcpClosed::instance();
}

void TcpConnection::changeState(TcpState* s) {
	_state = s;
}

void TcpConnection::ActiveOpen() { 
	_state->ActiveOpen(this);
}

void TcpConnection::close() {
	_state->close(this);
}

//... other proxy
//



void TcpState::Transmit(TcpConnection*, TCPOcterStream*) {}
//...


void TcpState::changestate(TcpConnection* t, TcpState* s) {
	t->changestate(s);
}

class TcpEstablicshed : public TcpState {
	public:
		static TcpSate* instance();

		virtual void transmit(TcpConnection*, TCPOcterStream*);
		virtual void close(TcpConnection*);
};


class TcpListen : public TcpState {
	public:
		static TcpState* Instance();

		virtual void send(TcpConnection*);
		/////
};


class TcpClosed : public TcpState {
	public:
		static TcpState *Instancd() ;

		virtual void send(TcpConnection*);
		//...
};


void TcpClosed::activeOpen(TcpConnection* t) {
	// send SYN, recerive syn, ack, tyc.
	//
	
	changeState(t, TCPOcterStream::Instance());
}

void TcpClosed::passiveOpen(TcpConnection* t) {
	changeState(t, tcplisten::Instance());
}
//...

void Tcpestablished::close(TcpConnection* t) {
	//send FIN, RECEIVE ACK OF fin
	chanfeState(t. tcplisten::Instance());
}

void Tcpestablished::Transmit(TcpConnection* t, TCPOcterStream* 9)
{
	t->processOctet(0);
}

void tcplisten::send(TcpConnection *t) {
	// send syn, recerive syn, ack tec.
	changeState(t, Tcpestablished::Instance() ):
}


