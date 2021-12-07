#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

class Window
{
private:
	GLFWwindow* m_pWindow;
public:
	static Window* Init(glm::vec2 size, const char* title, GLFWmonitor* monitor);
	void StartOpenGL();
	void Release();
};

