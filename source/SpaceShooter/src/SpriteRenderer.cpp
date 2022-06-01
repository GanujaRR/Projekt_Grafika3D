#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	unsigned int vbo;

	float vertices[] = {
	// 3 i 4 kolumna kordynaty tekstur 
	//lewo,prawo //góra, dol
		-0.5f, -0.5f, 0.f, 0.f,
		-0.5f,  0.5f, 0.f, 1.f,
		 0.5f,  0.5f, 1.f, 1.f,
		 0.5f, -0.5f, 1.f, 0.f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0 
	};

	// tworzy tablcie obiektów
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);

	// index buffor object
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vbo);
}

void SpriteRenderer::Draw(Texture& texture, Shader& shader, glm::vec3 position, float rotation, glm::vec3 size, glm::vec4 color)
{
	shader.Bind();
	glm::mat4 model(1);
	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(rotation), glm::vec3(0, 0, 1));
	model = glm::scale(model, size);

	shader.SetMatrix("model", model);
	shader.SetVector4("v_Color", color);
	texture.Bind(1);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void SpriteRenderer::Draw(Shader& shader, glm::vec3 position, float rotation, glm::vec3 size, glm::vec4 color)
{
	shader.Bind();
	glm::mat4 model(1);
	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(rotation), glm::vec3(0, 0, 1));
	model = glm::scale(model, size);

	shader.SetMatrix("model", model);
	shader.SetVector4("v_Color", color);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
