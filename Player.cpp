#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

Player::Player() {
	bullet_ = new Bullet();

	isShot = false;

	playerX_ = 640;
	playerY_ = 600;
	playerRadius_ = 25;
	playerSpeed_ = 5;
	isAlive = 1;

};

Player::~Player() {
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_UP] || keys[DIK_W]) {
		playerY_ -= playerSpeed_;
	}
	if (keys[DIK_DOWN] || keys[DIK_S]) {
		playerY_ += playerSpeed_;
	}
	if (keys[DIK_RIGHT] || keys[DIK_D]) {
		playerX_ += playerSpeed_;
	}
	if (keys[DIK_LEFT] || keys[DIK_A]) {
		playerX_ -= playerSpeed_;
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_->isShot == false) {

		bullet_->isShot = true;

		bullet_->bulletX_ = (float)playerX_;
		bullet_->bulletY_ = (float)playerY_;

	}

	bullet_->Update();
}

void Player::Draw() {
	bullet_->Draw();

	Novice::DrawEllipse(playerX_, playerY_, playerRadius_, playerRadius_, 0.0f, BLACK, kFillModeSolid);

}

void Player::Collision(float posX, float posY, float radius) {

	float distance = (float)sqrtf((posX - playerX_) * (posX - playerX_) + (posY - playerY_) * (posY - playerY_));
	float rad = (float)(playerRadius_ + radius);

	if (rad >= distance) {
		isAlive = 0;
	}
}

void Player::Initialize() {
	bullet_ = new Bullet();

	isShot = false;
	playerX_ = 640;
	playerY_ = 600;
	playerRadius_ = 25;
	playerSpeed_ = 5;
	isAlive = 1;
}

void Player::SetSpeed(int speed) { this->playerSpeed_ *= speed;};
