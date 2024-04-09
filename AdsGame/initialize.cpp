#include "initialize.h"
#include "DxLib.h"

int InitializeDxLib(int width, int height) {
	SetOutApplicationLogValidFlag(0);
	ChangeWindowMode(1);
	SetGraphMode(width, height, 16);
	SetMainWindowText("LƒQ[");
	if (DxLib_Init() == -1) {
		MessageBox(0, "DxLib‚ğ‹N“®‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½", "LƒQ[", MB_OK);
		return 0;
	}

	return 1;
}