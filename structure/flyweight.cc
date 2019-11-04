
class node{
	public:
		node *next;
		int value;
};

int recur(node *n)
{
	if(n != 0)
		recur(n->next);
};



class Glyph {
	public:
		virtual ~Glyph() { }
		virtual void Draw(window *, Glyphcontext&);

		virtual void SetFont(Font*, Glyphcontext&);
		virtual Font* getFont(Glyphcontext&);

		virtual void first(Glyphcontext&);
		virtual void next(Glyphcontext&);
		virtual bool isdone(Glyphcontext&);
		virtual Glyph* current(Glyphcontext&);

		virtual void insert(Glyph&, Glyphcontext&);
		virtual void remove(Glyphcontext&);

	protected:
		Glyph();
};

class Character : public Glyph {
	public:
		Character(char );

		virtual void draw(window*, Glyphcontext&);
	private:
		char _charcode;
};


class cglyphcontext {
	public:
		glyphcontext();
		virtual ~glyphcontext();

		virtual void next(int step = 1);
		virtual void insert(int quantity = 1);

		virtual font* getfont();
		virtual void insert(int quantity =  1);

		virtual font* getfont();
		virtual void setfond(font*, int span = 1);
	private:
		int _index;
		btree* _fonts;
};



