#pragma once
#include "Vector2.h"

class Enemy
{
private:
	Vector2 pos_;
	Vector2 rad_;

	bool isDead_ = false;

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:
	void Initialize();
	void Update();
	void Draw();
	void OnCollision();
	Vector2 GetPosition();
};