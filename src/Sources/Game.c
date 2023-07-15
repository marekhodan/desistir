#include "../Headers/Game.h"

extern const unsigned int WINDOW_WIDTH;
extern const unsigned int WINDOW_HEIGHT;
extern const char*        ENGINE_NAME;
extern const char*        ENGINE_VERSION;
extern const char*        ENGINE_AUTHOR;
extern const char*        ENGINE_LICENSE;

void dsr_printEngineInfo()
{
  printf("%s %s\n", ENGINE_NAME, ENGINE_VERSION);
  printf("Created by %s\n", ENGINE_AUTHOR);
  printf("Licensed under %s\n\n", ENGINE_LICENSE);
}

bool dsr_initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
}

bool dsr_initializeWindow(GLFWwindow** window, const unsigned int width, const unsigned int height, const char* title)
{
  *window = glfwCreateWindow(
    width,
    height,
    title,
    NULL,
    NULL
  );
  if (*window == NULL)
  {
    printf("Failed to create a GLFW window!\n");
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(*window);
  printf("OpenGL: %s\n", glGetString(GL_VERSION));
  printf("GLFW:   %s\n", glfwGetVersionString());

  // Clear Color

  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  return true;
}

bool dsr_initializeGlew()
{
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    printf("Failed to initialize GLEW!\n");
    printf("Error: %s\n", glewGetErrorString(err));
    glfwTerminate();
    return false;
  }
  printf("GLEW:   %s\n", glewGetString(GLEW_VERSION));
  return true;
}
