#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>

#include "../Coordinates/coordinates.h"
//#include "../Field/field.h" //For draw-method

enum class Direction { Left, Up, Right, Down };

class AbstractSnake {
public:
	virtual ~AbstractSnake() = default;

	//bool load_head_sprite(...) = 0;
	//bool load_body_sprite(...) = 0;
	//bool load_tail_sprite(...) = 0;

	virtual bool const* get_mask() = 0;
	virtual Coordinates head_coordinates() = 0;
	virtual Coordinates tail_coordinates() = 0;
	virtual void set_head_direction(Direction dir) = 0;
	virtual Direction get_head_direction() = 0;
	virtual void move_forward(bool) = 0;
	//virtual void draw(AbstractField* field) = 0;
	virtual bool collides(Coordinates position) = 0;
};

class Snake : public AbstractSnake {
private:
	std::vector< Coordinates > junctions;
	Direction head_direction;
	
public:
	Snake();
	virtual ~Snake();

	//bool load_head_sprite(...);
	//bool load_body_sprite(...);
	//bool load_tail_sprite(...);

	virtual bool const* get_mask();
	virtual Coordinates head_coordinates();
	virtual Coordinates tail_coordinates();
	virtual void set_head_direction(Direction dir);
	virtual Direction get_head_direction();
	virtual void move_forward(bool with_growth = 1);
	//virtual void draw(AbstractField* field);
	virtual bool collides(Coordinates position);
};

#endif //__SNAKE_H__
