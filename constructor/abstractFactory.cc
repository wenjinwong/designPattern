class testMaze {

};

class testMazeGame {
	public:
		testMaze* createMaze();
};

testMaze* testMazeGame::createMaze() { /* terrible factory */
	testMaze* aMaze = new testMaze;
	/* ... */
	return aMaze;
};


enum direction { NORTH, EAST, SOUTH, WEST};

class Wall {
	public:
};


class Room {
	public:
		void SetSide(direction dir, Wall *w) { ; }
};


class Maze {
	public:
		void addRoom(Room *m) { ; }
};


class MazeFactory {
public:
	MazeFactory();
	virtual Maze* MakeMaze () const{ return new Maze; }
	virtual Wall* MakeWall () const { return new Wall; }
	virtual Room* MakeRoom (int i) const { return new Room; }
};

class MazeGame {
	Maze* createMaze(MazeFactory& factory) {
		Maze* aMaze = factory.MakeMaze();
		Room *r1 = factory.MakeRoom(1);
		r1->SetSide(NORTH, factory.MakeWall());
		/* ... */
		aMaze->addRoom(r1);
		return aMaze;
	}
};


class Spell{
	public:
};


class EnchantedRoom : public Room {
	public:
		EnchantedRoom(int i, Spell* s) { ; }
};

class EnchantedMazeFactory : public MazeFactory {
	public:
		EnchantedMazeFactory() = default;
		virtual Room* MakeRoom(int n) const { return new EnchantedRoom(n, CastSpell());}
		/* ... */
	protected:
		Spell* CastSpell() const  { return new Spell; }
};


class BombedWall : public Wall {
	public:
};


class RoomWithbomb : public Room {
	public:
		RoomWithbomb(int n) { ; }
};


class BombedMazeFactory : public MazeFactory {
	public:
		Wall* MakeWall() const { return new BombedWall; }
		Room* MakeRoom(int n) const { return new RoomWithbomb(n); }
};


