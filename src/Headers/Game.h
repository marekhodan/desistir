#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Prints the engine information.
 * This function prints the name, version, author, and license information of the engine.
 */
void dsr_printEngineInfo();

/**
 * Initializes GLFW library.
 *
 * @return True if GLFW initialization is successful, false otherwise.
 */
bool dsr_initializeGlfw();
/**
 * Initializes a GLFW window with the specified width, height, and title.
 *
 * @param window  A pointer to the GLFWwindow* to be initialized.
 * @param width   The width of the window.
 * @param height  The height of the window.
 * @param title   The title of the window.
 * @return True if the window creation is successful, false otherwise.
 */
bool dsr_initializeWindow(GLFWwindow** window, const unsigned int width, const unsigned int height, const char* title);
/**
 * Initializes GLEW library and checks for errors.
 *
 * @return True if GLEW initialization is successful, false otherwise.
 */
bool dsr_initializeGlew();

#endif // GAME_H
