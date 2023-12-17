#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include <memory>

class StageScene : public IScene
{
private:
	// 自キャラ
	std::unique_ptr<Player> player_;
	// 敵キャラ
	std::unique_ptr<Enemy> enemy_;

public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};

