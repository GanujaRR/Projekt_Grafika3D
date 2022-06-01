#include "ShowLose.h"

void ShowLose::OnInit(glm::vec3 position, float rotation, glm::vec3 size)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = size;
	isLose = false;
}

void ShowLose::OnUpdate(float ds)
{
	if (isLose && position.y >= 0)
		position.y -= 400 * ds;
}

void ShowLose::OnRender(SpriteRenderer* renderer)
{
	if (isLose)
	{
		renderer->Draw(Texture::GetTexture("lose"), Shader::GetShader("sprite"), position, rotation, scale, glm::vec4(1));
	}
}

void ShowLose::ShowLoseUI(GameObject* player, GameObject* boss, GameObject* enemySpawner)
{
	isLose= true;
	player->Destroy();
	boss->Destroy();
	enemySpawner->Destroy();
}
