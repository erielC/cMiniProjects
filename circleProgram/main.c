#include <stdio.h>
#include <stdbool.h>
#include "glad/glad.h"
#include <GLFW/glfw3.h>



// However, the moment a user resizes the window the viewport should be adjusted as well. We can register a callback function on the window that gets called each time the window is resized. This resize callback function has the following prototype: 
void framebuffer_size_callback(GLFWwindow* window, int width, int height){

    // The framebuffer size function takes a GLFWwindow as its first argument and two integers indicating the new window dimensions. Whenever the window changes in size, GLFW calls this function and fills in the proper arguments for you to process. 
    glViewport(0, 0, width, height);
}

// Inputs

// We'll be using GLFW's glfwGetKey function that takes the window as input together with a key. The function returns whether this key is currently being pressed. We're creating a processInput function to keep all input code organized: 
void processInput(GLFWwindow *window){
    // Here we check whether the user has pressed the escape key (if it's not pressed, glfwGetKey returns GLFW_RELEASE). If the user did press the escape key, we close GLFW by setting its WindowShouldClose property to true using glfwSetwindowShouldClose. The next condition check of the main while loop will then fail and the application closes. 
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}


int main()
{
    glfwInit();

    //  OpenGL version 3.3 we'd like to tell GLFW that 3.3 is the OpenGL version we want to use. This way GLFW can make the proper arrangements when creating the OpenGL context. This ensures that when a user does not have the proper OpenGL version GLFW fails to run. We set the major and minor version both to 3 using OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We also tell GLFW we want to explicitly use the core-profile. Telling GLFW we want to use the core-profile means we'll get access to a smaller subset of OpenGL features without backwards-compatible features we no longer need

    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); for OS X use only!!

    GLFWwindow* window = glfwCreateWindow(800, 600, "Circle Program", NULL, NULL);

    // if statement if window does not load
    if(window == NULL){
        printf("Failed to create a GLFW Window!\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // still don't know what that is

    // pass GLAD the function to load the address of the OpenGL function pointers which is OS-specific. GLFW gives us glfwGetProcAddress that defines the correct function based on which OS we're compiling for. 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Failed to initalize GLAD\n");
        return -1;
    }

    // tell OpenGL the size of the rendering window so OpenGL knows how we want to display the data and coordinates with respect to the window. We can set those dimensions via the glViewport function: 
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    // We want the application to keep drawing images and handling user input until the program has been explicitly told to stop. For this reason we have to create a while loop, that we now call the render loop, that keeps on running until we tell GLFW to stop. The following code shows a very simple render loop: 

    // The glfwWindowShouldClose function checks at the start of each loop iteration if GLFW has been instructed to close. If so, the function returns true and the render loop stops running, after which we can close the application.
    while(!glfwWindowShouldClose(window)){
        // Input
        processInput(window);

        //Rendering Commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //  The glfwSwapBuffers will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window) that is used to render to during this render iteration and show it as output to the screen. 
        glfwPollEvents();

        // The glfwPollEvents function checks if any events are triggered (like keyboard input or mouse movement events), updates the window state, and calls the corresponding functions (which we can register via callback methods). 
        glfwSwapBuffers(window);

    }
 
    // Inputs


    

    glfwTerminate();
    return 0;
}