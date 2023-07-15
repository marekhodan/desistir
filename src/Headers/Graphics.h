#ifndef GRPAHICS_H
#define GRPAHICS_H

#include <GL/glew.h>

typedef struct VBO
{
  GLuint ID;
} VBO;

void dsr_initVBO(VBO* VBO, GLfloat* vertices[], GLuint size);
void dsr_bindVBO(VBO* VBO);
void dsr_unbindVBO();
void dsr_deleteVBO(VBO* VBO);

#endif // GRPAHICS_H
