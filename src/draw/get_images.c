#include "../../dep/so_long.h"

#define PLAYER "sprites/Player.xpm"
#define COLLECTIBLE "sprites/Collectible.xpm"
#define EXIT "sprites/Exit.xpm"
#define WALL "sprites/Wall.xpm"
#define BACKGROUND "sprites/BG.xpm"

int	get_images_from_textures(t_vars *vars)
{
	int	length;
	int	map_x;
	int	map_y;

	map_x = vars->map_size[X] * 64;
	map_y = vars->map_size[Y] * 64 + 18;
	vars->images[P]
			= mlx_xpm_file_to_image(vars->mlx, PLAYER, &length, &length);
	vars->images[E]
			= mlx_xpm_file_to_image(vars->mlx, EXIT, &length, &length);
	vars->images[C]
			= mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE, &length, &length);
	vars->images[W]
			= mlx_xpm_file_to_image(vars->mlx, WALL, &length, &length);
	vars->images[BG]
			= mlx_xpm_file_to_image(vars->mlx, BACKGROUND, &map_x, &map_y);
	vars->images[5] = NULL;
	return (0);
}
