#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
class LightSource
{
public:
	void setAmbient(float ambient_);
	void setDiffuse(float diffuse_);
	void setSpecular(float specular_);
	void setLightPos(glm::vec3 lightPos_);
	void setLightColour(glm::vec3 lightColour_);

	float getAmbient() const;
	float getDiffuse() const;
	float getSpecular() const;
	glm::vec3 getLightPos() const;
	glm::vec3 getLightColour() const;
private:
	float ambient, diffuse, specular;
	glm::vec3 lightPos, lightColour;
	LightSource(float ambient_, float diffuse_, float specular_,
		glm::vec3 lightPos_, glm::vec3 lightColour_);
	~LightSource();
};

#endif // !LIGHTSOURCE_H