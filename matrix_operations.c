

#include "fdf.h"

int					**charmatrix_to_intmatrix(char **charmatrix, int y_size)
{
	t_count				n;
	int					**intmatrix;
	int					x_size;
	char				**test_array;

	y_size--;
	test_array = ft_split(charmatrix[0]);
	x_size = ft_strlen_2darray(test_array);
	intmatrix = (int **)malloc(y_size * sizeof(int *));
	n.i = -1;
	while (++n.i < y_size)
		intmatrix[n.i] = (int *)malloc(x_size * sizeof(int));
	n.i = 0;
	while (n.i < y_size)
	{
		n.j = 0;
		while (n.j < x_size)
		{
			intmatrix[n.i][n.j] = atoi(ft_split(charmatrix[n.i])[n.j]);
			n.j++;
		}
		n.i++;
	}
	return (intmatrix);
}

t_xyzstruct			*intmatrix_to_struct(int **matrix, int x_size, int y_size)
{
	t_xyzstruct	*punct;
	int			i;
	int			j;
	int			k;

	punct = (t_xyzstruct *)malloc(sizeof(t_xyzstruct) * y_size * x_size);
	i = 0;
	k = 0;
	while (i < y_size)
	{
		j = 0;
		while (j < x_size)
		{
			punct[k].x_cord = i;
			punct[k].y_cord = j;
			punct[k].z_cord = matrix[i][j];
			j++;
			k++;
		}
		i++;
	}
	return (punct);
}

t_pointxystruct		**push_to_matrix(t_xyzstruct *points_array,
		int l1, int c, int elem_num)
{
	t_pointxystruct		l;
	t_pointxystruct		**matrix;
	t_xyzstruct			*current;
	t_count				n;

	n.k = 0;
	current = points_array;
	l.x = l1;
	l.y = c;
	matrix = (t_pointxystruct **)malloc((sizeof(t_pointxystruct *) * l.x + 1));
	n.i = 0;
	while (n.k < elem_num || n.i < l.x)
	{
		matrix[n.i] = (t_pointxystruct *)malloc(sizeof(t_pointxystruct) * l.y);
		n.j = 0;
		while (n.j < l.y)
		{
			matrix[n.i][n.j].x = current[n.k].x_cord;
			matrix[n.i][n.j].y = current[n.k].y_cord;
			n.k++;
			n.j++;
		}
		n.i++;
	}
	return (matrix);
}
