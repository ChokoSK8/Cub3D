#include "mlx.h"
#include <string.h>
#include <stdio.h>

void		put_xpm_to_final(char *data_final, char *data, int size_line)
{
	int		x;
	int		y;
	int		pos;

	y = 0;
	while (y < 350)
	{
		x = 0;
		while (x < 500)
		{
			pos = x * 4 + size_line * y;
			data_final[pos] = data[pos];
			data_final[pos + 1] = data[pos + 1];
			data_final[pos + 2] = data[pos + 2];
			data_final[pos + 3] = data[pos + 3];
			x++;
		}
		y++;
	}
}

int		main()
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "sample.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	int	bpp;
	int	size_line;
	int	endian;
	char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	void	*img_final;

	img_final = mlx_new_image(mlx, 500, 350);
	int	b;
	int s;
	int	e;
	char *data_final = mlx_get_data_addr(img_final, &b, &s, &e);

	put_xpm_to_final(data_final, data, s);

	win = mlx_new_window(mlx, 1000, 700, "Sprite");

	mlx_put_image_to_window(mlx, win, img_final, 0, 0);

	mlx_loop(mlx);
}
