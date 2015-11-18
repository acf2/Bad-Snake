#ifndef __FIELD_H__
#define __FIELD_H__

#include <vector>

#include "../Coordinates/coordinates.h"

class AbstractField {
public:
	virtual ~AbstractField() = default;

	virtual bool const* get_mask() = 0;
	//virtual void draw_cell(Coordinates position) = 0;
	//virtual void draw_cell(Coordinates position, ... sprite) = 0;
	virtual bool collides(Coordinates position) = 0;
};

class Field : public AbstractField {
private:
	Coordinates size;
	std::vector< bool > walls;
public:
	Field(
		Coordinates asize,
		std::vector< bool > awalls/*,
		... agrass_sprite,
		... awall_sprite
		*/
	);
	virtual ~Field();

	virtual bool const* get_mask();
	//virtual void draw_cell(Coordinates position);
	//virtual void draw_cell(Coordinates position, ... sprite);
	virtual bool collides(Coordinates position);
};

#endif //__FIELD_H__
