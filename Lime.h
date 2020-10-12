#ifndef WILDLIME_LIME_H
#define WILDLIME_LIME_H
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "vector"

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
    VkDebugUtilsMessengerEXT debugMessenger;

    //VK vars
    VkInstance instance;
    VkApplicationInfo applicationInfo{};

    GLFWwindow *window;
    unsigned int WIDTH;
    unsigned int HEIGHT;

    void createInstance(VkApplicationInfo info);

    std::vector<const char *> getRequiredExtensions();

    bool checkSystemSupportsValidation();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT severity,
            VkDebugUtilsMessageTypeFlagsEXT msgType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);

    void setupDebugMessenger();

    VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                          const VkAllocationCallbacks *pAllocator,
                                          VkDebugUtilsMessengerEXT *pDebugMessenger);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
                                       const VkAllocationCallbacks *pAllocator);
};


#endif //WILDLIME_LIME_H
