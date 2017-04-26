

#ifndef FDF_H
# define FDF_H

# include "math.h"
# include "stdlib.h"
# include "sys/stat.h"
# include "fcntl.h"
# include "libft.h"
# include "mlx.h"

# define DEG30 0.524

typedef struct		s_structure
{
	int		x_cord;
	int		y_cord;
	int		z_cord;
	char	*color;
}					t_xyzstruct;

typedef struct		s_points
{
	int x;
	int y;
}					t_pointxystruct;

typedef struct		s_counter
{
	int	i;
	int	j;
	int	k;
}					t_count;

typedef struct		s_windows
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		dx;
	int		x_size;
	int		y_size;
	int		fd;
	int		dy;
	int		error;
	int		e2;
	char	*filename;
}					t_win;

void				fdf(char **matrixchar, t_xyzstruct *points_array, t_win e);
int					draw_matrix_line(t_win e, t_pointxystruct **matrix,
		int l, int c);
int					draw_matrix_column(t_win e, t_pointxystruct **matrix,
		int l, int c);
t_pointxystruct		to_point(int x, int y);
void				ft_put_struct_matrix(t_pointxystruct **structmatrix,
		char	**charmatrix, int x_size, int y_size);
int					point_space(int y_size, char **charmatrix);
t_pointxystruct		**push_to_matrix(t_xyzstruct *points_array,
		int l1, int c, int elem_num);
void				transform_struct_iso(t_xyzstruct *points_array,
		int elem_num, int y_size, char **charmatrix);
t_xyzstruct			*intmatrix_to_struct(int	**matrix,
		int x_size, int y_size);
int					ft_strlen_2darray(char	**array);
int					**charmatrix_to_intmatrix(char **charmatrix, int y_size);
void				ft_putintmatrix(int	**intmatrix, char	**charmatrix,
		int x_size, int y_size);
int					count_words(char *str);
char				*malloc_word(char *str);
char				**ft_split(char *str);
void				get_x_size(void);
int					get_next_line(int fd, char **line);
void				get_matrix_size(int *x_size, int *y_size, int fd);
void				ft_putmatrix(char **square);
char				**get_matrix(int x_size, int y_size, int fd);
void				ft_draw_line(t_pointxystruct p1,
		t_pointxystruct p2, t_win e);
int					matrix_valid(char **matrix, int y_size, int x_size);

#endif
