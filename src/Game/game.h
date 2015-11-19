#ifndef __GAME_H__
#define __GAME_H__

#include <cstddef>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <functional>

#include "../Field/field.h"
#include "../Snake/snake.h"
#include "../Score/score.h"
#include "../FruitCreators/fruit_creators.h" 

class AbstractGame {
public:
	//AbstractGame();
	virtual ~AbstractGame() = default;

	virtual size_t maincycle() = 0;
};

class Game : public AbstractGame {
private:
	std::unordered_map< std::string, std::function< void() > > effects;

	AbstractField* field;
	AbstractSnake* snake;
	AbstractScore* score;
	std::vector< FruitCreator* > fruit_creators;
	std::list< Fruit* > fruits;

public:
	Game(
		AbstractField* afield,
		AbstractSnake* asnake,
		AbstractScore* ascore,
		std::vector< FruitCreator* > afruit_creators
	);
	virtual ~Game();

	virtual size_t maincycle();
};

#endif //__GAME_H__
