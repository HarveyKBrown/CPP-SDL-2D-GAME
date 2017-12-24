#include "Vector2D.h"

class GameObject
{
	public:
		Vector2D position;
		Vector2D size;
		SDL_Texture image;

		void draw();
		//Do I need a draw, or can that be all on game-logic side?
};
