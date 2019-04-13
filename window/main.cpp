#include <iostream>
#include <cstdio>
#include <SDL2/SDL.h>
SDL_Window *window;
SDL_Renderer *renderer;

const int height = 800;
const int width  = 600;

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL could not init: %s", SDL_GetError());
		return 1;
	}
	else 
	{
		printf("SDL has started! YAY!!! \n");
	}

	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			height, width, SDL_WINDOW_OPENGL);

	if(window == NULL)
	{
		std::cout << "Error, window couldn't be made: " << SDL_GetError() << std::endl;	
	}
	

	/*
	 *
	 */
	SDL_Delay(3000);	
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
