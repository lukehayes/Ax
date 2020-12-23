#ifndef CG_WINDOW_H
#define CG_WINDOW_H

namespace CG 
{

    class Window
    {
        public:
            Window(){}
            ~Window(){}

            void Create()
            {
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

                this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);

                glfwMakeContextCurrent(this->window);

                /* Glew MUST be initialized after context creation*/
                GLenum err = glewInit();

                if( GLEW_OK != err )
                {
                    fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
                }
            }

            s32 width = 800;
            s32 height = 600;
            const_str title = "Game Title";
            GLFWwindow* window;
            GLFWmonitor* monitor;
    };
}


#endif
