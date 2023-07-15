#include "../Headers/Graphics.h"

void dsr_initVBO(VBO* VBO, GLfloat* vertices[], GLuint size)
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
