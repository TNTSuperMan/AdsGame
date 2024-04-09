#pragma once
#include "DxLib.h"
#include <cmath>

#define PLUS 0
#define MINUS 1
#define TIMES 2
#define DIVIE 3

class Wall
{
public:
	int left_type;
	int left_score;
	int left_isUltra;
	bool left_isRed;

	int right_type;
	int right_score;
	int right_isUltra;
	bool right_isRed;
	
	Wall();
	void Draw(int y);
};

int r(int rength);
void wall_set(int& type, int& score, int& isUltra, bool& isRed);
void draw(int& type, int& score, int& isUltra, bool& isRed, bool& isLeft, int& y);