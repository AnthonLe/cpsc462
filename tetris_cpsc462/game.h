#ifndef Tetris_Game_h
#define Tetris_Game_h

//class Board;
//class Brain;
//#include "board.h"
//#include "brain.h"

class Board;
class Brain;


namespace Tetris
{
	class Game
	{
	public:
		/*std::unique_ptr<Tetris::Game> gameTest;
		std::unique_ptr<Tetris::Brain> brainTest;
		std::unique_ptr<Tetris::Board> boardTest;*/

		bool gameover = false;
		void StartNewGame(Game &obj, Brain &obj3);
		void UpdateGame(Game &obj, Brain &obj3, Board &obj2);
		int nScore = 0;
		/*bool gameover = false;
		void StartNewGame(Game &gameTest, Brain &brainTest);
		void UpdateGame(Game &gameTest, Brain &brainTest, Board &boardTest);
		int nScore = 0;*/

		Game();

		//Game() = default;   // default ctor

		// Destructor
		~Game() ;

	private:
		// These smart pointers hold pointers to lower architectural layer's interfaces
		std::unique_ptr<Persistence::PersistenceHandler>    _persistentData;
		std::unique_ptr<Logging::CLogger>             _loggerPtr;
		std::unique_ptr<Tetris::Game>  _game;
		//std::unique_ptr<Tetris::Brain>  _brains;
		//std::unique_ptr<Tetris::Board>  _boards;
		//std::unique_ptr<Tetris::Block>  _block;

		// convenience reference object enabling standard insertion syntax
		// This line must be physically after the definition of _loggerPtr
		Logging::CLogger                            & _logger = *_loggerPtr;

	};
}  // namespace Tetris

#endif // Tetris_Game_h