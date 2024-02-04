#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	bulletX_ = -100;
	bulletY_ = -100;
	bulletSpeed_ = 15;
	bulletRadius_ = 15;
	isShot = false;

};

Bullet::~Bullet() {

}

void Bullet::Update() {
	if (isShot == true) {
		bulletY_ -= bulletSpeed_;
	}
	if (bulletY_ < 0) {
		isShot = false;
	}
};

void Bullet::Draw() {
	if (isShot == true) {
		Novice::DrawEllipse((int)bulletX_, (int)bulletY_, bulletRadius_, bulletRadius_, 0.0f, WHITE, kFillModeSolid);
	}
}
