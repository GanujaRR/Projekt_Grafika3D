#pragma once

#include "GameObject.h"

class ShowLose : public GameObject
{
public:
	ShowLose() {}
	void OnInit(glm::vec3 position, float rotation, glm::vec3 size) override;
	void OnUpdate(float ds) override;
	void OnRender(SpriteRenderer* renderer) override;
	void ShowLoseUI(GameObject* player, GameObject* boss, GameObject* enemySpawner);
private:
	bool isLose;
};