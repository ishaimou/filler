#include "visualizer.h"

int		init(t_visual *v)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		ft_printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		ft_printf("IMG_init: %s\n", IMG_GetError());
		return (0);
	}
	v->window = SDL_CreateWindow("Filler Visualizer", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (v->window == NULL)
	{
		ft_printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}
	v->renderer = SDL_CreateRenderer(v->window, -1, SDL_RENDERER_ACCELERATED);
	if (v->renderer == NULL)
	{
		ft_printf("SDL_CreateRenderer: %s\n", SDL_GetError());
		return (0);
	}
	return (1);
}

void	ft_sdlclose(t_visual *v)
{
	SDL_CloseAudioDevice(v->device_id);
	SDL_FreeWAV(v->wav_buffer);
	v->wav_buffer = NULL;
	SDL_DestroyTexture(v->bg_tex);
	v->bg_tex = NULL;
	SDL_DestroyRenderer(v->renderer);
	v->renderer = NULL;
	SDL_DestroyWindow(v->window);
	v->window = NULL;
	IMG_Quit();
	SDL_Quit();
}

int		load_media(t_visual *v)
{
	SDL_Surface	*bg_img;

	bg_img = NULL;
	bg_img = IMG_Load("images/bg1.jpg");
	if (!bg_img)
	{
		printf("Unable to load image \"%s\" SDL_ERROR: %s\n", "bg1.jpg", IMG_GetError());
		return (0);
	}
	v->bg_tex = SDL_CreateTextureFromSurface(v->renderer, bg_img);
	SDL_FreeSurface(bg_img);
	bg_img = NULL;
	return (1);
}

int		load_audio(t_visual *v)
{
	SDL_AudioSpec		wav_spec;
	Uint32				wav_length;
	int					success;
		
	if (!SDL_LoadWAV("audio/Fantasia.wav", &wav_spec, &(v->wav_buffer), &wav_length))
	{
		printf("Could not open \"%s\" SDL_ERROR: %s\n", "Fantasia.wav", SDL_GetError()); 
		return (0);
	}
	v->device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	success = SDL_QueueAudio(v->device_id, v->wav_buffer, wav_length);
	return (1);
}

int		main(int argc, char *argv[])
{
	SDL_Event	event;
	t_visual	v;

	if (!init(&v))
		return (0);
	if (!load_media(&v))
		return (0);
	if (!load_audio(&v))
		return (0);
	
	//Wait five seconds
	//SDL_Delay(5000);
	
	SDL_PauseAudioDevice(v.device_id, 0);
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		SDL_RenderClear(v.renderer);
		SDL_RenderCopy(v.renderer, v.bg_tex, NULL, NULL);
		SDL_RenderPresent(v.renderer);
	}
	ft_sdlclose(&v);
	return (0);
}
