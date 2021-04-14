#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoordinates;
layout (location = 3) in vec3 colourValue;

out vec3 Normal;
out vec2 TexCoords;
out vec3 Colour;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	gl_Position = projection * view * model * vec4(position, 1.0f);
	Colour = colourValue;
	TexCoords = texCoordinates;
	Normal = normal;
}