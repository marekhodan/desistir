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
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);  
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
