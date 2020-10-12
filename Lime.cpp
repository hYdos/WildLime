#include "Lime.h"

Lime::Lime(uint32_t width, uint32_t height, char *title, char *name) {
    HEIGHT = height;
    WIDTH = width;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, title, nullptr, nullptr);

    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pApplicationName = name;
    applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
    applicationInfo.pEngineName = "Wild Lime";
    applicationInfo.engineVersion = VK_MAKE_VERSION(0, 1, 0);
    applicationInfo.apiVersion = VK_API_VERSION_1_0;

    instance = createInstance(applicationInfo);
}

void Lime::mainLoop() {
    glfwPollEvents();
}

bool Lime::shouldStayOpen() {
    return !glfwWindowShouldClose(window);
}

void Lime::destroy() {
    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);
    glfwTerminate();
}

VkInstance Lime::createInstance(VkApplicationInfo info) {
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &info;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}
