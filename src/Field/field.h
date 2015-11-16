#ifndef __FIELD_H__
#define __FIELD_H__

#include "../Coordinates/coordinates.h"

class AbstractField {
public:
	virtual ~AbstractField() = default;

	//virtual bool load_grass_sprite(...) = 0;
	//virtual bool load_wall_sprite(...) = 0;

	virtual bool const* get_mask() = 0;
	//virtual void draw_cell(Coordinates position) = 0;
	virtual bool collides(Coordinates position) = 0;
};

class Field : public AbstractField {
private:
	Coordinates size;
	bool* walls;
public:
	Field(Coordinates asize, bool* awalls);
	virtual ~Field();

	//virtual bool load_grass_sprite(...);
	//virtual bool load_wall_sprite(...);

	virtual bool const* get_mask();
	//virtual void draw_cell(Coordinates position);
	virtual bool collides(Coordinates position);
};

#endif //__FIELD_H__
