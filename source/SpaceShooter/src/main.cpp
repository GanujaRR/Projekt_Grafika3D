#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Game.h"
#include "Input.h"

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024 && action == GLFW_PRESS)
        Input::keys[key] = true;
    if (key >= 0 && key < 1024 && action == GLFW_RELEASE)
        Input::keys[key] = false;
}

int main()
{
    glfwInit();
    // Wskaz�wki dotycz�ce wersji major 3, minor 3 = ver.  3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Tworzenie okna
    GLFWwindow* window = glfwCreateWindow(Game::w_width, Game::w_height, "Space Shooter", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //ustawia w�tek na kontekst
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Funkcja do przechwytywania wci�ni�tych klawiszy gdy okno jest aktywne 
    glfwSetKeyCallback(window, key_callback);

    Game game;
    game.Init();

    float currentTime = 0;
    float delta = 0;
    float lastTime = 0;

    while (!glfwWindowShouldClose(window))
    {
        currentTime = glfwGetTime();
        delta = currentTime - lastTime;
        lastTime = currentTime;

        //przetwarza zdarzenia kt�re ju� s� w kolejce 
        glfwPollEvents();
        game.OnProcessInput();

        game.OnUpdate(delta);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.OnRender();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}