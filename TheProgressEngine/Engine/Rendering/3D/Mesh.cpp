#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertexList_) 
: VAO(0), VBO(0), vertexListing(std::vector<Vertex>())
{
	vertexListing = vertexList_;
	GenerateBuffer();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	vertexListing.clear();
}

void Mesh::Render()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, vertexListing.size());

	glBindVertexArray(0);
}

void Mesh::GenerateBuffer()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexListing.size() * sizeof(Vertex),
		&vertexListing[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
		(GLvoid*)offsetof(Vertex, normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
		(GLvoid*)offsetof(Vertex, texCoordinates));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, colourValue));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
