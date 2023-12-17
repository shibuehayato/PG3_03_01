#include "StageScene.h"
#include "Novice.h"

void StageScene::Initialize()
{
	// 自キャラの生成
	player_ = std::make_unique<Player>();
	player_->Initialize();

	// 敵キャラの生成
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update()
{
	player_->Update();

	enemy_->Update();
}

void StageScene::Draw()
{
	player_->Draw();

	enemy_->Draw();

	Novice::ScreenPrintf(1280 / 2, 720 / 2, "StageScene");
}
