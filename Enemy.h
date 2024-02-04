#pragma once
#include "math.h"
#define _USE_MATH_DEFINES
#include "Novice.h"
class Enemy {
private:
	float posX_;
	float posY_;
	int speed_;
	float radius_;

public:
	float GetEnemyPosX_() { return posX_; };
	float GetEnemyPosY_() { return posY_; };
	int GetEnemySpeed_() { return speed_; };
	float GetEnemyRadius_() { return radius_; };

	void SetSpeed(int speedX);
	int respownCount;
	bool isAlive;

public:
	
	Enemy(float posX, float posY);

	~Enemy();

	void Update();
	void Draw();
	void Collision(float posX, float posY, int radius);
	void respawn();
	void Initialize(float posX, float posY);

};