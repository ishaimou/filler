//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

//Screen dimension macros
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


//The window we'll be rendering to
SDL_Window	*window = NULL;

//The surface contained by the window
//SDL_Surface	*scr_surface = NULL;

SDL_Renderer	*renderer = NULL;

//The image we will load and show on the screen
SDL_Surface	*bg_img = NULL;

SDL_Texture	*bg_tex = NULL;

SDL_AudioDeviceID	device_id;

Uint8				*wav_buffer = NULL;

int		init(void)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}

	//Initialze_SDL_image
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		printf("IMG_init: %s\n", IMG_GetError());
		return (0);
	}

	//create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("SDL_CreateRenderer: %s\n", SDL_GetError());
		return (0);
	}

	//Get window surface
	//scr_surface = SDL_GetWindowSurface(window);
	return (1);
}

void	close(void)
{
	SDL_CloseAudioDevice(device_id);
	SDL_FreeWAV(wav_buffer);
	wav_buffer = NULL;
	
	SDL_DestroyTexture(bg_tex);
	bg_tex = NULL;

	//Deallocate surface
	//SDL_FreeSurface(bg_img);
	//bg_img = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL_Image
	IMG_Quit();

	//Quit SDL subsystems
	SDL_Quit();
}

int		load_media(void)
{

	bg_img = IMG_Load("images/bg1.jpg");
	if (!bg_img)
	{
		printf("Unable to load image \"%s\" SDL_ERROR: %s\n", "bg1.jpg", IMG_GetError());
		return (0);
	}
	bg_tex = SDL_CreateTextureFromSurface(renderer, bg_img);
	SDL_FreeSurface(bg_img);
	bg_img = NULL;
	return (1);
}

int		load_audio(void)
{
	SDL_AudioSpec		wav_spec;
	Uint32				wav_length;
	int					success;
		
	if (!SDL_LoadWAV("audio/Fantasia.wav", &wav_spec, &wav_buffer, &wav_length))
	{
		printf("Could not open \"%s\" SDL_ERROR: %s\n", "Fantasia.wav", SDL_GetError()); 
		return (0);
	}
	device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	success = SDL_QueueAudio(device_id, wav_buffer, wav_length);
	return (1);
}

int		main(int argc, char *argv[])
{
	SDL_Event	event;

	if (!init())
		return (0);
	if (!load_media())
		return (0);
	if (!load_audio())
		return (0);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	//SDL_RenderPresent(renderer);
	//Apply the image
	//SDL_BlitSurface(bg_img, NULL, scr_surface, NULL);

	//Fill the surface white
	//SDL_FillRect(scr_surface, NULL, SDL_MapRGB(scr_surface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	//SDL_UpdateWindowSurface(window);

	//Wait two seconds
	//SDL_Delay(5000);
	
	SDL_PauseAudioDevice(device_id, 0);
	
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	
	close();
	return (0);
}
