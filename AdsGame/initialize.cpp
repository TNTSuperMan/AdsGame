#include "initialize.h"
#include "DxLib.h"

int InitializeDxLib(int width, int height) {
	SetOutApplicationLogValidFlag(0);
	ChangeWindowMode(1);
	SetGraphMode(width, height, 16);
	SetMainWindowText("広告ゲー");
	if (DxLib_Init() == -1) {
		MessageBox(0, "DxLibを起動できませんでした", "広告ゲー", MB_OK);
		return 0;
	}

	return 1;
}