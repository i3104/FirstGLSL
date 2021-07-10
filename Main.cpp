#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
int main() {
    // to initialize GLFW
    if ( GL_FALSE == glfwInit() ) {
        // Error message
        std::cerr << "Can't initialize GLFW" << std::endl;
        return -1;
    }

    // to attach the glfwTerminate
    atexit(glfwTerminate);

    // to set OpenGL Version 3.2 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // to create a GLFW window
    GLFWwindow* const w(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
    if ( NULL == w ) {
        // Error message
        std::cerr << "Can't create GLFW window." << std::endl;
        return -1;
    }

    // to bind OpenGL processing to created window
    glfwMakeContextCurrent(w);

    // to initialize GLEW
    glewExperimental = GL_TRUE;
    if ( GLEW_OK != glewInit() ) {
        // Error message
        std::cerr << "Can't initialize GLEW" << std::endl;
        return 1;
    }

    // to select the V-Sync count
    glfwSwapInterval(1);

    // to specify background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    // main loop
    while ( glfwWindowShouldClose(w) == GL_FALSE ) {
        // to clrea color buffer in frame buffer
        glClear(GL_COLOR_BUFFER_BIT);

        //
        // TODO
        //

        // to swap w-buffer
        glfwSwapBuffers(w);

        // to wait for an event to occur
        glfwWaitEvents();
    }
}
