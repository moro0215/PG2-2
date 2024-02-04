#pragma once

class Bullet {
public:
	Bullet();
	~Bullet();
	float bulletX_;
	float bulletY_;
	int bulletSpeed_;
	int bulletRadius_;
	bool isShot;

public:
	void Update();

	void Draw();

};