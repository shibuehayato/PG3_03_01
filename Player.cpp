#include "Player.h"
#include "Novice.h"
#include "Enemy.h"

void Player::Initialize()
{
	pos_ = { 640.0f,500.0f };
	rad_ = { 10.0f,10.0f };

	// 自キャラの生成
	playerBullet_ = std::make_unique<PlayerBullet>();
	playerBullet_->Initialize();

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void Player::Update()
{
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	if (playerBullet_->GetIsBulletShot() == false) {
		if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
			isBulletShot = true;
			playerBullet_->SetIsBulletShot(isBulletShot);
			playerBullet_->SetPosition(pos_.x, pos_.y);
		}
	}
	playerBullet_->Update();

	if (keys_[DIK_W]) {
		pos_.y -= speed;
	}
	if (keys_[DIK_S]) {
		pos_.y += speed;
	}
	if (keys_[DIK_A]) {
		pos_.x -= speed;
	}
	if (keys_[DIK_D]) {
		pos_.x += speed;
	}
}

void Player::Draw()
{
	playerBullet_->Draw();
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(rad_.x), int(rad_.y), 0.0f, GREEN, kFillModeSolid);
}