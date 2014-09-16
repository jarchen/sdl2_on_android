#include <android/log.h>

#include "SDL.h"

#define  LOG_TAG    "SDL2"
#define  LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

int main (int argc, char** argv) {
	int win_width = 0, win_height = 0;
	int quit = 0;
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *bmp = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return -1;

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(0, 0, &mode);
	win_width = mode.w;
	win_height = mode.h;
	LOGI("[main] - Display Size is %dx%d", win_width, win_height);

	win = SDL_CreateWindow(NULL, 0, 0, win_width, win_height, SDL_WINDOW_OPENGL);
	if (win == NULL) {
		LOGE("[main] SDL Window Created failed : %s", SDL_GetError());
		return -1;
	}

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		LOGE("[main] SDL Renderer Created failed : %s", SDL_GetError());
		return -1;
	}

	while (!quit) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_QUIT:
					quit = 1;
					break;
				case SDL_KEYDOWN:
					// android back button
					if (e.key.keysym.sym == SDLK_AC_BACK) quit = 1;
					break;
				case SDL_FINGERMOTION:
				{
					int r = 0, g = 0, b = 0;
					r = (int) (e.tfinger.x * 255);
					g = (int) (e.tfinger.y * 255);
					b = (int) ((r+g) / 2);
					SDL_RenderClear(renderer);
					SDL_SetRenderDrawColor(renderer, r, g, b, 255);
					SDL_RenderPresent(renderer);
					break;
				}
				default:
					break;
			}
		} // SDL_PollEvent
	} // quit

	return 0;
}