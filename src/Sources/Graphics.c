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
