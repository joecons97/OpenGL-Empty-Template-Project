

#include "Window.h"

int main(void)
{
    Window* win = Window::Init({ 640, 480 }, "My Window", 0);
    if (!win)
        return -1;

    win->StartOpenGL();

    win->Release();

    return 0;
}
