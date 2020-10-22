// OpenGLApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#include <GL/glew.h> // $(SolutionDir)../External Libs/GLEW/include -> Additional Include Dir
#include <GLFW/glfw3.h> //$(SolutionDir)../External Libs/GLFW/include -> Additional Include Dir

//Windows Dimentions 1290 x 720
const GLint Width = 1290;
const GLint Height = 720;

int main()
{
    //Initialise GlFW
    if (!glfwInit()) {
        std::cout << "GLFW Initalisation failed\n" << std::endl;
        glfwTerminate();
        return 1;
    }

    // setup the GLFW windowProperties
    // OpenGL Version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //set core profile = no backward compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create a window
    GLFWwindow* mainWindow = glfwCreateWindow(Width, Height, "Test Window", NULL, NULL);
    if (!mainWindow) {
        char errstr[243];
        std::cout << "Main Window creation failed " << strerror_s(errstr,errno) << std::endl;
        glfwTerminate();
        return 1;
    }

    //get Buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //set the context of the GLEW to use 
    glfwMakeContextCurrent(mainWindow);

    //Allow Modern extension feature
    glewExperimental = GL_TRUE;

    //intialise glew
    if (glewInit() != GLEW_OK) {
        char errstr[233];
        std::cout << "GLEW intialsation failed: " << strerror_s(errstr, errno) << std::endl;
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
    //setup the veiwpoint size
    glViewport(0, 0, bufferWidth, bufferHeight);

    //loop until the window closed
    while (!glfwWindowShouldClose(mainWindow)) {
        //get + handle for user input events
        //any user input mouse ,keyboard, move the window etc
        glfwPollEvents();
        //clear window
        //(R,G,B,Tranparency)
        glClearColor(1.0f, 0.0f, 0.0f, 0.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(mainWindow);
    }
    return 0;
}
