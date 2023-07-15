#ifndef GRPAHICS_H
#define GRPAHICS_H

#include <GL/glew.h>

typedef struct VBO
{
  GLuint ID;
} VBO;

typedef struct EBO
{
  GLuint ID;
} EBO;

typedef struct VAO
{
  GLuint ID;
} VAO;

void dsr_initVBO(VBO* VBO, GLfloat vertices[], GLuint size);
void dsr_bindVBO(VBO* VBO);
void dsr_unbindVBO();
void dsr_deleteVBO(VBO* VBO);

void dsr_initEBO(EBO* EBO, GLuint indices[], GLuint size);
void dsr_bindEBO(EBO* EBO);
void dsr_unbindEBO();
void dsr_deleteEBO(EBO* EBO);

void dsr_initVAO(VAO* VAO);
void dsr_linkAttrib(VBO* VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset);
void dsr_bindVAO(VAO* VAO);
void dsr_unbindVAO();
void dsr_deleteVAO(VAO* VAO);

#endif // GRPAHICS_H
