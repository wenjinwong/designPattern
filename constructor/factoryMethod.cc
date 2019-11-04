#include<iostream>

using ProductId = int;


class Product{
};


class myProduct :public  Product{
};

class yourProduct :public  Product {
};

class Creator {
	public:
		virtual Product *Create(ProductId);
		Product *GetProduct();
	protected:
		virtual Product *CreateProduct();
	private:
		Product *_product;
}

Product* Creatro::GetProduct() {
			if(_product == 0)
			{
				_product = createProduct();
			}
			return _product;
};

template<class TheProduct>
class StandardCreator : public Creator {
	public:
		virtual Product* createProduct();
};

template<class TheProduct>
Product* StandardCreator<TheProduct>::CreateProduct() {
	return new TheProduct;
}

class Myproduct : public Product {
	public:
		myProduct();
		// ...
};

StandardCreator<Myproduct> MyCreator;


typedef int id;
#define MINE 1
#define YOURS 2
#define THEIS 3
Product *Creator::Create(ProductId id) {
	if(id == MINE) return new myProduct;
	if(id == YOURS) return new yourProduct;
	// 
	return 0;
}

class MyCreator : public Creator {
	public:
		Product *create(ProductId id) {
			if(id = THEIS) return new myProduct;
			return Creator::Create(id);
		}
};



