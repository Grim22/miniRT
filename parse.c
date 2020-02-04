#include "mini.h"
#include "libft.h"
// gerer les cas ou le fichier en input est incorrect
// gerer les conversions depuis/vers float
// free (notamment apres les split)
// ft_scan: attention a preciser la 2em lettre si deux id peuvent avoir la meme


int ft_scan(char *line)
{
    if(line[0] == 'R')
        return(1);
    if(line[0] == 'A')
        return(2);
    if(line[0] == 'c' && line[1] == ' ')
        return(3);
    if(line[0] == 'l')
        return(4);
    if(ft_len(line) > 1 && line[0] == 's' && line[1] == 'p')
        return(5); 
    return(0);
}

int fill_R(char *line, t_reso *reso, char **words)
{
    reso->x = ft_atoi(words[1]);
    reso->y = ft_atoi(words[2]);
    return(0);
}

int fill_c(char *line, t_cam *cam, char **words)
{
    char **co;

    co = ft_split(words[1], ',');
    cam->pos.x = ft_atoi(co[0]);
    cam->pos.y = ft_atoi(co[1]);
    cam->pos.z = ft_atoi(co[2]);
    co = ft_split(words[2], ',');
    cam->orientation.x = ft_atoi(co[0]);
    cam->orientation.y = ft_atoi(co[1]);
    cam->orientation.z = ft_atoi(co[2]);
    cam->FOV = ft_atoi(words[3]);
    return(0);
}

int fill_l(char *line, t_light *light, char **words)
{
    char **co;
    char **num;
    char **col;
    
    num = ft_split(words[2], '.');
    light->ratio = ft_atoi(num[1]) * 0.1;
    // faire fonction str to float...
    col = ft_split(words[3], ',');
    light->col = encode_color(ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2]));
    co = ft_split(words[1], ',');
    light->pos.x = ft_atoi(co[0]);
    light->pos.y = ft_atoi(co[1]);
    light->pos.z = ft_atoi(co[2]);
    return(0);
}

int fill_sp(char *line, t_sphere *sp, char **words)
{
    char **co;
    char **col;
    
    co = ft_split(words[1], ',');
    sp->pos.x = ft_atoi(co[0]);
    sp->pos.y = ft_atoi(co[1]);
    sp->pos.z = ft_atoi(co[2]);
    sp->diam = ft_atoi(words[2]);
    col = ft_split(words[3], ',');
    sp->col = encode_color(ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2]));
    printf("diam: %d\n", sp->diam);
    return(0);
}

int fill_A(char *line, t_lum_amb *amb, char **words)
{
    char **col;
    char **num;

    num = ft_split(words[1], '.');
    amb->ratio = ft_atoi(num[1]) * 0.1;
    // faire fonction str to float...
    col = ft_split(words[2], ',');
    amb->col = encode_color(ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2]));
    return(0);
}

int ft_fill(int indice, char *line, t_reso *reso, t_lum_amb *amb, t_cam *cam, t_light *light, t_sphere *sp)
{
    char **words;
    
    if (indice == 0)
        return(0);
    words = ft_split(line, ' ');
    if (indice == 1)
        fill_R(line, reso, words);
    if (indice == 2)
        fill_A(line, amb, words);
    if (indice == 3)
        fill_c(line, cam, words);
    if (indice == 4)
        fill_l(line, light, words);
    if (indice == 5)
        fill_sp(line, sp, words);
    return(0);
}

int ft_init_parse(t_reso *reso, t_lum_amb *amb, t_light *light, t_sphere *sp, t_cam *cam)
{
    char *line;
    int ret;
    int i;
    int fd;

    fd = open("ex.rt", O_RDONLY);

    while((ret = get_next_line(fd, &line)))
    {
        if (ret == -1)
            return(-1);
        i = ft_scan(line);
        ft_fill(i, line, reso, amb, cam, light, sp);
    }
    if (ret == -1)
            return(-1);
    i = ft_scan(line);
    ft_fill(i, line, reso, amb, cam, light, sp);
    return (0);
}