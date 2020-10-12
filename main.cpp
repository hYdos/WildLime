#include "Lime.h"

int main() {
    Lime limeRenderer = Lime(1200, 800, "Lime Example", "lime_example");

    try {
        while (limeRenderer.shouldStayOpen()){
            limeRenderer.mainLoop();
        }
        limeRenderer.destroy();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}