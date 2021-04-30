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

struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<unsigned int> meshIndices;
	GLuint textureID;
};

class Mesh
{
public:
	Mesh(SubMesh& subMesh_, GLuint shaderProgram_);
	~Mesh();

	void Render(Camera* camera_,std::vector<glm::mat4>& instances_);

private:
	void GenerateBuffer();
	GLuint VAO, VBO;
	SubMesh subMesh;
	GLuint shaderProgram;
	GLuint modelLoc, viewLoc, projectionLoc, textureLoc,
		cameraPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightSpecularLoc, lightColourLoc;

};
#endif // !MESH_H
