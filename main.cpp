#include <Novice.h>
#include "GameManager.h"
const char kWindowTitle[] = "LE2C_11_シブエ_ハヤト_PG3_03_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManager* gameManager = new GameManager();

	// ゲームループ
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
