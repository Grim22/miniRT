#include "mini.h"

void print_square(t_data img, int x, int y, int len, int col)
{
int i = 0;
printf("square\n");
while(i < len)
{
	my_mlx_pixel_put(&img, x, y + i, col);
	my_mlx_pixel_put(&img, x + i, y, col);
	my_mlx_pixel_put(&img, x + len, y + i, col);
	my_mlx_pixel_put(&img, x + i, y + len, col);
	i++;
}
}

void print_line (t_data img, int x0, int y0, int x1, int y1, int col)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;)
  {  /* loop */
    my_mlx_pixel_put(&img, x0, y0, col);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

/*
void print_circle(t_data img, int x, int y, int rad, int col)
{
//1st method (using x2 + y2 = r2)
double a;
double b;
a = 0;
while(a < 640)
{
	b = 0;	
	while(b < 480)
	{
		if ((a*a + b*b) > rad * rad)
		{
			i = a;
			j = b;
			my_mlx_pixel_put(&img, i + x, j + y, col);
		}
		b = b + 0.1;
	}
	a = a + 0.1;
}
*/

//2nd method (using cos/sin)
void	print_circle(t_data img, int x, int y, int r, int col)
{
	double	angle;
	int 	i;
	int 	j;
	
    angle = 0;
    while (angle < 360)
    {
        i = r * cos(angle * M_PI / 180);
        j = r * sin(angle * M_PI / 180);
        // mlx_pixel_put(data->mlx_ptr, data->mlx_win, x + 300, y + 300, 0.1*color.r*color.g*color.b);
        my_mlx_pixel_put(&img, x + i, y + j, col);
        angle += 0.1;
    }
}

void print_plane(t_data img, int x, int y, int lon, int lar, int col)
{
    int i = 0;

    while(i < lon)
    {
        my_mlx_pixel_put(&img, x, y + i, col);
        my_mlx_pixel_put(&img, x + lar, y + i, col);
        i++;
    }
    i = 0;
    while(i < lar)
    {
        my_mlx_pixel_put(&img, x + i, y, col);
        my_mlx_pixel_put(&img, x + i, y + lon, col);
        i++;
    }
}


void print_triangle(t_data img, int x1, int y1, int x2, int y2, int x3, int y3, int col)
{
    print_line(img, x1, y1, x2, y2, col);
    print_line(img, x2, y2, x3, y3, col);
    print_line(img, x1, y1, x3, y3, col);
    
}
