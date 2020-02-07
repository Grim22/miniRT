#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

//minilibx
typedef struct  s_data {
    void        *img;
    void        *win;
    void        *mlx;
    char        *addr;
    int         bpp;
    int         line_length;
    int         endian;
}               t_data;

//parsing
typedef struct  s_cord {
    float       x;
    float       y;
    float       z;
}               t_cord;

typedef struct  s_reso {
    int         x;
    int         y;
}               t_reso;

typedef struct  s_lum_amb {
    float       ratio;
    int         col;
}               t_lum_amb;

typedef struct  s_cam {
    t_cord     pos;
    t_cord     orientation;
    int         FOV;
}               t_cam;

typedef struct  s_shere {
    t_cord     pos;
    int         diam;
    int         col;
}               t_sphere;

typedef struct  s_light {
    t_cord     pos;
    float       ratio;
    int         col;
}               t_light;

//minilibX
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int encode_color(int R, int G, int B);
void init_mlx(t_data *img, int xres, int yres);
void fill_screen(t_data *img, int xres, int yres);
// shapes
void print_square(t_data img, int x, int y, int len, int col);
void print_circle(t_data img, int x, int y, int r, int col);
void print_plane(t_data img, int x, int y, int lon, int lar, int col);
void print_line(t_data img, int x1, int x2, int y1, int y2, int col);
void print_triangle(t_data img, int x1, int y1, int x2, int y2, int x3, int y3, int col);
// events
int print_plane_on_a(int key, t_data *img);
int print_square_on_click(int key, int x, int y, t_data *img);
int ft_close(void *param); 
int try_loop_hook(t_data *img);
// vectors
float vect_prod(t_cord a, t_cord b);
t_cord vect_scalar_prod(t_cord a, float x);
t_cord vect_add(t_cord a, t_cord b);
void print_vect(t_cord a);
t_cord vect_normalize(t_cord a);
// parsing
int ft_init_parse(t_reso *reso, t_lum_amb *amb, t_light *light, t_sphere *sp, t_cam *cam);