#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../tools/camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#ifndef utils
#define utils


#define SCR_WIDTH 960
#define SCR_HEIGHT 720

//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
unsigned int loadTexture(char const * path);


// camera
extern Camera camera;

extern bool firstMouse;
extern float lastX;
extern float lastY;

// timing
extern float deltaTime;	// time between current frame and last frame
extern float lastFrame;


extern glm::vec3 lightPos;


#endif // !utils

