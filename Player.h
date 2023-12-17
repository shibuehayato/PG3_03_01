#pragma once
#include "Vector2.h"
#include "PlayerBullet.h"
#include <memory>

class Enemy;

class Player
{
private:
	Vector2 pos_;
	Vector2 rad_;
	float speed = 2.0f;

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
	bool isBulletShot = false;

	std::unique_ptr<Enemy> enemy_;

	// 弾
	std::unique_ptr<PlayerBullet> playerBullet_;

public:
	void Initialize();
	void Update();
	void Draw();

};