#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
const unsigned int WINDOW_WIDTH   = 800;
const unsigned int WINDOW_HEIGHT  = 600;
const char*        WINDOW_TITLE   = "GLFW";
const char*        ENGINE_NAME    = "Desistir Engine";
const char*        ENGINE_AUTHOR  = "Marek Hodan";
const char*        ENGINE_LICENSE = "GNU GPLv3";
const char*        ENGINE_VERSION = "0.1";

void printEngineTitle();

int main()
{
  // Initialzing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  printEngineTitle();

  // Creating the Window
  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (window == NULL)
  {
    printf("Failed to create a GLFW Window!\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  printf("OpenGL: %s\n", glGetString(GL_VERSION));
  printf("GLFW:   %s\n", glfwGetVersionString());

  // Initializing GLEW
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    printf("Failed to initialize GLEW!\n");
    printf("Error: %s\n", glewGetErrorString(err));
    glfwTerminate();
    return -1;
  }
  printf("GLEW:   %s\n", glewGetString(GLEW_VERSION));

  // Clear Color
  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  // Main Loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }

  // Terminating the Program
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}

void printEngineTitle()
{
  printf("%s %s\n", ENGINE_NAME, ENGINE_VERSION);
  printf("Created by %s\n", ENGINE_AUTHOR);
  printf("Licensed under %s\n\n", ENGINE_LICENSE);
}
