#include "visualizer.h"

int		main(void)
{
	t_visual	v;

	if (!init_visual(&v))
		return (0);
	if (!rec_game(&v))
		return (0);
	//print_list(v.lst);
	printf("\nlist size = %d\n", ft_list_size(v.lst));
	printf("p1 = %s\n", v.p1_name);
	printf("p2 = %s\n", v.p2_name);
	printf("map_h = %d\n", v.map_h);
	printf("map_w = %d\n", v.map_w);
	printf("res_p1 = %d; res_p2 = %d\n", v.res_p1, v.res_p2);
	free_list(&(v.lst));
	free_visual(&v);
	//ft_sdlclose(&v);
	return (0);
}
