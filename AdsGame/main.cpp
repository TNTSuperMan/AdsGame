#include "Windows.h"
#include "initialize.h"
#include "DxLib.h"
#include "Wall.h"
#include <cmath>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd){
	if (!InitializeDxLib(500,500)) return 0;
	ULONG64 tick = 0;
	int size = 1;
	int x = 250;
	int pswidth = 0;
	bool isget = false;
	Wall w;
	char* player_status = new char[255];
	srand(GetNowCount());
	while (ProcessMessage() == 0) {
		ScreenFlip();
		ClearDrawScreen();

		DrawBox(0, 0, 500, 500, GetColor(255, 255, 255),1);

		#pragma region Player

		GetMousePoint(&x, &pswidth); //pswidthは後で書き込むので適当に
		if (x < 0) x = 0;
		if (x > 500) x = 500;
		DrawCircle(x, 350, sqrt(20 * size), GetColor(255, 255, 0));
		sprintf_s(player_status, 255, "%d", size);
		pswidth = GetDrawStringWidth(player_status, strlen(player_status));
		DrawString(x - pswidth / 2, 350, player_status, GetColor(0, 0, 0));
		#pragma endregion

		#pragma region Wall
		w.Draw(tick * 3);
		if (tick % 250 == 0) {
			w = Wall();
			tick = 0;
			isget = false;
		}
		#pragma endregion
		
		#pragma region Collision
		if (tick * 3 >= 350 && !isget) {
			isget = true;
			int score, type, isultra;
			if (x < 250) {
				score = w.left_score;
				type = w.left_type;
				isultra = w.left_isUltra;
			}
			else {
				score = w.right_score;
				type = w.right_type;
				isultra = w.right_isUltra;
			}
			printfDx("%d",isultra);
			if (isultra) {
				switch (isultra) {
				case 1:
					size *= sin(25) - cos(5);
					break;
				case 2:
				default:
					size *= log((double)22-(double)7*sin(1.3));
					break;
				}
				goto cc;
			}
			switch (type) {
			case 0:
				size += score;
				break;
			case 1:
				size -= score;
				break;
			case 2:
				size *= score;
				break;
			case 3:
				size /= score;
				break;
			}
			cc:;
			if (size <= 0) {
				MessageBox(GetMainWindowHandle(), "ゲームオーバー", "広告ゲー", MB_OK);
				return 0;
			}
		}
		#pragma endregion
		tick++;
	}
	return 0;
}