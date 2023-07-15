#include "../Headers/Graphics.h"

void dsr_initVBO(VBO* VBO, GLfloat vertices[], GLuint size)
{
  glGenBuffers(1, &VBO->ID);
  glBindBuffer(GL_ARRAY_BUFFER, VBO->ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void dsr_bindVBO(VBO* VBO)
{
  glBindBuffer(GL_ARRAY_BUFFER, VBO->ID);
}

void dsr_unbindVBO()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void dsr_deleteVBO(VBO* VBO)
{
  glDeleteBuffers(1, &VBO->ID);
}

void dsr_initEBO(EBO* EBO, GLuint indices[], GLuint size)
{
  glGenBuffers(1, &EBO->ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO->ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void dsr_bindEBO(EBO* EBO)
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO->ID);
}

void dsr_unbindEBO()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void dsr_deleteEBO(EBO* EBO)
{
  glDeleteBuffers(1, &EBO->ID);
}

void dsr_initVAO(VAO* VAO)
{
  glGenVertexArrays(1, &VAO->ID);
}

void dsr_linkAttrib(VBO* VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset)
{
  dsr_bindVBO(VBO);
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);  
  dsr_unbindVBO();
}

void dsr_bindVAO(VAO* VAO)
{
  glBindVertexArray(VAO->ID);
}

void dsr_unbindVAO()
{
  glBindVertexArray(0);
}

void dsr_deleteVAO(VAO* VAO)
{
  glDeleteBuffers(1, &VAO->ID);
}

void dsr_initShader(Shader* Shader, const char* vertexSourcePath, const char* fragmentSourcePath)
{
  // Info Log
  int success;
  char infoLog[512];

  // Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  const char* vertexShaderSource = dsr_file_getContents(vertexSourcePath);
  const char* fragmentShaderSource = dsr_file_getContents(fragmentSourcePath);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Validating Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("Failed to compile the vertex shader!\n");
    printf("Error: %s\n", infoLog);
  }

  // Validating Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("Failed to compile the fragment shader!\n");
    printf("Error: %s\n", infoLog);
  }

  // Shader Program
  Shader->ID = glCreateProgram();
  glAttachShader(Shader->ID, vertexShader);
  glAttachShader(Shader->ID, fragmentShader);
  glLinkProgram(Shader->ID);

  // Validating Shader Program
  glGetProgramiv(Shader->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(Shader->ID, 512, NULL, infoLog);
    printf("Failed to link the shader program!\n");
    printf("Error: %s\n", infoLog);
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void dsr_useShader(Shader* Shader)
{
  glUseProgram(Shader->ID);
}

void dsr_deleteShader(Shader* Shader)
{
  glDeleteProgram(Shader->ID);
}
