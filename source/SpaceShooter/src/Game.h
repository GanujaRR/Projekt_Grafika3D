#pragma once
#include "glm/glm.hpp"
#include "Space.h"
#include "BackGround.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Shader.h"
#include "Input.h"
#include "LittleEnemy.h"
#include "Bullet.h"
#include "EnemySpawnManager.h"
#include "Boss.h"
#include "ShowWin.h"
#include "ShowLose.h"

#include <vector>

class Game 
{
public:
	static int w_width;
	static int w_height;

public:
	Game();
	~Game();
	void Init();
	void OnProcessInput();
	void OnUpdate(float ds);
	void OnRender();

private:
	void InitBulletPool();
	void PlayerShoot();
	void PlayerShootSpaceTime(float ds);

	void DoCollision();

private:
	glm::mat4 projection;

	SpriteRenderer* renderer;
	Space* space; // Player
	Boss* boss;
	BackGround* bg;
	ShowWin* showWin;
	ShowLose* showLose;
	
	// player bullet
	std::vector<Bullet*> player_bulletPool;
	int bullet_index = 0;
	int max_bullet = 10;
	int kill = 0; // show boss when kill >= 20

	bool canShoot = true;
	float time_to_next_shoot = 0.3f;
	float time_btw = time_to_next_shoot;

	// Enemy Spawner
	EnemySpawnManager* enemySpawnManager;
};