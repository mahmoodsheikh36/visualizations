#include "graphics.h"

void update(int windowWidth, int windowHeight) {
    for (int i = 0; i < windowWidth; ++i) {
        for (int j = 0; j < windowHeight; ++j) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            fillPixel(i, j, r, g, b);
        }
    }
}

int main() {
    printf("initializing...\n");
    init();
    printf("entering loop...\n");
    loop(update);
    quit();
}
