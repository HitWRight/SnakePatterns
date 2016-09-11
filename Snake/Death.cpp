#include "Death.h"
#include "ConsoleDraw.h"
#include "Vec2d.h"

Death::Death()
{
}

Death::~Death()
{
}

void Death::Die()
{

	ConsoleDraw::ClearConsole();

	//25x25
	Vec2d signStartPos = { 3, 8 };

	// 0   4   8   12  15
	// @@  @@@  @  @@@ @ @
	// @ @ @   @ @ @@@ @ @
	// @ @ @@  @@@  @  @@@
	// @ @ @   @ @  @  @ @
	// @@  @@@ @ @  @  @ @

	Vec2d deathSignPos[5][10] = { { { 0,0 },{ 0,1 },{ 0,2 },{ 0,3 },{ 0,4 },{ 1,0 },{ 1,4 },{ 2,1 },{ 2,2 },{ 2,3 } }, //D
	{ { 4,0 },{ 4,1 },{ 4,2 },{ 4,3 },{ 4,4 },{ 5,0 },{ 6,0 },{ 5,2 },{ 5,4 },{ 6,4 } }, //E
	{ { 8,4 },{ 8,1 },{ 8,2 },{ 8,3 },{ 9,0 },{ 9,2 },{ 10,4 },{ 10,1 },{ 10,2 },{ 10,3 } }, //A
	{ { 12,0 },{ 12,1 },{ 13,2 },{ 13,3 },{ 13,4 },{ 13,0 },{ 13,1 },{ 14,0 },{ 14,1 },{ 17,2 } }, //T and H middle
	{ { 16,0 },{ 16,1 },{ 16,2 },{ 16,3 },{ 16,4 },{ 18,0 },{ 18,1 },{ 18,2 },{ 18,3 },{ 18,4 } } }; //H

	for (int i = 0; i<5; ++i)
		for (int j = 0; j < 10; ++j)
		{
			ConsoleDraw::Draw(signStartPos + deathSignPos[i][j], '@');
		}

	Sleep(5000);

//	throw new std::exception("Snake has died");
	exit(EXIT_FAILURE);

}
