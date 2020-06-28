#include "graphics.h"

double xPos = 0;
double yPos = 255;
double w = 100;
double h = 100;
double xVel = 0.8;
double yVel = 0.1;
void update(int windowW, int windowH) {
    fillRect(xPos, yPos, w, h, 0, 255, 0);
    if (xPos + w > windowW || xPos < 0) {
        xVel *= -1;
    }
    if (yPos + h > windowH || yPos < 0) {
        yVel *= -1;
    }
    xPos += xVel;
    yPos += yVel;
}

int main() {
    init();
    loop(update);
    quit();
}
