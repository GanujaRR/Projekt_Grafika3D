#pragma once

#include "Shader.h"
#include "Texture.h"
#include "glm/glm.hpp"

class SpriteRenderer
{
public:
	SpriteRenderer();

	void Draw(Texture& texture, Shader& shader, glm::vec3 position, float rotation, glm::vec3 size, glm::vec4 color);
	void Draw(Shader& shader, glm::vec3 position, float rotation, glm::vec3 size, glm::vec4 color);

private:
	unsigned int vao, ebo;
};