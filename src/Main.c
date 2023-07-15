#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "Headers/Graphics.h"
#include "Headers/File.h"

// Functions

void printEngineTitle();

// Callbacks

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

// Constants

const unsigned int WINDOW_WIDTH   = 800;
const unsigned int WINDOW_HEIGHT  = 600;
const char*        WINDOW_TITLE   = "GLFW";
const char*        ENGINE_NAME    = "Desistir Engine";
const char*        ENGINE_AUTHOR  = "Marek Hodan";
const char*        ENGINE_LICENSE = "GNU GPLv3";
const char*        ENGINE_VERSION = "0.1";

// Vertices and Indices

GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f, 1.f, 0.f, 0.f,
   0.0f,  -0.5f, 0.f, 0.f, 1.f, 0.f,
   0.5f,  -0.5f, 0.f, 0.f, 0.f, 1.f,
  -0.25f,  0.0f, 0.f, 1.f, 1.f, 0.f,
   0.25f,  0.0f, 0.f, 0.f, 1.f, 1.f,
   0.0f,   0.5f, 0.f, 1.f, 0.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

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

  // Shaders

  Shader defaultShader;
  dsr_initShader(&defaultShader, "src/Shaders/default.vert", "src/Shaders/default.frag");

  // VAO, VBO, and EBO

  VAO VAO1;
  VBO VBO1;
  EBO EBO1;

  dsr_initVAO(&VAO1);
  dsr_initVBO(&VBO1, vertices, sizeof(vertices));
  dsr_initEBO(&EBO1, indices, sizeof(indices));

  dsr_bindVAO(&VAO1);
  dsr_bindVBO(&VBO1);
  dsr_bindEBO(&EBO1);

  dsr_linkAttrib(&VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  dsr_linkAttrib(&VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  dsr_unbindVAO();
  dsr_unbindVBO();
  dsr_unbindEBO();

  // Callbacks

  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  // Main Loop

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    dsr_useShader(&defaultShader);
    dsr_bindVAO(&VAO1);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);

    glfwSwapBuffers(window);
  }

  // Terminating the Program

  dsr_deleteVAO(&VAO1);
  dsr_deleteVBO(&VBO1);
  dsr_deleteEBO(&EBO1);
  dsr_deleteShader(&defaultShader);
  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}

// Functions

void printEngineTitle()
{
  printf("%s %s\n", ENGINE_NAME, ENGINE_VERSION);
  printf("Created by %s\n", ENGINE_AUTHOR);
  printf("Licensed under %s\n\n", ENGINE_LICENSE);
}

// Callbacks

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
