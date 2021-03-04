#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Camera/Camera.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoordinates;
	glm::vec3 colourValue;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex>& vertexList_, GLuint shaderProgram_);
	~Mesh();

	void Render(Camera* camera_,glm::mat4 transform_);

private:
	void GenerateBuffer();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexListing;
	GLuint shaderProgram;
	GLuint modelLoc, viewLoc, projectionLoc;

};
#endif // !MESH_H
