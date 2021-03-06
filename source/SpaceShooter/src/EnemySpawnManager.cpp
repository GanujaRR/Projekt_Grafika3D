#include "EnemySpawnManager.h"

EnemySpawnManager::EnemySpawnManager()
{
	this->position = glm::vec3(0);
	this->rotation = 0;
	this->scale = glm::vec3(1);
}

void EnemySpawnManager::OnInit(glm::vec3 position, float rotation, glm::vec3 size)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = size;

	this->isAlive = true;

	// Init Little Enemy
	for (int i = 0; i < max_littleEnemy; i++)
	{
		littleEnemies.push_back(new LittleEnemy());
		littleEnemies[i]->OnInit(glm::vec3(0), 180, glm::vec3(100, 100, 0));
	}
}

void EnemySpawnManager::OnUpdate(float ds)
{
	if (isAlive)
	{
		// Update Little Enemys
		for (int i = 0; i < littleEnemies.size(); i++)
			littleEnemies[i]->OnUpdate(ds);

		if (time_btw <= 0)
			SpawnLittleEnemy();
		else 
			time_btw -= ds;
	}
}

void EnemySpawnManager::OnRender(SpriteRenderer* renderer)
{
	if (isAlive)
	{
		// Render Little Enemys
		for (int i = 0; i < littleEnemies.size(); i++)
			littleEnemies[i]->OnRender(renderer);
	}
}

void EnemySpawnManager::SpawnLittleEnemy()
{
	time_to_spawn = 1.f;
	time_btw = time_to_spawn;
	float p_X = 1 + rand() % 400 - 190; // random spawn x position;
	littleEnemies[little_enemy_index]->Spaw(glm::vec3(p_X, 400, 0));
	little_enemy_index++;
	if (little_enemy_index >= max_littleEnemy)
		little_enemy_index = 0;
}

EnemySpawnManager::~EnemySpawnManager()
{
	for (int i = 0; i < littleEnemies.size(); i++)
		delete littleEnemies[i];
}