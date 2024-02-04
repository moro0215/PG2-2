#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

const char kWindowTitle[] = "GC1A_14_モロズミ_サトシ_タイトル";

enum Scene {
	TITLE,
	GAME,
	CREAR,
	GAMEOVER,
};

Scene scene = TITLE;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();

	Enemy* enemy1 = new Enemy(320, 200);
	Enemy* enemy2 = new Enemy(960, 400);

	int title = Novice::LoadTexture("./title.png");
	int gameclear = Novice::LoadTexture("./clear.png");
	int gameover = Novice::LoadTexture("./over.png");


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene) {
			case TITLE:
				if (keys[DIK_SPACE]&&preKeys[DIK_SPACE]==0) {
					scene = GAME;
				}

				player->Initialize();
				enemy1->Initialize(320, 200);
				enemy2->Initialize(960, 400);

				break;
			case GAME:

			player->Update(keys, preKeys);

			enemy2->Collision(player->bullet_->bulletX_, player->bullet_->bulletY_, player->bullet_->bulletRadius_);
			enemy1->Collision(player->bullet_->bulletX_, player->bullet_->bulletY_, player->bullet_->bulletRadius_);

			if (enemy1->isAlive == 1) {
				enemy1->Update();
				player->Collision(enemy1->GetEnemyPosX_(), enemy1->GetEnemyPosY_(), enemy1->GetEnemyRadius_());
			}

			if (enemy2->isAlive == 1) {
				enemy2->Update();
				player->Collision(enemy2->GetEnemyPosX_(), enemy2->GetEnemyPosY_(), enemy2->GetEnemyRadius_());
			}

			enemy1->respawn();
			enemy2->respawn();

			if (player->isAlive == 0) {
				scene = GAMEOVER;
			}
			if (enemy1->isAlive == 0 && enemy2->isAlive == 0) {
				scene = CREAR;
			}

			break;
			case CREAR:
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					scene = TITLE;
				}
				break;
			case GAMEOVER:
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					scene = TITLE;
				}
				break;

		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene) {
			case TITLE:
				Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);
				break;
			case GAME:

		
		if (player->isAlive == 1) {
			player->Draw();
		}

		if (enemy1->isAlive == 1) {
			enemy1->Draw();
		}

		if (enemy2->isAlive == 1) {
			enemy2->Draw();
		}

		break;
			case CREAR:
				Novice::DrawSprite(0, 0, gameclear, 1, 1, 0.0f, WHITE);
				break;
			case GAMEOVER:
				Novice::DrawSprite(0, 0, gameover, 1, 1, 0.0f, WHITE);
				break;

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete enemy1;
	delete enemy2;
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}