#pragma once
#include "Bullet.h"
#include "Novice.h"
#include "math.h"
#define _USE_MATH_DEFINES

class Player {
public:

	Bullet* bullet_;
	int bulletX_;
	int bulletY_;
	int bulletSpeed_;
	int bulletRadius_;
	bool isShot;
	bool isAlive;

public:
	Player();
	~Player();
	int GetPlayerPosX_() { return playerX_; };
	int GetPlayerPosY_() { return playerY_; };
	int GetPlayerSpeed_() { return playerSpeed_; };
	int GetPlayerRadius_() { return playerRadius_; };

	void SetSpeed(int speed);
private:
	int playerX_;
	int playerY_;
	int playerRadius_;
	int playerSpeed_;

public:
	void Update(char* keys, char* preKeys);
	void Draw();
	void Collision(float posX, float posY, float radius);
	void Initialize();

};