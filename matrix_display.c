

#include "fdf.h"

int		point_space(int y_size, char **charmatrix)
{
	int x_size;
	int space;
	int size;

	x_size = ft_strlen_2darray(ft_split(charmatrix[0]));
	space = 30;
	size = x_size * y_size;
	if (size <= 500)
		return (space);
	else
	{
		if (size > 500 && size <= 2500)
			space = 20;
		else
		{
			if (size > 2500 && size < 49492)
				space = 10;
			else
				space = 3;
		}
	}
	return (space);
}
