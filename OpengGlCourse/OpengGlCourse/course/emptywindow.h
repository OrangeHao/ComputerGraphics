#include "../tools/utils.h"

#include <iostream>
using namespace std;

class Window
{
public:
	Window();
	~Window();
	int show();

private:
};

Window::Window()
{

}

Window::~Window()
{
}

int Window::show()
{
	//����glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//����һ�����ڶ���������ڶ����������кʹ�����ص����ݣ����һᱻGLFW����������Ƶ�����õ���
	GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	//�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window);

	//GLAD����������OpenGL�ĺ���ָ��ģ������ڵ����κ�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//���ô��ڵ�ά��(Dimension)
	glViewport(0, 0, 800, 600);

	//ע���������������GLFW����ϣ��ÿ�����ڵ�����С��ʱ������������
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//�򵥵���Ⱦѭ��
	while (!glfwWindowShouldClose(window)) {
		// ����
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//˫����Ӧ���У�ǰ�󻺳�Ľ���
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}