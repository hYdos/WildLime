#ifndef WILDLIME_LIME_H
#define WILDLIME_LIME_H
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Lime {
public:
    Lime(uint32_t, uint32_t, char *displayname, char *name);

    bool shouldStayOpen();

    void mainLoop();

    void destroy();

private:
    //Validation layers
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif


    VkInstance instance;
    VkApplicationInfo applicationInfo{};

    GLFWwindow *window;
    unsigned int WIDTH;
    unsigned int HEIGHT;


    void initVulkan() {

    }

    VkInstance createInstance(VkApplicationInfo info);
};


#endif //WILDLIME_LIME_H
