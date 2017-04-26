

#include "fdf.h"

int					ft_strlen_2darray(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

void				get_matrix_size(int *x_size, int *y_size, int fd)
{
	char	*line;
	int		get_next_status;

	get_next_status = get_next_line(fd, &line);
	*x_size = ft_strlen(line);
	*y_size = 1;
	while (get_next_status != 0)
	{
		*y_size = *y_size + 1;
		get_next_status = get_next_line(fd, &line);
	}
}

char				**get_matrix(int x_size, int y_size, int fd)
{
	char	**matrix;
	char	*line;
	int		g;
	int		k;
	int		i;

	k = 0;
	matrix = (char **)malloc(sizeof(char*) * (y_size + 1));
	i = 0;
	while (i < y_size)
	{
		matrix[i] = (char *)malloc(sizeof(char) * (x_size + 1));
		++i;
	}
	g = get_next_line(fd, &line);
	while (g != 0 && k < x_size)
	{
		matrix[k] = ft_strcpy(matrix[k], line);
		g = get_next_line(fd, &line);
		k++;
	}
	return (matrix);
}

void				transform_struct_iso(t_xyzstruct *points_array,
	int elem_num, int y_size, char **charmatrix)
{
	int				space;
	t_pointxystruct	p;
	t_xyzstruct		*current;
	int				i;

	i = 0;
	space = point_space(y_size, charmatrix);
	current = points_array;
	while (i < elem_num)
	{
		p.x = 500 + current[i].x_cord * space * sin(DEG30) +
			current[i].y_cord * space * cos(DEG30);
		p.y = 500 + current[i].x_cord * space * sin(DEG30) -
			(current[i].y_cord) * space * sin(DEG30) -
			current[i].z_cord * space;
		current[i].x_cord = p.x;
		current[i].y_cord = p.y;
		i++;
	}
}

t_pointxystruct		to_point(int x, int y)
{
	t_pointxystruct p;

	p.x = x;
	p.y = y;
	return (p);
}
