#ifndef __SCORE_H__
#define __SCORE_H__

#include <cstddef> 

#include "../Coordinates/coordinates.h"
#include "../Field/field.h"

class AbstractScore {
public:
	virtual ~AbstractScore() = default;

	virtual void add_points(size_t) = 0;
	virtual void sub_points(size_t) = 0;
	virtual size_t get_points() = 0;
};

class Score {
private:

public:
	Score(
		AbstractField* afield,
		Coordinates aplace/*,
		... asprite*/
	);
	virtual ~Score() = default;

	virtual void add_points(size_t num);
	virtual void sub_points(size_t num);
	virtual size_t get_points();
};

#endif //__SCORE_H__
