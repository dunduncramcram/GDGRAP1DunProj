#include <GLFW/glfw3.h>

#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(500, 500, "Dun Baniqued ", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
        glBegin(GL_POLYGON);
        float distance = 0.5, radians = 0.4*M_PI, x, y;

        for (float z = 0; z < 5; z++) {
            
            x = distance * cos(radians*z);
            y = distance * sin(radians*z);
            glVertex2f(x, y);
            
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}