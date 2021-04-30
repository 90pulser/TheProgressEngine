#include "LightSource.h"

LightSource::LightSource(glm::vec3 lightPos_, float ambient_, float diffuse_, float specular_,
	 glm::vec3 lightColour_) : ambient(0), diffuse(0),
	specular(0), lightPos(glm::vec3()), lightColour(glm::vec3())
{
	setAmbient(ambient_);
	setDiffuse(diffuse_);
	setSpecular(specular_);
	setLightPos(lightPos_);
	setLightColour(lightColour_);
}

LightSource::~LightSource()
{
}

void LightSource::setAmbient(float ambient_)
{
	ambient = ambient_;
}

void LightSource::setDiffuse(float diffuse_)
{
	diffuse = diffuse_;
}

void LightSource::setSpecular(float specular_)
{
	specular = specular_;
}

void LightSource::setLightPos(glm::vec3 lightPos_)
{
	lightPos = lightPos_;
}

void LightSource::setLightColour(glm::vec3 lightColour_)
{
	lightColour = lightColour_;
}

float LightSource::getAmbient() const
{
	return ambient;
}

float LightSource::getDiffuse() const
{
	return diffuse;
}

float LightSource::getSpecular() const
{
	return specular;
}

glm::vec3 LightSource::getLightPos() const
{
	return lightPos;
}

glm::vec3 LightSource::getLightColour() const
{
	return lightColour;
}


