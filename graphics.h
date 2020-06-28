#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    SDL_PollEvent(&event);
    return 0;
}

void loop(void (*updateFunction)(int, int)) {
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        int width, height;
        SDL_GetWindowSize(window, &width, &height);
        (*updateFunction)(width, height);
        SDL_RenderPresent(renderer);
    }
}

void quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void fillPixel(int x, int y, int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 0x00);
    SDL_RenderDrawPoint(renderer, x, y);
}
