#include <iostream>
#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

SDL_Renderer *renderer;
SDL_Surface *surface;
static void glewinit()
{
	if(glewInit() == false)
	{
	std::cout << "GLEW didnt start." << std::endl; 
	}
}

struct world
{
	static float x;
	static float y;

	// add other things
};

void movementFunc()
{
	// TODO
}



// function for rendering a rectangle.
void rectangle()
{
	SDL_Rect r;

	r.x = 50; 
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

	SDL_RenderFillRect(renderer, &r);
	SDL_RenderPresent(renderer);
}

/*
 * Make a renderer that makes a texture render and all of that. so I can render nice pretty images.
 * or other things that are pretty nice, like GLSL or OpenGL functions that are pretty nice.
 *
 */
// some mathematices that you can something really nice like pseudo 3d projection,
// So that would be pretty nice to know if I can do the mathematices.

const int height = 800;
const int width  = 600;

int main(int argc, char* argv[])
{
	SDL_Window *window; // pointer to the window
	SDL_Init(SDL_INIT_VIDEO); // init the window
	//window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
	

	// opengl testing
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	

	if(window == NULL)
	{
		std::cout << "Error, couldent make window: " << SDL_GetError() << std::endl;
		return 1;
	}
	// Events and handling
	
	SDL_Event event;
	while(true)
	{

//		sdlRenderer(); // the void renderer thing
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
			{
				SDL_Log("User has just pressed a key");
			}
			switch(event.type)
			{
				case SDL_QUIT:
					SDL_Quit();
					break;
			
			}
			// keyboard input like escape key
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					SDL_Quit();
					break;
			}
			// movement keys are up down left and right, so you can do something that is pretty nice.
			// or change colours on the screen so you can do anything.
			// or anything that you can do with event keys.
			switch(event.key.keysym.sym)
			{
				case SDLK_LEFT:
					// amke the lines or object moves.
					// or something more interesting
					break;
				case SDLK_RIGHT:
					// make the lines or objects moves to the right
					// or something more interesting.
					break;
				case SDLK_UP:
					// it says up there. thank you
					break;
				case SDLK_DOWN:
					// look up at SDLK_LEFT and SDLK_RIGHT;
					break;
			}	
		}

		SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);


		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255,255,255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 300, 200, 100, 400);

		SDL_SetRenderDrawColor(renderer, 20,240,152, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 10,20,500,0);
		SDL_RenderPresent(renderer);

		// rectangle render function;
		rectangle();


	}


	SDL_Delay(3000); // for 3 seconds for the window to open
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}

