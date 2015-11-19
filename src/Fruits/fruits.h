#ifndef __FRUITS_H__
#define __FRUITS_H__

#include <string>

#include "../Coordinates/coordinates.h"
#include "../Field/field.h"

class Fruit {
public:
	virtual ~Fruit() = default;

	virtual Coordinates get_position() const = 0;
	virtual void decrement_timer() = 0;
	virtual std::string type() = 0;
};


class GoodFruit : public Fruit {
private:
	AbstractField* field;
	Coordinates position;

public:
	GoodFruit(
		AbstractField* field,
		Coordinates aposition/*,
		... asprite */
	);
	virtual ~GoodFruit() = default;

	Coordinates get_position() const;
	void decrement_timer();
	std::string type();
};

#endif //__FRUITS_H__
