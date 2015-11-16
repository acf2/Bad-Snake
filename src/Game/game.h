#ifndef __GAME_H__
#define __GAME_H__

#include <cstddef>

#include "../Field/field.h"
#include "../Snake/snake.h"

class AbstractGame {
public:
	//AbstractGame();
	virtual ~AbstractGame() = default;

	virtual size_t maincycle() = 0;
};

class Game : public AbstractGame {
private:
	AbstractSnake* snake;
	AbstractField* field;

public:
	Game();
	virtual ~Game();

	virtual size_t maincycle();
};

#endif //__GAME_H__
