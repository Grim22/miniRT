#include "mini.h"
#include "libft.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int encode_color(int R, int G, int B)
{
    int r;
    int g;
    int b;
    int color;

    r = (R & 255) << 16;
    g = (G & 255) << 8;
    b = (B & 255);
    color = r | g | b;
    //color = (0 & 0xff) << 24 | color;
    return (color);
}

void init_mlx(t_data *img, int xres, int yres)
// inits mlx, creates a window and an image
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, xres, yres, "Test");
    img->img = mlx_new_image(img->mlx, xres, yres);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

void fill_screen(t_data *img, int xres, int yres)
{
int i;
int j;
i = 0;
while(i < xres)
{
    j = 0;
    while(j < yres)
    {
        my_mlx_pixel_put(img, i, j, encode_color((int)(i / (float)xres * 255), (int)(j / (float)yres * 255), 0));
        j++;
    }
    i++;
}
}