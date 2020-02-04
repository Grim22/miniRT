#include "mini.h"

int ft_close(void *param)
{
	printf("Bye !\n");
	(void)param;
	exit(0);
}

int print_plane_on_a(int key, t_data *img)
{
    static int count;
    
    printf("keycode: %d\n", key);
    if (key == 0)
    {
        print_plane(*img, 120 + 10*count, 200, 200, 50, 0xFF0000);
        count++;
    }
    if (key == 53)
        exit(0);
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    return(0);
}

int print_square_on_click(int key, int x, int y, t_data *img)
{
    static int count;
    
    printf("keycode: %d, x: %d, y: %d\n", key, x, y);
    if (key == 1)
    {
        print_square(*img, 10*count, 20, 50, 0xFF00FF);
        mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
        count++;
    }
    return(0);
}

int try_loop_hook(t_data *img)
{   
    print_square(*img, 10, 20, 50, 0xFF00FF);
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    return(0);
}