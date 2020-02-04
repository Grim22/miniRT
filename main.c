#include "mini.h"
#include "libft.h"

int intersect_sphere(t_cam cam, t_cord dir, t_sphere sp, float *dist)
{
    
    t_cord L;
    float tca;
    float d2;
    float r;
    float thc;
    float t1;

    r = (float)sp.diam / 2;
    L = vect_add(sp.pos, vect_scalar_prod(cam.pos, -1));
    tca = vect_prod(L, dir);
    d2 = vect_prod(L, L) - tca*tca;
    if (d2 > r * r)
        return(0);
    thc = sqrt(r*r - d2);
    *dist = tca + thc;
    if(*dist < 0)
        *dist = t1;
    if (*dist < 0)
        return(0);
    return(1);
}

void get_pix_vect(t_cord *vect, int i, int j, t_cam cam, t_reso res)
{
    float size;
    float angle;
    float screen_ratio;

    angle = (float)cam.FOV * M_PI / 180;
    size = 2 * tan(angle / 2);
    screen_ratio = res.x / res.y;
    vect->x = (0.5 + i) * size / (float)res.x - size / 2;
    vect->x = vect->x * screen_ratio;
    vect->y = (0.5 + j) * size / (float)res.y - size / 2;
    vect->z = -1;
    *vect = vect_normalize(*vect);
}

void get_light_angle(t_cam cam, t_cord dir, t_sphere sp, float d, t_cord *inter, t_cord *N)
{
    *inter = cam.pos + vect_scalar_prod(dir, d);
    // inter: point dintersection du rayon avec la sphere
    *N = vect_add(*inter, vect_scalar_prod(sp.pos, -1));
    // N 
    *N = vect_normalize(*N);
    angle = vect_prod(*N, *inter);
}

void fill_if_sphere(t_data *img, t_reso res, t_cam cam, t_sphere sp)
{
int i;
int j;
t_cord dir;
float d;
float angle;
t_cord inter;
t_cord N;

i = 0;
while(i < res.x)
{
    j = 0;
    while(j < res.y)
    {
        get_pix_vect(&dir, i, j, cam, res);
        if (intersect_sphere(cam, dir, sp, &d))
        {
            angle = get_light_angle(cam, dir, sp, d, &inter, &N);
            my_mlx_pixel_put(img, i, j, 0xFFFF00);
        }
        else
            my_mlx_pixel_put(img, i, j, 0xFFFFFF);
        j++;
    }
    i++;
}
}

int main()
{
t_data img;
int col;
t_reso reso;
t_lum_amb amb;
t_light light;
t_sphere sp;
t_cam cam;

ft_init_parse(&reso, &amb, &light, &sp, &cam);
init_mlx(&img, reso.x, reso.y);
fill_if_sphere(&img, reso, cam, sp);
/*
fill_screen(&img, reso.x, reso.y);

print_circle(img, 200, 200, 100, 0x00FF00);
print_square(img, 300, 300, 10, 0x00FF00);
print_plane(img, 420, 100, 200, 50, 0xFF0000);
print_line(img, 0, 0, 100, 200, 0xFF00FF);
print_triangle(img, 100, 100, 200, 200, 150, 400, 0x00FF00);

//mlx_key_hook(img.win, &print_plane_on_a, &img);
//mlx_mouse_hook(img.win, &print_square_on_click, &img);
//mlx_hook(img.win, 17, 1L << 17, &ft_close, 0);
//mlx_loop_hook(img.mlx, &try_loop_hook, &img);

*/

mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

mlx_loop(img.mlx);

//mlx_clear_window(mlx_p, win_p);
//mlx_destroy_window(mlx_p, win_p);
}