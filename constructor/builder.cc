#include<iostream>

enum Direction { NORTH, EAST, SOUTH, WEST };
class Room{
};

class Wall{
};

class Door{
};

class Maze{
};


class MazeBuilder {
	public:
		virtual void BuildMaze() { ; }
		virtual void BuildRoom(int room) {}
		virtual void BuildDoor(int roomFrom, int roomTo) { ; }

		virtual Maze* GetMaze() { return 0; }
	protected:
		MazeBuilder();
};

class StandardMazeBuilder : public MazeBuilder{
	public:
		StandardMazeBuilder();
		
		virtual void BuildMaze();
		virtual void BuildRoom(int);
		virtual void BuildDoor(int, int);
		virtual Maze* GetMaze();
	private:
		Direction CommonWall(Room*, Room*);
		Maze* _currentMaze;
};


StandardMazeBuilder::StandardMazeBuilder() {
	_currentMaze = 0;
}

void StandardMazeBuilder::BuildMaze() {
	_currentMaze = new Maze;
}

Maze* StandardMazeBuilder::GetMaze() {
	return _currentMaze;
}

void StandardMazeBuilder::BuildRoom(int n) {
	/*
	if(!_currentMaze->BuildRoom(n)) {
		Room* room = new Room(n);
		_currentMaze->addRoom(room);
		room->SetSide(North, new Wall);
		room->SetSide(South, new Wall);
		room->SetSide(East, new wall);
		room->SetSide(West, new wall);
		}
    */
}


void StandardMazeBuilder::BuildDoor(int n1, int n2) {
	/*
	Room *r1 = _currentMaze->RoomNo(n1);
	Room *r2 = _currentMaze->RoomNo(n2);
	Door *d = new Door(r1, r2);

	r1->SetSide(CommonWall(r1, r2), d);
	r2->SetSide(CommonWall(r2, r1), d);
	*/
}


class MazeGame{
	public:
		Maze* CreateMaze(MazeBuilder &builder) {
			builder.BuildMaze();
			builder.BuildRoom(1);
			builder.BuildRoom(2);
			builder.BuildDoor(1, 2);
			return builder.GetMaze();
		}
};


int 
main(int argc, char *argv[])
{
	Maze *maze;
	MazeGame game;
	StandardMazeBuilder builder;
	game.CreateMaze(builder);
	maze = builder.GetMaze();
}
