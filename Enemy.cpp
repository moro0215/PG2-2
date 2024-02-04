#include "Enemy.h"

Enemy::Enemy(float posX, float posY) {
	posX_ = posX;
	posY_ = posY;
	speed_ = 5;
	radius_ = 20;
	respownCount = 300;
	isAlive = 1;
}

Enemy::~Enemy() {
}

void Enemy::Update() {
	if (isAlive == 1) {
		posX_ += speed_;
	}
	if (posX_ - radius_ < 0 || posX_ + radius_ > 1280) {
		speed_ *= -1;
	}
}

void Enemy::Draw() {
	if (isAlive == 1) {
		Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::Collision(float posX, float posY, int radius) {

	float distance = (float)sqrtf((posX - posX_) * (posX - posX_) + (posY - posY_) * (posY - posY_));
	float rad = (float)(radius_ + radius);

	if (rad >= distance) {
		isAlive = 0;
	}
}

void Enemy::respawn() {
	
	if (isAlive == 0) {
		respownCount --;
	}
	if (respownCount <= 0) {
		isAlive = 1;
		respownCount = 300;
	}

}

void Enemy::Initialize(float posX, float posY) {
	posX_ = posX;
	posY_ = posY;
	speed_ = 5;
	radius_ = 20;
	respownCount = 300;
	isAlive = 1;
}

void Enemy::SetSpeed(int speed) { this->speed_ *= speed;};
