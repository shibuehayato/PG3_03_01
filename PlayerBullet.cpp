#include "PlayerBullet.h"
#include "Novice.h"
#include "Enemy.h"

void PlayerBullet::Initialize()
{
	pos_ = { 0.0f,0.0f };

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void PlayerBullet::Update()
{
	if (isBulletShot_ == true) {
		pos_.y -= speed_;
	}
	if (pos_.y <= 0.0f) {
		pos_.y = -200.0f;
		isBulletShot_ = false;
	}

	CheckCollision();
}

void PlayerBullet::Draw()
{
	Novice::DrawTriangle(int(pos_.x - 5.0f), int(pos_.y + 5.0f), int(pos_.x), int(pos_.y - 5.0f), int(pos_.x + 5.0f), int(pos_.y + 5.0f), WHITE, kFillModeSolid);
}

void PlayerBullet::SetPosition(float x, float y)
{
	pos_.x = x;
	pos_.y = y;
}

bool PlayerBullet::SetIsBulletShot(bool result)
{
	return isBulletShot_ = result;
}

Vector2 PlayerBullet::GetPosition()
{
	return pos_;
}

void PlayerBullet::CheckCollision()
{
	Vector2 enemyPos;
	enemyPos = enemy_->GetPosition();
	float distance = ((enemyPos.x - pos_.x) * (enemyPos.x - pos_.x) + (enemyPos.y - pos_.y) * (enemyPos.y - pos_.y));
	float radius = (20.0f + 5.0f) * (20.0f + 5.0f);
	if (radius == distance || radius > distance) {
		enemy_->OnCollision();

		sceneNo = kClear;
	}
}