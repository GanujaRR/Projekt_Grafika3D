#pragma once
#include "GameObject.h"
#include "LittleEnemy.h"

#include <vector>

class EnemySpawnManager : public GameObject
{
public:
	EnemySpawnManager();
	~EnemySpawnManager();
	void OnInit(glm::vec3 position, float rotation, glm::vec3 size) override;
	void OnUpdate(float ds) override;
	void OnRender(SpriteRenderer* renderer) override;
	void Destroy() override { isAlive = false; }

	void SpawnLittleEnemy();

	std::vector<LittleEnemy*> GetEnemies() { return littleEnemies; }

private:
	std::vector<LittleEnemy*> littleEnemies;
	int little_enemy_index = 0;
	int max_littleEnemy = 20;
	float time_to_spawn = 5;
	float time_btw = time_to_spawn;
	bool isAlive;
};