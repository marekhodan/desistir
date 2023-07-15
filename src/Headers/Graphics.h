#ifndef GRPAHICS_H
#define GRPAHICS_H

#include <GL/glew.h>

#include "File.h"

/**
 * Represents a Vertex Buffer Object.
*/
typedef struct VBO
{
  GLuint ID;
} VBO;

/**
 * Represents an Element Buffer Object
*/
typedef struct EBO
{
  GLuint ID;
} EBO;

/**
 * Represents a Vertex Array Object
*/
typedef struct VAO
{
  GLuint ID;
} VAO;

/**
 * Initializes a Vertex Buffer Object (VBO) with the provided vertices and size.
 * 
 * @param VBO       The VBO object to be initialized.
 * @param vertices  The array of vertex data.
 * @param size      The size of the vertex data in bytes.
 */
void dsr_initVBO(VBO* VBO, GLfloat vertices[], GLuint size);
/**
 * Binds the specified VBO object for rendering.
 *
 * @param VBO The VBO object to be bound.
 */
void dsr_bindVBO(VBO* VBO);
/**
 * Unbinds the currently bound VBO.
 */
void dsr_unbindVBO();
/**
 * Deletes the specified VBO object and releases associated resources.
 *
 * @param VBO The VBO object to be deleted.
 */
void dsr_deleteVBO(VBO* VBO);

/**
 * Initializes an Element Buffer Object (EBO) with the provided indices and size.
 *
 * @param EBO      The EBO object to be initialized.
 * @param indices  The array of indices.
 * @param size     The size of the index data in bytes.
 */
void dsr_initEBO(EBO* EBO, GLuint indices[], GLuint size);
/**
 * Binds the specified EBO object for rendering.
 *
 * @param EBO The EBO object to be bound.
 */
void dsr_bindEBO(EBO* EBO);
/**
 * Unbinds the currently bound EBO.
 */
void dsr_unbindEBO();
/**
 * Deletes the specified EBO object and releases associated resources.
 *
 * @param EBO The EBO object to be deleted.
 */
void dsr_deleteEBO(EBO* EBO);

/**
 * Initializes a Vertex Array Object (VAO) with the provided VAO object.
 * 
 * @param VAO The VAO object to be initialized.
 */
void dsr_initVAO(VAO* VAO);
/**
 * Links vertex attribute data to the specified VBO (Vertex Buffer Object) within a VAO.
 * 
 * @param VBO     The VBO object containing the vertex attribute data.
 * @param layout  The attribute layout index.
 * @param size    The number of components per attribute (e.g., 2 for 2D, 3 for 3D).
 * @param type    The data type of each component.
 * @param stride  The stride between consecutive attributes.
 * @param offset  The offset of the attribute data within the VBO.
 */
void dsr_linkAttrib(VBO* VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset);
/**
 * Binds the specified VAO object for rendering.
 * 
 * @param VAO The VAO object to be bound.
 */
void dsr_bindVAO(VAO* VAO);
/**
 * Unbinds the currently bound VAO.
 */
void dsr_unbindVAO();
/**
 * Deletes the specified VAO object and releases associated resources.
 * 
 * @param VAO The VAO object to be deleted.
 */
void dsr_deleteVAO(VAO* VAO);

typedef struct Shader
{
  GLuint ID;
} Shader;

/**
 * Initializes a Shader object with the provided vertex and fragment shader source code paths.
 *
 * @param shader             The Shader object to be initialized.
 * @param vertexSourcePath   The file path to the vertex shader source code.
 * @param fragmentSourcePath The file path to the fragment shader source code.
 */
void dsr_initShader(Shader* Shader, const char* vertexSourcePath, const char* fragmentSourcePath);
/**
 * Sets the specified Shader object as the current active shader program.
 *
 * @param shader The Shader object to be used.
 */
void dsr_useShader(Shader* Shader);
/**
 * Deletes the specified Shader object and releases associated resources.
 *
 * @param shader The Shader object to be deleted.
 */
void dsr_deleteShader(Shader* Shader);

#endif // GRPAHICS_H
