

#include "fdf.h"

int		my_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
}

void	fdf(char **matrixchar, t_xyzstruct *points_array, t_win e)
{
	transform_struct_iso(points_array, ((e.y_size - 1) *
					(ft_strlen_2darray(ft_split(matrixchar[0])))),
				e.y_size, matrixchar);
	push_to_matrix(points_array, e.y_size - 1,
			ft_strlen_2darray(ft_split(matrixchar[0])),
			(e.y_size - 1) * (ft_strlen_2darray(ft_split(matrixchar[0]))));
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "fdf");
	draw_matrix_line(e, push_to_matrix(points_array, e.y_size - 1,
				ft_strlen_2darray(ft_split(matrixchar[0])),
				(e.y_size - 1) *
				(ft_strlen_2darray(ft_split(matrixchar[0])))),
			e.y_size - 1, ft_strlen_2darray(ft_split(matrixchar[0])));
	draw_matrix_column(e, push_to_matrix(points_array, e.y_size - 1,
				ft_strlen_2darray(ft_split(matrixchar[0])),
				(e.y_size - 1) *
				(ft_strlen_2darray(ft_split(matrixchar[0])))),
			e.y_size - 1, ft_strlen_2darray(ft_split(matrixchar[0])));
	mlx_key_hook(e.win, my_key_funct, e.mlx);
	mlx_loop(e.mlx);
}

int		main(int argc, char **argv)
{
	t_win		e;
	char		**matrixchar;
	int			**matrixint;
	t_xyzstruct	*points_array;

	if (argc != 2)
		ft_error("Usage: ./fdf <filename> [ case_size z_size]");
	else
	{
		e.filename = argv[1];
		e.fd = open(e.filename, O_RDONLY);
		get_matrix_size(&e.x_size, &e.y_size, e.fd);
		close(e.fd);
		e.fd = open(e.filename, O_RDONLY);
		matrixchar = get_matrix(e.x_size, e.y_size, e.fd);
		matrixint = charmatrix_to_intmatrix(matrixchar, e.y_size);
		points_array = intmatrix_to_struct(matrixint,
				ft_strlen_2darray(ft_split(matrixchar[0])), e.y_size - 1);
		fdf(matrixchar, points_array, e);
	}
}
