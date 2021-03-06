#include "Camera.h"

#include "../Core/ProgressEngine.h"

Camera::Camera()
	: position(glm::vec3()), fieldOfView(0.0f), forward(glm::vec3()), up(glm::vec3()),
	right(glm::vec3()), worldUp(glm::vec3()), near(0.0f), far(0.0f),
	yaw(0.0f), pitch(0.0f), perspective(glm::mat4()), orthographic(glm::mat4()), view(glm::mat4()), lightSources(std::vector<LightSource*>()){
	fieldOfView = 45.0f;
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = up;
	near = 2.0f;
	far = 50.0f;
	yaw = -90.0f;
	pitch - 0.0f;

	perspective = glm::perspective(fieldOfView,
		ProgressEngine::GetInstance()->GetScreenWidth() /
		ProgressEngine::GetInstance()->GetScreenHeight(),
		near, far);

	orthographic = glm::ortho(0.0f, ProgressEngine::GetInstance()->GetScreenWidth(),
		0.0f, ProgressEngine::GetInstance()->GetScreenHeight(),
		-1.0f, 1.0f);
	
	lightSources.reserve(5);

	UpdateCameraVectors();
}

Camera::~Camera()
{
	if (lightSources.size() > 0) {
		for (auto l : lightSources) {
			delete l;
			l = nullptr;
		}
		lightSources.clear();
	}
}

void Camera::SetPosition(glm::vec3 position_)
{
	position = position_;

	UpdateCameraVectors();
}

void Camera::SetRotation(float yaw_, float pitch_)
{
	yaw = yaw_;
	pitch = pitch_;

	UpdateCameraVectors();
}

void Camera::AddLightSource(LightSource* light_)
{
	lightSources.push_back(light_);
}

std::vector<LightSource*> Camera::GetLightSources() const
{
	return lightSources;
}

glm::mat4 Camera::GetView() const
{
	return view;
}

glm::mat4 Camera::GetPerspective() const
{
	return perspective;
}

glm::mat4 Camera::GetOrthographic() const
{
	return orthographic;
}

glm::vec3 Camera::GetPosition() const
{
	return position;
}


void Camera::UpdateCameraVectors()
{
	forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward.y = sin(glm::radians(pitch));
	forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forward = glm::normalize(forward);

	right = glm::normalize(glm::cross(forward, worldUp));

	up = glm::normalize(glm::cross(right, forward));

	view = glm::lookAt(position, position + forward, up);
}
