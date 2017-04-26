

#include "fdf.h"

void	ft_draw_line(t_pointxystruct p1, t_pointxystruct p2, t_win e)
{
	int	sx;
	int	sy;

	e.dx = abs(p2.x - p1.x);
	sx = p1.x < p2.x ? 1 : -1;
	e.dy = abs(p2.y - p1.y);
	sy = p1.y < p2.y ? 1 : -1;
	e.error = (e.dx > e.dy ? e.dx : -e.dy) / 2;
	while (1)
	{
		mlx_pixel_put(e.mlx, e.win, p1.x, p1.y, 0x99CCFF);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e.e2 = e.error;
		if (e.e2 > -e.dx)
		{
			e.error -= e.dy;
			p1.x += sx;
		}
		if (e.e2 < e.dy)
		{
			e.error += e.dx;
			p1.y += sy;
		}
	}
}

int		draw_matrix_column(t_win e, t_pointxystruct **matrix, int l, int c)
{
	int				i;
	int				j;
	t_pointxystruct	p1;
	t_pointxystruct	p2;
	t_pointxystruct	m;

	m.x = l;
	m.y = c;
	i = 0;
	while (i < m.x)
	{
		j = 0;
		while (j < m.y - 1)
		{
			p1 = to_point(matrix[i][j].x, matrix[i][j].y);
			p2 = to_point(matrix[i][j + 1].x, matrix[i][j + 1].y);
			ft_draw_line(p1, p2, e);
			j++;
		}
		i++;
	}
	return (1);
}

int		draw_matrix_line(t_win e, t_pointxystruct **matrix, int l, int c)
{
	int				i;
	int				j;
	t_pointxystruct	p1;
	t_pointxystruct	p2;
	t_pointxystruct	m;

	i = 0;
	m.x = l;
	m.y = c;
	while (i < m.x - 1)
	{
		j = 0;
		while (j < m.y)
		{
			p1 = to_point(matrix[i][j].x, matrix[i][j].y);
			p2 = to_point(matrix[i + 1][j].x, matrix[i + 1][j].y);
			ft_draw_line(p1, p2, e);
			j++;
		}
		i++;
	}
	return (1);
}
