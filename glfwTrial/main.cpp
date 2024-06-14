#include <GLFW/glfw3.h>
#include <stdexcept>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        glfwTerminate();
        throw std::runtime_error("GLFW Initialization Failed!\n");
    }

    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);

    if (!window){
        glfwTerminate();
        throw std::runtime_error("Failed to Create GLFW Window!\n");   
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Set the clear color to light red */
    glClearColor(1.0f, 0.5f, 0.5f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

