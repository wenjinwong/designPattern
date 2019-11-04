class element {
	public :
		element();
		virtual void accept(vistor& v) { v.visitelement(); }
};

class elementa : public element{
	public:
		virtual void accept(vistor& v) { v.visitelementa(); }
};

class visitor {
	public:
		virtual void visitelemnt() { ; }
		virtual void visitelementa() { : }
		// ...
};

class compositeElement : public element {
	public:
		virtual void accept(visitor& v);
	private:
		List<element*>* _children;
};

void compositeElement::accept(visitor& v) {
	ListIterator<element*> i(_children);

	for(i.first(); !i.isdone(); i.next()) {
		i.currentItem()->accept(v);
	}
	v.visitCompositeElement(this);
}


class equipment {
	public:
		virtual ~equipment();

		const char* name() { return _name; }

		virtual watt power() ;
		virtual currency nerprice();
		virtual currency discountPrice();

		virtual void accept(equipmentVisitor&);
	protected:
		equipment(const char*);
	private:
		const char* _name;
};


class equipmentVisitor {
	public:
		virtual ~equipmentVisitor();

		virtual void visitFloppyDist(FloppyDisk*);
		virtual void visitcard(card*);
		virtual void visitChassis(chassis *);
		virtual void visitBus(bus*);

		// and so no for other concrete sbclasses of equipment
	protected:
		equipmentVisitor();
};

void FloppyDisk::accept(equipmentVisitor& vistor) {
	visitor.visitFloppyDisk(this);
}

void chassis::accept(equipmentVisitor* visitor) {
	if(parts) {
		parts.accept(visitor);
		parts.iter();
	}
	visitor.visitChassis(this);
}

class pricingvisitor : public Equipmentvisitor {
	public:
		pricingvisitor();

		currency& gettotalprice();

		virtual void visitFloppyDisk(FloppyDisk*);
		// ...
	private:
		currency _total;
};

void Iventoryvisitor::visitFloppyDisk(FloppyDisk* e) {
	_inventory.accumulate(e);
}

void Iventoryvisitor::add(equipment *e) {
	_total.appen(e);
}



	
