#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 900;

void processInput(GLFWwindow* window) {

}

 
/*
float vertices[] = {
    // positions          // colors
    -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f
};
*/
float vertices[] = {
    0.0, 0.0, 2.0, 1.5, 0.0, 2.0, 0.0, 1.0, 2.0,
    0.0, 1.0, 2.0, 1.5, 0.0, 2.0, 2.5, 1.0, 1.0,
    0.0, 1.0, 2.0, 2.5, 1.0, 1.0, 2.0, 2.0, 2.0,
    0.0, 1.0, 2.0, 2.0, 2.0, 2.0, 1.0, 3.0, 1.0,
    0.0, 1.0, 2.0, 1.0, 3.0, 1.0, 0.0, 4.0, 2.0,
    1.5, 0.0, 2.0, 4.0, 0.5, 2.0, 2.5, 1.0, 1.0,
    1.5, 0.0, 2.0, 4.0, 0.0, 2.0, 4.0, 0.5, 2.0,
    3.5, 2.5, 1.0, 4.0, 0.5, 2.0, 4.0, 4.0, 2.0,
    2.0, 2.0, 2.0, 2.5, 1.0, 1.0, 4.0, 0.5, 2.0,
    2.0, 2.0, 2.0, 4.0, 0.5, 2.0, 3.5, 2.5, 1.0,
    2.5, 4.0, 2.0, 3.5, 2.5, 1.0, 4.0, 4.0, 2.0,
    2.0, 2.0, 2.0, 3.5, 2.5, 1.0, 2.5, 4.0, 2.0,
    1.0, 3.0, 1.0, 2.0, 2.0, 2.0, 2.5, 4.0, 2.0,
    0.0, 4.0, 2.0, 1.0, 3.0, 1.0, 2.5, 4.0, 2.0
};




int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Scene", NULL, NULL);

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

   

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }    

    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
