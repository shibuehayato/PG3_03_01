#include "Enemy.h"
#include "Novice.h"

void Enemy::Initialize()
{
	pos_ = { 640.0f,100.0f };
	rad_ = { 20.0f,20.0f };
}

void Enemy::Update()
{}

void Enemy::Draw()
{
	if (isDead_ == false) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(rad_.x), int(rad_.y), 0.0f, RED, kFillModeSolid);
	}
}

Vector2 Enemy::GetPosition()
{
	return pos_;
}

void Enemy::OnCollision()
{
	isDead_ = true;
}
