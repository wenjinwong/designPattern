#include<iostream>


class MazePrototypeFactory : public MazeFactory {
	public:
		MazePrototypeFactory(Maze* m, Wall *w, Room *r, Door *d)
		{
			_pM = m;
			_pW = w;
			_pR = r;
			_pD = d;
		}
		virtual Maze* MakeMaze() const;
		virtual Room* MakeRoom() const;
		virtual Wall* MakeWall() const;
		virtual Door* MakeDoor(Room*, Room*) const;
};

// MakeWall ...
Wall* MazePrototypeFactory::MakeWall() const {
	return _pW->clone();
}

//...
 
class Door : public Mapsite {
	public:
		Door() ;
		Door(const Door&);
		virtual void Initalize(Room*, Room*);
		virtual Door* Clone() const;
		virtual void Enter();
		Room *OtherSideFrom(Room*);
	private:
		Room* _room1;
		Room* _room2;
};

Door::Door(const Door& other) {
	_room1 = other._room1;
	_room2 = other._room2;
}

void Door::Initalize(Room *r1, Room *r2) {
	_room1 = r1;
	_room2 = r2;
}

Door* Door::Clone() const {
	return new Door(*this);
}



class BombedWall : public wall {
	public:
		BombedWall();
		BombedWall(const BombedWall& b) { _bomb = b._bomb; }
		virtual wall *Clone() const { return new BombedWall(*this); }
};




