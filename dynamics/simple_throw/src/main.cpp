#include "Object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <vector>

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen_surface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Rect rectangle;

	rectangle.h = 50;
	rectangle.w = 50;
	rectangle.x = SCREEN_WIDTH/2;
	rectangle.y = SCREEN_HEIGHT/2;


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Window could not be created. SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created. SDL_Error: " << SDL_GetError() << std::endl;
			}
			/* screen_surface = SDL_GetWindowSurface(window); */
			/* SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface -> format, 0xFF, 0xFF, 0xFF)); */
			/* SDL_UpdateWindowSurface(window); */

			/* SDL_RenderClear(renderer); */

		}
	}


	std::vector<float> initial_position {0, 8.0};
	std::vector<float> initial_velocity {3.0, 10.0};

	if (argc > 1)
	{
		initial_velocity[0] = atoi(argv[1]);
		initial_velocity[1] = atoi(argv[2]);
	}

	Object object(5, initial_position, initial_velocity);

	do	
	{

		object.Update(0.001);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		rectangle.x = object.GetPosition()[0] * SCREEN_WIDTH/80;
		rectangle.y = SCREEN_HEIGHT - object.GetPosition()[1] * SCREEN_HEIGHT/80 - rectangle.h;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &rectangle);

		SDL_RenderPresent(renderer);
		/* SDL_Delay(1); */

		std::cout << object.GetVelocity()[0] << " " << object.GetVelocity()[1] << std::endl;

	} while ( object.GetPosition()[1] > 0 );

	SDL_Delay(2000);

	std::cout << object.GetPosition()[0] << std::endl;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
