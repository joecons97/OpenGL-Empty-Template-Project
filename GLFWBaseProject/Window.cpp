#include <GL/glew.h>
#include "Window.h"

Window* Window::Init(glm::vec2 size, const char* title, GLFWmonitor* monitor)
{
	/* Initialize the library */
    if (!glfwInit())
        return 0;

    Window* win = new Window();

    /* Create a windowed mode window and its OpenGL context */
    win->m_pWindow = glfwCreateWindow(size.x, size.y, title, monitor, NULL);
    if (!win->m_pWindow)
    {
        glfwTerminate();
        return 0;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(win->m_pWindow);

    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return 0;
    }

	return win;
}

void Window::StartOpenGL()
{
	/* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(m_pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void Window::Release()
{
    glfwTerminate();
    delete this;
}
