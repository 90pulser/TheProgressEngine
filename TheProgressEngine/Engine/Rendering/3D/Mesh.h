#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoordinates;
	glm::vec3 colourValue;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex>& vertexList_);
	~Mesh();

	void Render();

private:
	void GenerateBuffer();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexListing;

};
#endif // !MESH_H
