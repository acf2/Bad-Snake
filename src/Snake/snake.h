#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>

#include "../Coordinates/coordinates.h"
#include "../Field/field.h"

enum class Direction { Left, Up, Right, Down };

class AbstractSnake {
public:
	virtual ~AbstractSnake() = default;

	virtual bool const* get_mask() = 0;
	virtual Coordinates get_head_position() = 0;
	virtual Coordinates get_tail_position() = 0;
	virtual void set_head_direction(Direction dir) = 0;
	virtual Direction get_head_direction() = 0;
	virtual void move_forward(bool) = 0;
	virtual bool collides(Coordinates position) = 0;
};

class Snake : public AbstractSnake {
private:
	std::vector< Coordinates > junctions;
	Direction head_direction;
	AbstractField* field;

public:
	Snake(
		AbstractField* afield,
		std::vector< Coordinates > ajunctions/*,
		... ahead_sprite,
		... abody_sprite,
		... atail_sprite*/
	);
	virtual ~Snake();

	virtual bool const* get_mask();
	virtual Coordinates get_head_position();
	virtual Coordinates get_tail_position();
	virtual void set_head_direction(Direction dir);
	virtual Direction get_head_direction();
	virtual void move_forward(bool with_growth = 1);
	virtual bool collides(Coordinates position);
};

#endif //__SNAKE_H__
