#pragma once
#include "Vector2.h"
#include <memory>
#include <IScene.h>

class Enemy;

class PlayerBullet : public IScene
{
private:
	Vector2 pos_;
	float speed_ = 4.0f;
	bool isBulletShot_ = false;
	float enemyHp = 0;

	std::unique_ptr<Enemy> enemy_;
public:
	void Initialize();
	void Update();
	void Draw();
	void SetPosition(float x, float y);
	bool GetIsBulletShot() { return isBulletShot_; }
	bool SetIsBulletShot(bool result);
	Vector2 GetPosition();
	void CheckCollision();
};