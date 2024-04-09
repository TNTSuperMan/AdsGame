#include "initialize.h"
#include "DxLib.h"

int InitializeDxLib(int width, int height) {
	SetOutApplicationLogValidFlag(0);
	ChangeWindowMode(1);
	SetGraphMode(width, height, 16);
	SetMainWindowText("�L���Q�[");
	if (DxLib_Init() == -1) {
		MessageBox(0, "DxLib���N���ł��܂���ł���", "�L���Q�[", MB_OK);
		return 0;
	}

	return 1;
}