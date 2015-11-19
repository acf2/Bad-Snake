#ifndef __FRUIT_CREATORS_H__
#define __FRUIT_CREATORS_H__

#include "../Fruits/fruits.h"
#include "../Coordinates/coordinates.h"
#include "../Field/field.h"

class FruitCreator {
public:
	virtual ~FruitCreator() = default;

	virtual Fruit* create_fruit(Coordinates, /*...,*/ size_t) = 0;
	virtual void set_field(AbstractField* afield) = 0;
};

class GoodFruitCreator : public FruitCreator {
private:
	AbstractField* field;

public:
	virtual ~GoodFruitCreator() = default;

	virtual Fruit* create_fruit(Coordinates aposition, /*... asprite,*/ size_t timer = 0);
	virtual void set_field(AbstractField* afield);
};

#endif //__FRUIT_CREATORS_H__
