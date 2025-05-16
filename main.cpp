#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// initialize window
void initializeWindow() {
    // instantiate window
    glfwInit();

    // version number
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // use core-profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // needed for MacOS?
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

// readjust window when window size adjusted
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main() {
    int res_x = 800; int res_y = 600;

    // initialize and instantiate window
    initializeWindow();

    GLFWwindow* window = glfwCreateWindow(res_x, res_y, "AnterogradeWindow", NULL, NULL);
    if (window == NULL) { // exception if fail
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // set viewport and register dynamical adjustment when window size changes
    glViewport(0, 0, res_x, res_y);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // terminate and exit
    glfwTerminate();
    return 0;
}
