#include "Wall.h"
int r(int rength) {
	int random = rand() % rength;
	if (random < 0) {
		random = 0 - random;
	}
	return random;
}

void wall_set(int& type, int& score, int& isUltra, bool& isRed) {
	int wr = r(4);
	type = wr;
	isRed = false;
	switch (wr) {
	case 0:
		isRed = true;
	case 1:
		score = r(16) * 10;
		break;
	case 2:
		isRed = true;
	case 3:
		score = r(9);
		break;
	}
	if (r(10) == 0) isRed = !isRed;

	//ウルトラ処理
	if (r(10) == 7) {
	//if(true){
		isUltra = r(5) + 1;
		score = 0;
	}
	else {
		isUltra = 0;
	}
}


void draw(int& type, int& score, int& isUltra, bool& isRed, bool isLeft, int& y) {
	UINT color;
	char* text = new char[255];
	char* opt = new char[2];
#pragma region Left
	if (isRed) {
		color = GetColor(175, 0, 0);
	}
	else {
		color = GetColor(50, 50, 255);
	}
	int ladd = isLeft ? 0 : 250;
	DrawBox(0 + ladd, y - 25, 250 + ladd, y + 25, color, 1);
	switch (type) {
	case 0:
		strcpy_s(opt, 2, "+");
		break;
	case 1:
		strcpy_s(opt, 2, "-");
		break;
	case 2:
		strcpy_s(opt, 2, "x");
		break;
	case 3:
		strcpy_s(opt, 2, "/");
		break;
	}
	sprintf_s(text, 255, "%s%d", opt, score);
	if (isUltra) {
		switch (isUltra) {
		case 1:
			DrawString(0 + ladd, y, "x(sin(25)-cos(5))", GetColor(0, 0, 0));
		case 2:
		default:
			DrawString(0 + ladd, y, "xlog(22-7sin(1.3))", GetColor(0, 0, 0));
			break;
		}
		return;
	}
	DrawString(0 + ladd, y, text, GetColor(0, 0, 0));
}

Wall::Wall() {
	wall_set(left_type, left_score, left_isUltra, left_isRed);
	wall_set(right_type, right_score, right_isUltra, right_isRed);
}

void Wall::Draw(int y)
{
	draw(left_type, left_score, left_isUltra, left_isRed, true, y);
	draw(right_type, right_score, right_isUltra, right_isRed, false, y);
}
